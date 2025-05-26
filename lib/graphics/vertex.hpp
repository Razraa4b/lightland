#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "graphics/geometry.hpp"

namespace wg::graphics
{
    struct Vertex
    {
        Vec2f position;
        Vec2f color;
        Vec2f textureCoords;
    };
}

#endif
