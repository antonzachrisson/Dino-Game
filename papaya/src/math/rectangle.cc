// rectangle.cc

#include "math/rectangle.hpp"
#include "math/point.hpp"
#include "math/vector2.hpp"
#include "math/vector4.hpp"

namespace papaya {
   // static 
   bool Rectangle::contains(const Rectangle &lhs, const Point &rhs)
   {
      bool x_axis = lhs.x_ >= rhs.x_ && lhs.x_ + lhs.width_ <= rhs.x_;
      bool y_axis = lhs.y_ >= rhs.y_ && lhs.y_ + lhs.width_ <= rhs.y_;
      return x_axis && y_axis;
   }

   bool Rectangle::overlap(const Rectangle &lhs, const Rectangle &rhs)
   {
      bool x_axis = (lhs.x_ < (rhs.x_ + rhs.width_)) && ((lhs.x_ + lhs.width_) > rhs.x_);
      bool y_axis = (lhs.y_ < (rhs.y_ + rhs.width_)) && ((lhs.y_ + lhs.width_) > rhs.y_);
      return x_axis && y_axis;
   }

   Rectangle::Rectangle()
      : x_(0)
      , y_(0)
      , width_(0)
      , height_(0)
   {
   }

   Rectangle::Rectangle(const int x, const int y, const int width, const int height)
      : x_(x)
      , y_(y)
      , width_(width)
      , height_(height)
   {
   }

   Rectangle::Rectangle(const Vector2 &xy, const Vector2 &width_height)
      : x_(static_cast<int>(xy.x_))
      , y_(static_cast<int>(xy.y_))
      , width_(static_cast<int>(width_height.x_))
      , height_(static_cast<int>(width_height.y_))
   {
   }

   Rectangle::Rectangle(const Vector4 &rhs)
      : x_(static_cast<int>(rhs.x_))
      , y_(static_cast<int>(rhs.y_))
      , width_(static_cast<int>(rhs.z_))
      , height_(static_cast<int>(rhs.w_))
   {
   }

   Rectangle::Rectangle(const Rectangle &rhs) 
      : x_(rhs.x_)
      , y_(rhs.y_)
      , width_(rhs.width_)
      , height_(rhs.height_)
   {
   }
} // !papaya
