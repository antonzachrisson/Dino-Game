// matrix3.cc

#include "math/matrix3.hpp"
#include "math/vector2.hpp"

#include <cmath>

namespace papaya {
   // static 
   Matrix3 Matrix3::translate(const float x, const float y)
   {
      return
      {
         1.0f, 0.0f, 0.0f,
         0.0f, 0.0f, 0.0f,
            x,    y, 0.0f,
      };
   }

   Matrix3 Matrix3::rotate(const float x, const float y, const float radians)
   {
      const float c = std::cosf(radians);
      const float s = std::sinf(radians);

      return
      {
            c,   -s, 0.0f,
            s,    c, 0.0f,
         0.0f, 0.0f, 1.0f,
      };
   }

   Matrix3 Matrix3::scale(const float x, const float y) 
   {
      return
      {
            x, 0.0f, 0.0f,
         0.0f,    y, 0.0f,
         0.0f, 0.0f, 1.0f,
      };
   }

   Matrix3::Matrix3()
      : x_(1.0f, 0.0f, 0.0f)
      , y_(0.0f, 1.0f, 0.0f)
      , z_(0.0f, 0.0f, 1.0f)
   {
   }

   Matrix3::Matrix3(const float xx, const float xy, const float xz,
                    const float yx, const float yy, const float yz,
                    const float zx, const float zy, const float zz)
      : x_(xx, xy, xz)
      , y_(yx, yy, yz)
      , z_(zx, zy, zz)
   {
   }

   Matrix3::Matrix3(const Vector3 &x, const Vector3 &y, const Vector3 &z)
      : x_(x)
      , y_(y)
      , z_(z)
   {
   }

   Matrix3::Matrix3(const Matrix3 &rhs)
      : x_(rhs.x_)
      , y_(rhs.y_)
      , z_(rhs.z_)
   {
   }

   Matrix3 Matrix3::operator*(const Matrix3 &rhs) const
   {
      const float xx = x_.x_ * rhs.x_.x_ + x_.y_ * rhs.y_.x_ + x_.z_ * rhs.z_.x_;
      const float xy = x_.x_ * rhs.x_.y_ + x_.y_ * rhs.y_.y_ + x_.z_ * rhs.z_.y_;
      const float xz = x_.x_ * rhs.x_.z_ + x_.y_ * rhs.y_.z_ + x_.z_ * rhs.z_.z_;

      const float yx = y_.x_ * rhs.x_.x_ + y_.y_ * rhs.y_.x_ + y_.z_ * rhs.z_.x_;
      const float yy = y_.x_ * rhs.x_.y_ + y_.y_ * rhs.y_.y_ + y_.z_ * rhs.z_.y_;
      const float yz = y_.x_ * rhs.x_.z_ + y_.y_ * rhs.y_.z_ + y_.z_ * rhs.z_.z_;

      const float zx = z_.x_ * rhs.x_.x_ + z_.y_ * rhs.y_.x_ + z_.z_ * rhs.z_.x_;
      const float zy = z_.x_ * rhs.x_.y_ + z_.y_ * rhs.y_.y_ + z_.z_ * rhs.z_.y_;
      const float zz = z_.x_ * rhs.x_.z_ + z_.y_ * rhs.y_.z_ + z_.z_ * rhs.z_.z_;

      return { xx, xy, xz,  yx, yy, yz,  zx, zy, zz };
   }

   Vector3 transform_vector(const Matrix3 &lhs, const Vector3 &rhs)
   {
      const float x = lhs.x_.x_ * rhs.x_ + lhs.x_.y_ * rhs.y_ + lhs.x_.z_ * rhs.z_;
      const float y = lhs.y_.x_ * rhs.x_ + lhs.y_.y_ * rhs.y_ + lhs.y_.z_ * rhs.z_;
      const float z = lhs.z_.x_ * rhs.x_ + lhs.z_.y_ * rhs.y_ + lhs.z_.z_ * rhs.z_;

      return { x, y, z };
   }

   Vector2 transform_vector(const Matrix3 &lhs, const Vector2 &rhs)
   {
      return transform_vector(lhs, Vector3(rhs, 1.0f)).xy();
   }

   Vector2 transform_unit_vector(const Matrix3 &lhs, const Vector2 &rhs)
   {
      return transform_vector(lhs, Vector3(rhs, 0.0f)).xy();
   }
} // !papaya
