#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "graphics/geometry.hpp"

namespace ad::graphics
{
    /// @brief Represents a class for working with object transformations
    class Transform
    {
    public:
        Vec3f position;
        Vec3f rotation;
        Vec3f scale;

        /// @brief Converts `Transform` object field values to matrix
        /// @return Matrix 4x4
        Mat4f toMatrix() const;

        Transform& operator+=(const Transform& right);
        Transform& operator-=(const Transform& right);
        Transform& operator*=(const Transform& right);
        Transform& operator/=(const Transform& right);
    };

    bool operator==(const Transform& left, const Transform& right);
    bool operator!=(const Transform& left, const Transform& right);

    Transform operator+(const Transform& left, const Transform& right);
    Transform operator-(const Transform& left, const Transform& right);
    Transform operator*(const Transform& left, const Transform& right);
    Transform operator/(const Transform& left, const Transform& right);
}

#endif
