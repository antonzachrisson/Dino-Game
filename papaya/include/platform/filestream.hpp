// filestream.hpp

#pragma once 

namespace papaya {
   using int64 = long long;

   class FileStream final {
   public:
      // note: non-copyable
      FileStream(const FileStream &rhs) = delete;
      FileStream &operator=(const FileStream &rhs) = delete;

      // note: non-movable
      FileStream(FileStream &&rhs) = delete;
      FileStream &operator=(FileStream &&rhs) = delete;

   public:
      FileStream();
      FileStream(void *handle);
      ~FileStream();

      bool is_valid() const;
      void close();

      int64 size() const;
      int64 tell() const;
      int64 seek(const int64 index);
      int64 read(const int64 length, void *dst);

   private:
      void *handle_;
   };
} // !papaya
