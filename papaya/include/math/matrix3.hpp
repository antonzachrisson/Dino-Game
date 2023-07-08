// matrix3.hpp

#ifndef PAPAYA_MATRIX3_HPP_INCLUDED
#define PAPAYA_MATRIX3_HPP_INCLUDED

#include <math/vector3.hpp>

namespace papaya {
   class Matrix3 final {
   public:
      static Matrix3 translate(const float x, const float y);
      static Matrix3 rotate(const float x, const float y, const float radians);
      static Matrix3 scale(const float x, const float y);

   public:
      Matrix3();
      Matrix3(const float xx, const float xy, const float xz,
              const float yx, const float yy, const float yz, 
              const float zx, const float zy, const float zz);
      Matrix3(const Vector3 &x, const Vector3 &y, const Vector3 &z);
      Matrix3(const Matrix3 &rhs);

      Matrix3 operator*(const Matrix3 &rhs) const;

      Vector3 x_;
      Vector3 y_;
      Vector3 z_;
   };

   Vector3 transform_vector(const Matrix3 &lhs, const Vector3 &rhs);
   Vector2 transform_vector(const Matrix3 &lhs, const Vector2 &rhs);
   Vector2 transform_unit_vector(const Matrix3 &lhs, const Vector2 &rhs);
} // !papaya

#endif // !PAPAYA_MATRIX3_HPP_INCLUDED
