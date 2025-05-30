#include <glad/glad.h>
#include "graphics/opengl/primitive.hpp"

namespace wg::graphics
{
    unsigned int toGLenum(PrimitiveType type)
    {
        switch(type)
        {
            case PrimitiveType::Points:        return GL_POINTS;
            case PrimitiveType::Lines:         return GL_LINES;
            case PrimitiveType::LineLoop:      return GL_LINE_LOOP;
            case PrimitiveType::Triangles:     return GL_TRIANGLES;
            case PrimitiveType::TriangleStrip: return GL_TRIANGLE_STRIP;
            default: return GL_ZERO;
        }
    }
}
