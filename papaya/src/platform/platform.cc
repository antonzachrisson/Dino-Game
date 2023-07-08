// platform.cc

#include "platform/platform.hpp"

#include <SDL.h>
#include <stdexcept>

namespace papaya {
   Platform::Platform()
   {
      if (SDL_Init( SDL_INIT_VIDEO ) != 0) {
         throw std::runtime_error("Could not initialize SDL!");
      }
   }

   Platform::~Platform()
   {
      SDL_Quit();
   }
} // !papaya
