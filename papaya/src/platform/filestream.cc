// filestream.cc

#include <platform/filestream.hpp>

#include <SDL.h>

namespace papaya {
   FileStream::FileStream()
      : handle_(nullptr)
   {
   }

   FileStream::FileStream(void *handle)
      : handle_(handle)
   {
   }

   FileStream::~FileStream()
   {
      close();
   }

   bool FileStream::is_valid() const
   {
      return handle_ != nullptr;
   }

   void FileStream::close()
   {
      if (is_valid()) {
         SDL_RWclose((SDL_RWops *)handle_);
         handle_ = nullptr;
      }
   }

   int64 FileStream::size() const
   {
      if (!is_valid()) {
         return 0;
      }

      return SDL_RWsize((SDL_RWops *)handle_);
   }

   int64 FileStream::tell() const
   {
      if (!is_valid()) {
         return 0;
      }

      return SDL_RWtell((SDL_RWops *)handle_);
   }

   int64 FileStream::seek(const int64 index)
   {
      if (!is_valid()) {
         return 0;
      }

      return SDL_RWseek((SDL_RWops *)handle_, index, RW_SEEK_SET);
   }

   int64 FileStream::read(const int64 length, void *dst)
   {
      if (!is_valid()) {
         return 0;
      }

      return SDL_RWread((SDL_RWops *)handle_, dst, 1, length);
   }
} // !papaya
