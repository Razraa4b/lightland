#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <ostream>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>

namespace ad::graphics
{
    using Vec2i = glm::vec<2, int, glm::defaultp>;
    using Vec2d = glm::vec<2, double, glm::defaultp>;
    using Vec2f = glm::vec<2, float, glm::defaultp>;
    using Vec3i = glm::vec<3, int, glm::defaultp>;
    using Vec3d = glm::vec<3, double, glm::defaultp>;
    using Vec3f = glm::vec<3, float, glm::defaultp>;
    using Vec4i = glm::vec<4, int, glm::defaultp>;
    using Vec4d = glm::vec<4, double, glm::defaultp>;
    using Vec4f = glm::vec<4, float, glm::defaultp>;

    using Mat4i = glm::mat<4, 4, int, glm::defaultp>;
    using Mat4d = glm::mat<4, 4, double, glm::defaultp>;
    using Mat4f = glm::mat<4, 4, float, glm::defaultp>;
    using Mat3i = glm::mat<3, 3, int, glm::defaultp>;
    using Mat3d = glm::mat<3, 3, double, glm::defaultp>;
    using Mat3f = glm::mat<3, 3, float, glm::defaultp>;
    using Mat2i = glm::mat<2, 2, int, glm::defaultp>;
    using Mat2d = glm::mat<2, 2, double, glm::defaultp>;
    using Mat2f = glm::mat<2, 2, float, glm::defaultp>;

    struct Rect
    {
        Rect() { }
        Rect(double xpos, double ypos, double width, double height) : Rect({ xpos, ypos }, { width, height }) { }
        Rect(Vec2d position, Vec2d size) : position(position), size(size) { }
        Vec2d position;
        Vec2d size;
    };
    inline bool operator==(const Rect& left, const Rect& right)
    {
        return ((left.position == right.position) && 
                (left.size == right.size));
    }
    inline bool operator!=(const Rect& left, const Rect& right)
    {
        return !(left == right);
    }

    struct Quad
    {
        Quad() : side(0.0) { }
        Quad(Vec2d position, double side) : position(position), side(side) { }
        Vec2d position;
        double side;
    };
    inline bool operator==(const Quad& left, const Quad& right)
    {
        return ((left.position == right.position) && 
                (left.side == right.side));
    }
    inline bool operator!=(const Quad& left, const Quad& right)
    {
        return !(left == right);
    }
}

#endif
