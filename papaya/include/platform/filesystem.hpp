// filesystem.hpp

#pragma once

#include <string>
#include <functional>

namespace papaya {
   using uint64 = unsigned long long;

   class FileStream;

   class FileSystem {
   public:
      // note: non-copyable
      FileSystem(const FileSystem &) = delete;
      FileSystem &operator=(const FileSystem &) = delete;

      // note: non-movable
      FileSystem(FileSystem &&) = delete;
      FileSystem &operator=(FileSystem &&) = delete;

   public:
      FileSystem(const char *company, const char *application);
      ~FileSystem();

      FileStream open(const char *filename);

      const std::string &app_folder_path() const;
      const std::string &user_folder_path() const;

      bool file_exists(const char *filename);
      uint64 file_size(const char *filename);
      uint64 last_write_time(const char *filename);

      void enumerate_folder(const char *path, 
                            std::function<void(const char *)> callback,
                            const bool recursive = false);

   private:
      std::string app_path_;
      std::string user_path_;
   };
} // !papaya
