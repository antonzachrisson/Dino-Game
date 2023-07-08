// vector2.hpp

#ifndef PAPAYA_VECTOR2_HPP_INCLUDED
#define PAPAYA_VECTOR2_HPP_INCLUDED

namespace papaya {
   class Point;

   class Vector2 final {
   public:
      static Vector2 perpendicular(const Vector2 &rhs);
      static Vector2 min(const Vector2 &lhs, const Vector2 &rhs);
      static Vector2 max(const Vector2 &lhs, const Vector2 &rhs);
      static Vector2 lerp(const Vector2 &lhs, const Vector2 &rhs, const float t);
      static float distance(const Vector2 &lhs, const Vector2 &rhs);

   public:
      Vector2();
      Vector2(const float x, const float y);
      Vector2(const int x, const int y);
      Vector2(const Point &rhs);
      Vector2(const Vector2 &rhs);

      Vector2 operator+(const Vector2 &rhs) const;
      Vector2 operator-(const Vector2 &rhs) const;
      Vector2 operator*(const Vector2 &rhs) const;
      Vector2 operator/(const Vector2 &rhs) const;
      Vector2 operator*(const float rhs) const;
      Vector2 operator/(const float rhs) const;
      Vector2 &operator+=(const Vector2 &rhs);
      Vector2 &operator-=(const Vector2 &rhs);
      Vector2 &operator*=(const float rhs);
      Vector2 &operator/=(const float rhs);

      Vector2 normalized() const;
      float dot(const Vector2 &rhs) const;
      float magnitude() const;
      void normalize();

      float x_;
      float y_;
   };
} // !papaya

#endif // !PAPAYA_VECTOR2_HPP_INCLUDED
