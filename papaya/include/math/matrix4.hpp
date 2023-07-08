// matrix4.hpp

#ifndef PAPAYA_MATRIX4_HPP_INCLUDED
#define PAPAYA_MATRIX4_HPP_INCLUDED

#include <math/vector4.hpp>

namespace papaya {
   class Matrix3;

   class Matrix4 final {
   public:
      static Matrix4 orthographic(const float width, const float height);
      static Matrix4 translate(const float x, const float y, const float z);
      static Matrix4 rotate(const float x, const float y, const float z, const float radians);
      static Matrix4 scale(const float x, const float y, const float z);
      static Matrix4 transpose(const Matrix4 &rhs);
      static bool inverse(Matrix4 &lhs, const Matrix4 &rhs);

   public:
      Matrix4();
      Matrix4(const float xx, const float xy, const float xz, const float xw,
              const float yx, const float yy, const float yz, const float yw,
              const float zx, const float zy, const float zz, const float zw,
              const float wx, const float wy, const float wz, const float ww);
      Matrix4(const Vector4 &x, const Vector4 &y, const Vector4 &z, const Vector4 &w);
      Matrix4(const Matrix3 &rhs);
      Matrix4(const Matrix4 &rhs);

      Matrix4 operator*(const Matrix4 &rhs) const;

      Vector4 x_;
      Vector4 y_;
      Vector4 z_;
      Vector4 w_;
   };

   Vector4 transform_vector(const Matrix4 &lhs, const Vector4 &rhs);
   Vector3 transform_vector(const Matrix4 &lhs, const Vector3 &rhs);
   Vector2 transform_vector(const Matrix4 &lhs, const Vector2 &rhs);
   Vector3 transform_unit_vector(const Matrix4 &lhs, const Vector3 &rhs);
   Vector2 transform_unit_vector(const Matrix4 &lhs, const Vector2 &rhs);
} // !papaya

#endif // !PAPAYA_MATRIX4_HPP_INCLUDED
