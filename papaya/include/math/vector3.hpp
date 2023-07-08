// vector4.hpp

#ifndef PAPAYA_VECTOR3_HPP_INCLUDED
#define PAPAYA_VECTOR3_HPP_INCLUDED

namespace papaya {
    class Vector2;

    class Vector3 final {
    public:
        Vector3();
        Vector3(const float x, const float y, const float z);
        Vector3(const Vector2 &xy, const float z);
        Vector3(const Vector3 &rhs);

        Vector2 xy() const;

        float x_;
        float y_;
        float z_;
    };
} // !papaya

#endif // !PAPAYA_VECTOR3_HPP_INCLUDED
