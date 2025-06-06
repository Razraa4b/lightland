#include <glad/glad.h>
#include "graphics/opengl/primitive.hpp"
#include "graphics/opengl/vertex_array.hpp"
#include "graphics/opengl/vertex_buffer.hpp"

// -----------------------------------
//  VertexArray class implementation
// -----------------------------------

namespace ad::graphics
{
    VertexArray::VertexArray()
        : startIndex(0), vertexCount(0), m_bindedBuffer(nullptr) { }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexArray::VertexArray(VertexBuffer& buffer)
        : m_bindedBuffer(&buffer) { }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexArray::VertexArray(VertexBuffer& buffer, PrimitiveType primitiveType, size_t vertexCount, int startIndex)
        : vertexCount(vertexCount), primitiveType(primitiveType), startIndex(startIndex), m_bindedBuffer(&buffer) { }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexArray::VertexArray(VertexArray&& moved)
        : m_array(moved.m_array), startIndex(moved.startIndex), vertexCount(moved.vertexCount), m_bindedBuffer(moved.m_bindedBuffer)
    {
        moved.m_array = 0;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexArray::~VertexArray()
    {
        destroy();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexArray::create()
    {
        if (m_array) 
        {
            glDeleteVertexArrays(1, &m_array);
        }
        
        glGenVertexArrays(1, &m_array);
        if(m_bindedBuffer)
        {
            bindTo(*m_bindedBuffer);
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexArray::bindTo(VertexBuffer& buffer)
    {
        glBindVertexArray(m_array);
        glBindBuffer(GL_ARRAY_BUFFER, buffer.getHandle());

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoords));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexArray::destroy() const
    {
        if(m_array)
        {
            glDeleteVertexArrays(1, &m_array);
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    unsigned int VertexArray::getHandle() const
    {
        return m_array;
    }
}
