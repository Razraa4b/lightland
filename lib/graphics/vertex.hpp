#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "graphics/geometry.hpp"

namespace wg::graphics
{
    struct Vertex
    {
        Vec3f position;
        Vec4f color;
        Vec2f textureCoords;
    };
}

#endif
