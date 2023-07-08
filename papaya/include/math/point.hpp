// point.hpp

#ifndef PAPAYA_POINT_HPP_INCLUDED
#define PAPAYA_POINT_HPP_INCLUDED

namespace papaya {
   class Vector2;

   class Point final {
   public:
      Point();
      Point(const int x, const int y);
      Point(const Vector2 &rhs);
      Point(const Point &rhs);

      bool operator==(const Point &rhs) const;
      bool operator!=(const Point &rhs) const;

      int x_;
      int y_;
   };
} // !papaya

#endif // !PAPAYA_POINT_HPP_INCLUDED
