// vector3.cc

#include "math/vector3.hpp"
#include "math/vector2.hpp"

namespace papaya {
   Vector3::Vector3()
      : x_(0.0f)
      , y_(0.0f)
      , z_(0.0f)
   {
   }

   Vector3::Vector3(const float x, const float y, const float z)
      : x_(x)
      , y_(y)
      , z_(z)
   {
   }

   Vector3::Vector3(const Vector2 &xy, const float z)
      : x_(xy.x_)
      , y_(xy.y_)
      , z_(z)
   {
   }

   Vector3::Vector3(const Vector3 &rhs)
      : x_(rhs.x_)
      , y_(rhs.y_)
      , z_(rhs.z_)
   {
   }

   Vector2 Vector3::xy() const
   {
      return { x_, y_ };
   }
} // !papaya
