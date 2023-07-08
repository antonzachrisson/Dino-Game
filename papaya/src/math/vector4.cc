// vector4.cc

#include "math/vector4.hpp"
#include "math/vector2.hpp"
#include "math/vector3.hpp"

namespace papaya {
   Vector4::Vector4()
      : x_(0.0f)
      , y_(0.0f)
      , z_(0.0f)
      , w_(0.0f)
   {
   }

   Vector4::Vector4(const float x, const float y, const float z, const float w)
      : x_(x)
      , y_(y)
      , z_(z)
      , w_(w)
   {
   }

   Vector4::Vector4(const Vector2 &xy, const float z, const float w)
      : x_(xy.x_)
      , y_(xy.y_)
      , z_(z)
      , w_(w)
   {
   }

   Vector4::Vector4(const Vector3 &xyz, const float w)
      : x_(xyz.x_)
      , y_(xyz.y_)
      , z_(xyz.z_)
      , w_(w)
   {
   }

   Vector4::Vector4(const Vector4 &rhs)
      : x_(rhs.x_)
      , y_(rhs.y_)
      , z_(rhs.z_)
      , w_(rhs.w_)
   {
   }

   Vector2 Vector4::xy() const
   {
      return { x_, y_ };
   }

   Vector3 Vector4::xyz() const
   {
      return { x_, y_, z_ };
   }
} // !papaya

