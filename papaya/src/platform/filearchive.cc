// filearchive.cc

#include "platform/filearchive.hpp"
#include "platform/filestream.hpp"

#include <stb_image.h>

namespace papaya {
   using uint32 = unsigned int;
   using uint16 = unsigned short;

   static constexpr uint32 kZipCentralDirSignature = 0x02014B50u; // PK--
   static constexpr uint32 kZipLocalSignature      = 0x04034B50u;
   static constexpr uint32 kZipEocdSignature       = 0x06054B50u;

#pragma pack(push, 1)
   // note: local file header
   struct ZipLocalHeader {
      uint32 signature_;
      uint16 version_;
      uint16 bit_flags_;
      uint16 method_;
      uint16 last_mod_time_;
      uint16 last_mod_date_;
      uint32 crc32_;
      uint32 size_compressed_;
      uint32 size_uncompressed_;
      uint16 filename_length_;
      uint16 extra_field_length_;
   };

   // note: central directory file header
   struct ZipCDirHeader {
      uint32 signature_;
      uint16 version_;
      uint16 minimum_version_;
      uint16 bit_flags_;
      uint16 method_;
      uint16 last_mod_time_;
      uint16 last_mod_date_;
      uint32 crc32_;
      uint32 size_compressed_;
      uint32 size_uncompressed_;
      uint16 filename_length_;
      uint16 extra_field_length_;
      uint16 comment_length_;
      uint16 disk_num_file_start_;
      uint16 internal_file_attribs_;
      uint32 external_file_attribs_;
      uint32 local_header_offset_;
   };

   // note: end of central directory record
   struct ZipEocdRecord {
      uint32 signature_;
      uint16 disk_count_;
      uint16 disk_cdir_start_;
      uint16 local_cdir_count_;
      uint16 cdir_record_count_;
      uint32 cdir_size_;
      uint32 cdir_offset_;
      uint16 comment_length_;
   };
#pragma pack(pop)

   FileArchive::FileArchive(FileStream &stream)
      : stream_(stream)
   {
   }

   bool FileArchive::open()
   {
      if (!stream_.is_valid()) {
         return false;
      }

      // todo: error checking
      ZipEocdRecord eocd{};
      stream_.seek(stream_.size() - sizeof(eocd));
      stream_.read(sizeof(eocd), &eocd);
      if (eocd.signature_ != kZipEocdSignature) {
         return false;
      }

      stream_.seek(eocd.cdir_offset_);
      for (uint32 index = 0; index < eocd.cdir_record_count_; index++) {
         ZipCDirHeader cdir{};
         stream_.read(sizeof(cdir), &cdir);
         if (cdir.signature_ != kZipCentralDirSignature) {
            return false;
         }

         // note: small hack to for ascii content
         bool might_be_ascii = (cdir.internal_file_attribs_ & 0x1);
         std::string name(cdir.filename_length_, '\0');
         stream_.read(cdir.filename_length_, name.data());

         Entry entry{};
         entry.data_offset_ = cdir.local_header_offset_ + sizeof(ZipLocalHeader) + cdir.filename_length_;
         entry.size_compressed_ = cdir.size_compressed_ + (might_be_ascii ? 1 : 0);
         entry.size_uncompressed_ = cdir.size_uncompressed_;
         entries_.emplace(name, entry);
      }

      return true;
   }

   void FileArchive::close()
   {
      stream_.close();
      entries_.clear();
   }

   bool FileArchive::contains(const std::string &filename) const
   {
      return entries_.find(filename) != entries_.end();
   }

   bool FileArchive::extract(const std::string &filename, 
                             std::vector<char> &uncompressed)
   {
      if (!stream_.is_valid()) {
         return false;
      }

      // todo: error checking
      auto it = entries_.find(filename);
      if (it == entries_.end()) {
         return false;
      }

      bool result = true;
      const Entry &entry = it->second;
      stream_.seek(entry.data_offset_);
      uncompressed.resize(entry.size_uncompressed_);

      if (entry.size_compressed_ == entry.size_uncompressed_) {
         stream_.read(uncompressed.size(), uncompressed.data());
      }
      else {
         std::vector<char> compressed;
         compressed.resize(entry.size_compressed_, 0);
         stream_.read(compressed.size(), compressed.data());

         result = stbi_zlib_decode_noheader_buffer(uncompressed.data(),
                                                   (int)uncompressed.size(),
                                                   compressed.data(),
                                                   (int)compressed.size()) > 0;
         if (!result) {
            auto error = stbi_failure_reason();
            int asd = 0;
         }
      }

      return result;
   }
} // !papaya
