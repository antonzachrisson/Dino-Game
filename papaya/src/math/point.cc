// point.cc

#include "math/point.hpp"
#include "math/vector2.hpp"

namespace papaya {
   Point::Point()
      : x_(0)
      , y_(0)
   {
   }

   Point::Point(const int x, const int y) 
      : x_(x)
      , y_(y)
   {
   }

   Point::Point(const Vector2 &rhs)
      : x_(static_cast<int>(rhs.x_))
      , y_(static_cast<int>(rhs.y_))
   {
   }

   Point::Point(const Point &rhs)
      : x_(rhs.x_)
      , y_(rhs.y_)
   {
   }

   bool Point::operator==(const Point &rhs) const
   {
      return x_ == rhs.x_ && y_ == rhs.y_;
   }

   bool Point::operator!=(const Point &rhs) const
   {
      return x_ != rhs.x_ || y_ != rhs.y_;
   }
} // !papaya
