// rectangle.hpp

#ifndef PAPAYA_RECTANGLE_HPP_INCLUDED
#define PAPAYA_RECTANGLE_HPP_INCLUDED

namespace papaya {
   class Point;
   class Vector2;
   class Vector4;

   class Rectangle final {
   public:
      static bool contains(const Rectangle &lhs, const Point &rhs);
      static bool overlap(const Rectangle &lhs, const Rectangle &rhs);

   public:
      Rectangle();
      Rectangle(const int x, const int y, const int width, const int height);
      Rectangle(const Vector2 &xy, const Vector2 &width_height);
      Rectangle(const Vector4 &rhs);
      Rectangle(const Rectangle &rhs);

      int x_;
      int y_;
      int width_;
      int height_;
   };
} // !papaya

#endif // !PAPAYA_RECTANGLE_HPP_INCLUDED
