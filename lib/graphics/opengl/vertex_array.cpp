#include <glad/glad.h>
#include "graphics/opengl/vertex_array.hpp"
#include "graphics/opengl/vertex_buffer.hpp"

// -----------------------------------
//  VertexArray class implementation
// -----------------------------------

namespace wg::graphics
{
    VertexArray::VertexArray()
        : m_startIndex(0), m_count(0), m_bindedBuffer(nullptr) { }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexArray::VertexArray(VertexBuffer& buffer)
        : m_bindedBuffer(&buffer) { }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexArray::VertexArray(VertexBuffer& buffer, int count, int startIndex)
        : m_count(count), m_startIndex(startIndex), m_bindedBuffer(&buffer) { }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexArray::VertexArray(VertexArray&& moved)
        : m_array(moved.m_array), m_startIndex(moved.m_startIndex), m_count(moved.m_count), m_bindedBuffer(moved.m_bindedBuffer)
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
}
