// vector2.cc

#include "math/vector2.hpp"
#include "math/point.hpp"

#include <cmath>

namespace papaya {
   //static 
   Vector2 Vector2::perpendicular(const Vector2 &rhs)
   {
      return { -rhs.y_, rhs.x_ };
   }

   Vector2 Vector2::min(const Vector2 &lhs, const Vector2 &rhs)
   {
      const float x = lhs.x_ < rhs.x_ ? lhs.x_ : rhs.x_;
      const float y = lhs.y_ < rhs.y_ ? lhs.y_ : rhs.y_;
      return { x, y };
   }

   Vector2 Vector2::max(const Vector2 &lhs, const Vector2 &rhs)
   {
      const float x = lhs.x_ > rhs.x_ ? lhs.x_ : rhs.x_;
      const float y = lhs.y_ > rhs.y_ ? lhs.y_ : rhs.y_;
      return { x, y };
   }

   Vector2 Vector2::lerp(const Vector2 &lhs, const Vector2 &rhs, const float t)
   {
      if (t >= 1.0f) {
         return rhs;
      }
      else if (t <= 0.0f) {
         return lhs;
      }

      const float x = lhs.x_ + (rhs.x_ - lhs.x_) * t;
      const float y = lhs.y_ + (rhs.y_ - lhs.y_) * t;
      return { x, y };
   }

   float Vector2::distance(const Vector2 &lhs, const Vector2 &rhs)
   {
      return (rhs - lhs).magnitude();
   }

   Vector2::Vector2()
      : x_(0.0f)
      , y_(0.0f)
   {
   }

   Vector2::Vector2(const float x, const float y)
      : x_(x)
      , y_(y)
   {
   }

   Vector2::Vector2(const int x, const int y)
      : x_(static_cast<float>(x))
      , y_(static_cast<float>(y))
   {
   }

   Vector2::Vector2(const Point &rhs)
      : x_(static_cast<float>(rhs.x_))
      , y_(static_cast<float>(rhs.y_))
   {
   }

   Vector2::Vector2(const Vector2 &rhs)
      : x_(rhs.x_)
      , y_(rhs.y_)
   {
   }

   Vector2 Vector2::operator+(const Vector2 &rhs) const
   {
      return { x_ + rhs.x_, y_ + rhs.y_ };
   }

   Vector2 Vector2::operator-(const Vector2 &rhs) const
   {
      return { x_ - rhs.x_, y_ - rhs.y_ };
   }

   Vector2 Vector2::operator*(const Vector2 &rhs) const 
   {
      return { x_ * rhs.x_, y_ * rhs.y_ };
   }

   Vector2 Vector2::operator/(const Vector2 &rhs) const 
   {
      return { x_ / rhs.x_, y_ / rhs.y_ };
   }

   Vector2 Vector2::operator*(const float rhs) const
   {
      return { x_ * rhs, y_ * rhs };
   }

   Vector2 Vector2::operator/(const float rhs) const
   {
      return { x_ / rhs, y_ / rhs};
   }

   Vector2 &Vector2::operator+=(const Vector2 &rhs)
   {
      x_ += rhs.x_;
      y_ += rhs.y_;
      return *this;
   }

   Vector2 &Vector2::operator-=(const Vector2 &rhs)
   {
      x_ -= rhs.x_;
      y_ -= rhs.y_;
      return *this;
   }

   Vector2 &Vector2::operator*=(const float rhs)
   {
      x_ *= rhs;
      y_ *= rhs;
      return *this;
   }

   Vector2 &Vector2::operator/=(const float rhs)
   {
      x_ /= rhs;
      y_ /= rhs;
      return *this;
   }

   Vector2 Vector2::normalized() const
   {
      Vector2 result(*this);
      return result / result.magnitude();
   }

   float Vector2::dot(const Vector2 &rhs) const
   {
      return (x_ * rhs.x_ + y_ * rhs.y_);
   }

   float Vector2::magnitude() const
   {
      return std::sqrtf(x_ * x_ + y_ * y_);
   }

   void Vector2::normalize()
   {
      const float length = magnitude();
      x_ /= length;
      y_ /= length;
   }
} // !papaya
