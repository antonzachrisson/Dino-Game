// matrix4.cc

#include "math/matrix4.hpp"
#include "math/matrix3.hpp"
#include "math/vector2.hpp"
#include "math/vector3.hpp"

#include <cmath>

namespace papaya {
   // static
   Matrix4 Matrix4::orthographic(const float width, const float height)
   {
      const float xx = 2.0f / width;
      const float yy = 2.0f / -height;
      const float zz = 1.0f / 2.0f;
      const float wx = -1.0f;
      const float wy = 1.0f;
      const float wz = 0.5f;

      return 
      { 
           xx, 0.0f, 0.0f, 0.0f,
         0.0f,   yy, 0.0f, 0.0f,
         0.0f, 0.0f,   zz, 0.0f,
           wx,   wy,   wz, 1.0f,
      };
   }

   Matrix4 Matrix4::translate(const float x, const float y, const float z)
   {
      return
      {
         1.0f, 0.0f, 0.0f, 0.0f,
         0.0f, 1.0f, 0.0f, 0.0f,
         0.0f, 0.0f, 1.0f, 0.0f,
            x,    y,    z, 1.0f,
      };
   }

   Matrix4 Matrix4::rotate(const float x, const float y, const float z, const float radians)
   {
      const float c = std::cosf(radians);
      const float s = std::sinf(radians);
      const float c1 = 1.0f - c;
      const float xx = x * x;
      const float xy = x * y;
      const float xz = x * z;
      const float yy = y * y;
      const float yz = y * z;
      const float zz = z * z;

      return
      {
             xx * c1 + c,       xy * c1 - z * s,  xz * c1 + y * s,  0.0f,
         xy * c1 + z * s,           yy * c1 + c,  yz * c1 - x * s,  0.0f,
         xz * c1 - y * s,       yz * c1 + x * s,      zz * c1 + c,  0.0f,
                    0.0f,                  0.0f,             0.0f,  1.0f,
      };
   }

   Matrix4 Matrix4::scale(const float x, const float y, const float z)
   {
      return 
      {
            x, 0.0f, 0.0f, 0.0f,
         0.0f,    y, 0.0f, 0.0f,
         0.0f, 0.0f,    z, 0.0f,
         0.0f, 0.0f, 0.0f, 1.0f,
      };
   }

   Matrix4 Matrix4::transpose(const Matrix4 &rhs)
   {
      const float xx = rhs.x_.x_;
      const float xy = rhs.y_.x_;
      const float xz = rhs.z_.x_;
      const float xw = rhs.w_.x_;

      const float yx = rhs.x_.y_;
      const float yy = rhs.y_.y_;
      const float yz = rhs.z_.y_;
      const float yw = rhs.w_.y_;

      const float zx = rhs.x_.z_;
      const float zy = rhs.y_.z_;
      const float zz = rhs.z_.z_;
      const float zw = rhs.w_.z_;

      const float wx = rhs.x_.w_;
      const float wy = rhs.y_.w_;
      const float wz = rhs.z_.w_;
      const float ww = rhs.w_.w_;

      return 
      { 
         xx, xy, xz, xw,  
         yx, yy, yz, yw,  
         zx, zy, zz, zw,  
         wx, wy, wz, ww 
      };
   }

   bool Matrix4::inverse(Matrix4 &lhs, const Matrix4 &rhs)
   {
      // source: github.com/willnode/N-Matrix-Programmer/blob/master/Info/Matrix_4x4.txt
      const float A2323 = rhs.z_.z_ * rhs.w_.w_ - rhs.z_.w_ * rhs.w_.z_;
      const float A1323 = rhs.z_.y_ * rhs.w_.w_ - rhs.z_.w_ * rhs.w_.y_;
      const float A1223 = rhs.z_.y_ * rhs.w_.z_ - rhs.z_.z_ * rhs.w_.y_;
      const float A0323 = rhs.z_.x_ * rhs.w_.w_ - rhs.z_.w_ * rhs.w_.x_;
      const float A0223 = rhs.z_.x_ * rhs.w_.z_ - rhs.z_.z_ * rhs.w_.x_;
      const float A0123 = rhs.z_.x_ * rhs.w_.y_ - rhs.z_.y_ * rhs.w_.x_;
      const float A2313 = rhs.y_.z_ * rhs.w_.w_ - rhs.y_.w_ * rhs.w_.z_;
      const float A1313 = rhs.y_.y_ * rhs.w_.w_ - rhs.y_.w_ * rhs.w_.y_;
      const float A1213 = rhs.y_.y_ * rhs.w_.z_ - rhs.y_.z_ * rhs.w_.y_;
      const float A2312 = rhs.y_.z_ * rhs.z_.w_ - rhs.y_.w_ * rhs.z_.z_;
      const float A1312 = rhs.y_.y_ * rhs.z_.w_ - rhs.y_.w_ * rhs.z_.y_;
      const float A1212 = rhs.y_.y_ * rhs.z_.z_ - rhs.y_.z_ * rhs.z_.y_;
      const float A0313 = rhs.y_.x_ * rhs.w_.w_ - rhs.y_.w_ * rhs.w_.x_;
      const float A0213 = rhs.y_.x_ * rhs.w_.z_ - rhs.y_.z_ * rhs.w_.x_;
      const float A0312 = rhs.y_.x_ * rhs.z_.w_ - rhs.y_.w_ * rhs.z_.x_;
      const float A0212 = rhs.y_.x_ * rhs.z_.z_ - rhs.y_.z_ * rhs.z_.x_;
      const float A0113 = rhs.y_.x_ * rhs.w_.y_ - rhs.y_.y_ * rhs.w_.x_;
      const float A0112 = rhs.y_.x_ * rhs.z_.y_ - rhs.y_.y_ * rhs.z_.x_;

      float det = rhs.x_.x_ * (rhs.y_.y_ * A2323 - rhs.y_.z_ * A1323 + rhs.y_.w_ * A1223) -
         rhs.x_.y_ * (rhs.y_.x_ * A2323 - rhs.y_.z_ * A0323 + rhs.y_.w_ * A0223) +
         rhs.x_.z_ * (rhs.y_.x_ * A1323 - rhs.y_.y_ * A0323 + rhs.y_.w_ * A0123) -
         rhs.x_.w_ * (rhs.y_.x_ * A1223 - rhs.y_.y_ * A0223 + rhs.y_.z_ * A0123);
      det = 1.0f / det;
      if (det == 0.0f) {
         return false;
      }

      lhs.x_.x_ = det *  (rhs.y_.y_ * A2323 - rhs.y_.z_ * A1323 + rhs.y_.w_ * A1223);
      lhs.x_.y_ = det * -(rhs.x_.y_ * A2323 - rhs.x_.z_ * A1323 + rhs.x_.w_ * A1223);
      lhs.x_.z_ = det *  (rhs.x_.y_ * A2313 - rhs.x_.z_ * A1313 + rhs.x_.w_ * A1213);
      lhs.x_.w_ = det * -(rhs.x_.y_ * A2312 - rhs.x_.z_ * A1312 + rhs.x_.w_ * A1212);
      lhs.y_.x_ = det * -(rhs.y_.x_ * A2323 - rhs.y_.z_ * A0323 + rhs.y_.w_ * A0223);
      lhs.y_.y_ = det *  (rhs.x_.x_ * A2323 - rhs.x_.z_ * A0323 + rhs.x_.w_ * A0223);
      lhs.y_.z_ = det * -(rhs.x_.x_ * A2313 - rhs.x_.z_ * A0313 + rhs.x_.w_ * A0213);
      lhs.y_.w_ = det *  (rhs.x_.x_ * A2312 - rhs.x_.z_ * A0312 + rhs.x_.w_ * A0212);
      lhs.z_.x_ = det *  (rhs.y_.x_ * A1323 - rhs.y_.y_ * A0323 + rhs.y_.w_ * A0123);
      lhs.z_.y_ = det * -(rhs.x_.x_ * A1323 - rhs.x_.y_ * A0323 + rhs.x_.w_ * A0123);
      lhs.z_.z_ = det *  (rhs.x_.x_ * A1313 - rhs.x_.y_ * A0313 + rhs.x_.w_ * A0113);
      lhs.z_.w_ = det * -(rhs.x_.x_ * A1312 - rhs.x_.y_ * A0312 + rhs.x_.w_ * A0112);
      lhs.w_.x_ = det * -(rhs.y_.x_ * A1223 - rhs.y_.y_ * A0223 + rhs.y_.z_ * A0123);
      lhs.w_.y_ = det *  (rhs.x_.x_ * A1223 - rhs.x_.y_ * A0223 + rhs.x_.z_ * A0123);
      lhs.w_.z_ = det * -(rhs.x_.x_ * A1213 - rhs.x_.y_ * A0213 + rhs.x_.z_ * A0113);
      lhs.w_.w_ = det *  (rhs.x_.x_ * A1212 - rhs.x_.y_ * A0212 + rhs.x_.z_ * A0112);

      return true;
   }

   Matrix4::Matrix4()
      : x_(1.0f, 0.0f, 0.0f, 0.0f)
      , y_(0.0f, 1.0f, 0.0f, 0.0f)
      , z_(0.0f, 0.0f, 1.0f, 0.0f)
      , w_(0.0f, 0.0f, 0.0f, 1.0f)
   {
   }

   Matrix4::Matrix4(const float xx, const float xy, const float xz, const float xw,
                    const float yx, const float yy, const float yz, const float yw,
                    const float zx, const float zy, const float zz, const float zw,
                    const float wx, const float wy, const float wz, const float ww)
      : x_(xx, xy, xz, xw)
      , y_(yx, yy, yz, yw)
      , z_(zx, zy, zz, zw)
      , w_(wx, wy, wz, ww)
   {
   }

   Matrix4::Matrix4(const Vector4 &x, const Vector4 &y, const Vector4 &z, const Vector4 &w)
      : x_(x)
      , y_(y)
      , z_(z)
      , w_(w)
   {
   }

   Matrix4::Matrix4(const Matrix3 &rhs)
      : x_(rhs.x_, 0.0f)
      , y_(rhs.y_, 0.0f)
      , z_(0.0f, 0.0f, 1.0f, 0.0f)
      , w_(rhs.z_.xy(), 0.0f, 1.0f)
   {
   }

   Matrix4::Matrix4(const Matrix4 &rhs)
      : x_(rhs.x_)
      , y_(rhs.y_)
      , z_(rhs.z_)
      , w_(rhs.w_)
   {
   }

   Matrix4 Matrix4::operator*(const Matrix4 &rhs) const
   {
      const float xx = x_.x_ *rhs.x_.x_ + x_.y_ * rhs.y_.x_ + x_.z_ * rhs.z_.x_ + x_.w_ * rhs.w_.x_;
      const float xy = x_.x_ *rhs.x_.y_ + x_.y_ * rhs.y_.y_ + x_.z_ * rhs.z_.y_ + x_.w_ * rhs.w_.y_;
      const float xz = x_.x_ *rhs.x_.z_ + x_.y_ * rhs.y_.z_ + x_.z_ * rhs.z_.z_ + x_.w_ * rhs.w_.z_;
      const float xw = x_.x_ *rhs.x_.w_ + x_.y_ * rhs.y_.w_ + x_.z_ * rhs.z_.w_ + x_.w_ * rhs.w_.w_;
      
      const float yx = y_.x_ *rhs.x_.x_ + y_.y_ * rhs.y_.x_ + y_.z_ * rhs.z_.x_ + y_.w_ * rhs.w_.x_;
      const float yy = y_.x_ *rhs.x_.y_ + y_.y_ * rhs.y_.y_ + y_.z_ * rhs.z_.y_ + y_.w_ * rhs.w_.y_;
      const float yz = y_.x_ *rhs.x_.z_ + y_.y_ * rhs.y_.z_ + y_.z_ * rhs.z_.z_ + y_.w_ * rhs.w_.z_;
      const float yw = y_.x_ *rhs.x_.w_ + y_.y_ * rhs.y_.w_ + y_.z_ * rhs.z_.w_ + y_.w_ * rhs.w_.w_;
      
      const float zx = z_.x_ *rhs.x_.x_ + z_.y_ * rhs.y_.x_ + z_.z_ * rhs.z_.x_ + z_.w_ * rhs.w_.x_;
      const float zy = z_.x_ *rhs.x_.y_ + z_.y_ * rhs.y_.y_ + z_.z_ * rhs.z_.y_ + z_.w_ * rhs.w_.y_;
      const float zz = z_.x_ *rhs.x_.z_ + z_.y_ * rhs.y_.z_ + z_.z_ * rhs.z_.z_ + z_.w_ * rhs.w_.z_;
      const float zw = z_.x_ *rhs.x_.w_ + z_.y_ * rhs.y_.w_ + z_.z_ * rhs.z_.w_ + z_.w_ * rhs.w_.w_;
                                                                                  
      const float wx = w_.x_ *rhs.x_.x_ + w_.y_ * rhs.y_.x_ + w_.z_ * rhs.z_.x_ + w_.w_ * rhs.w_.x_;
      const float wy = w_.x_ *rhs.x_.y_ + w_.y_ * rhs.y_.y_ + w_.z_ * rhs.z_.y_ + w_.w_ * rhs.w_.y_;
      const float wz = w_.x_ *rhs.x_.z_ + w_.y_ * rhs.y_.z_ + w_.z_ * rhs.z_.z_ + w_.w_ * rhs.w_.z_;
      const float ww = w_.x_ *rhs.x_.w_ + w_.y_ * rhs.y_.w_ + w_.z_ * rhs.z_.w_ + w_.w_ * rhs.w_.w_;

      return
      {
         xx, xy, xz, xw,
         yx, yy, yz, yw,
         zx, zy, zz, zw,
         wx, wy, wz, ww
      };
   }

   Vector4 transform_vector(const Matrix4 &lhs, const Vector4 &rhs)
   {
      const float x = lhs.x_.x_ * rhs.x_ + lhs.x_.y_ * rhs.y_ + lhs.x_.z_ * rhs.z_ + lhs.x_.w_ * rhs.w_;
      const float y = lhs.y_.x_ * rhs.x_ + lhs.y_.y_ * rhs.y_ + lhs.y_.z_ * rhs.z_ + lhs.y_.w_ * rhs.w_;
      const float z = lhs.z_.x_ * rhs.x_ + lhs.z_.y_ * rhs.y_ + lhs.z_.z_ * rhs.z_ + lhs.z_.w_ * rhs.w_;
      const float w = lhs.w_.x_ * rhs.x_ + lhs.w_.y_ * rhs.y_ + lhs.w_.z_ * rhs.z_ + lhs.w_.w_ * rhs.w_;

      return { x, y, z, w };
   }

   Vector3 transform_vector(const Matrix4 &lhs, const Vector3 &rhs)
   {
      return transform_vector(lhs, Vector4(rhs, 1.0f)).xyz();
   }

   Vector2 transform_vector(const Matrix4 &lhs, const Vector2 &rhs)
   {
      return transform_vector(lhs, Vector4(rhs, 0.0f, 1.0f)).xy();
   }

   Vector3 transform_unit_vector(const Matrix4 &lhs, const Vector3 &rhs)
   {
      return transform_vector(lhs, Vector4(rhs, 0.0f)).xyz();
   }

   Vector2 transform_unit_vector(const Matrix4 &lhs, const Vector2 &rhs)
   {
      return transform_vector(lhs, Vector4(rhs, 0.0f, 0.0f)).xy();
   }
} // !papaya
