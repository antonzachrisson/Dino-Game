// color.cc

#include "math/color.hpp"

#include <cmath>

namespace papaya {
   static constexpr float kOneOver255 = 1.0f / 255.0f;

   // static 
   const Color Color::Black = Color{ 0.0f, 0.0f, 0.0f, 1.0f };
   const Color Color::White = Color{ 1.0f, 1.0f, 1.0f, 1.0f };

   // static
   Color Color::from_rgba8(const int red, 
                           const int green, 
                           const int blue, 
                           const int alpha)
   {
      const float r = (red   & 0xff) * kOneOver255;
      const float g = (green & 0xff) * kOneOver255;
      const float b = (blue  & 0xff) * kOneOver255;
      const float a = (alpha & 0xff) * kOneOver255;
      return { r, g, b, a };
   }

   Color Color::from_rgb24(const unsigned int rgb)
   {
      const float r = ((rgb >> 16) & 0xff) * kOneOver255;
      const float g = ((rgb >> 8 ) & 0xff) * kOneOver255;
      const float b = ((rgb >> 0 ) & 0xff) * kOneOver255;
      return { r, g, b, 1.0f };
   }

   Color Color::from_rgba32(const unsigned int rgba)
   {
      const float r = ((rgba >> 24) & 0xff) * kOneOver255;
      const float g = ((rgba >> 16) & 0xff) * kOneOver255;
      const float b = ((rgba >> 8 ) & 0xff) * kOneOver255;
      const float a = ((rgba >> 0 ) & 0xff) * kOneOver255;
      return { r, g, b, a };
   }

   Color::Color()
      : r_(1.0f)
      , g_(1.0f)
      , b_(1.0f)
      , a_(1.0f)
   {
   }

   Color::Color(const float r, const float g, const float b, const float a)
      : r_(r)
      , g_(g)
      , b_(b)
      , a_(a)
   {
   }

   Color::Color(const Color &rhs)
      : r_(rhs.r_)
      , g_(rhs.g_)
      , b_(rhs.b_)
      , a_(rhs.a_)
   {
   }
} // !papaya
