// vector4.hpp

#ifndef PAPAYA_VECTOR4_HPP_INCLUDED
#define PAPAYA_VECTOR4_HPP_INCLUDED

namespace papaya {
   class Vector2;
   class Vector3;

   class Vector4 final {
   public:
      Vector4();
      Vector4(const float x, const float y, const float z, const float w);
      Vector4(const Vector2 &xy, const float z, const float w);
      Vector4(const Vector3 &xyz, const float w);
      Vector4(const Vector4 &rhs);

      Vector2 xy() const;
      Vector3 xyz() const;

      float x_;
      float y_;
      float z_;
      float w_;
   };
} // !papaya

#endif // !PAPAYA_VECTOR4_HPP_INCLUDED
