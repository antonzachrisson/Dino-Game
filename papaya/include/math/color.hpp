// color.hpp

#ifndef PAPAYA_COLOR_HPP_INCLUDED
#define PAPAYA_COLOR_HPP_INCLUDED

namespace papaya {
   class Color {
   public:
      static const Color Black;
      static const Color White;

   public:
      static Color from_rgba8(const int red, 
                              const int green, 
                              const int blue, 
                              const int alpha = 255);
      static Color from_rgb24(const unsigned int rgb);
      static Color from_rgba32(const unsigned int rgba);

   public:
      Color();
      Color(const float r, const float g, const float b, const float a);
      Color(const Color &rhs);

      float r_;
      float g_;
      float b_;
      float a_;
   };
} // !papaya

#endif // !PAPAYA_COLOR_HPP_INCLUDED
