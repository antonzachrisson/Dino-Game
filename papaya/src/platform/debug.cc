// debug.cc

#include "platform/debug.hpp"

#include <SDL.h>
#include <cstdarg>

namespace papaya {
   // static
   void Debug::log(const char *format, ...)
   {
      va_list args;
      va_start(args, format);

      SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION, 
                      SDL_LOG_PRIORITY_INFO, 
                      format, 
                      args);

      va_end(args);
   }
} // !papaya
