// filesystem.cc

#include "platform/filesystem.hpp"
#include "platform/filestream.hpp"

#include <SDL.h>
#include <cassert>
#include <filesystem>

namespace papaya {
   FileSystem::FileSystem(const char *company, const char *application)
   {
      char *app = SDL_GetBasePath();
      app_path_ = app;
      SDL_free(app);

      char *user = SDL_GetPrefPath(company, application);
      user_path_ = user;
      SDL_free(user);
   }

   FileSystem::~FileSystem()
   {
   }

   const std::string &FileSystem::app_folder_path() const
   {
      return app_path_;
   }

   const std::string &FileSystem::user_folder_path() const
   {
      return user_path_;
   }

   bool FileSystem::file_exists(const char *filename)
   {
      return std::filesystem::exists(filename);
   }

   uint64 FileSystem::file_size(const char *filename)
   {
      return std::filesystem::file_size(filename);
   }

   uint64 FileSystem::last_write_time(const char *filename)
   {
      return std::filesystem::last_write_time(filename).time_since_epoch().count();
   }

   void FileSystem::enumerate_folder(const char *path, 
                                     std::function<void(const char *)> callback,
                                     const bool recursive)
   {
      if (recursive) {
         for (auto &entry : std::filesystem::recursive_directory_iterator(path)) {
            if (entry.is_regular_file()) {
               callback(entry.path().string().c_str());
            }
         }
      }
      else {
         for (auto &entry : std::filesystem::directory_iterator(path)) {
            if (entry.is_regular_file()) {
               callback(entry.path().string().c_str());
            }
         }
      }
   }

   FileStream FileSystem::open(const char *filename)
   {
      return FileStream{ SDL_RWFromFile(filename, "rb") };
   }

} // !papaya
