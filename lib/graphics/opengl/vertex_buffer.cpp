#include <glad/glad.h>
#include "graphics/opengl/vertex_buffer.hpp"
#include "log.h"

// -----------------------------------
//  VertexBuffer class implementation
// -----------------------------------

namespace ad::graphics
{
    VertexBuffer::VertexBuffer()
        : usageType(UsageType::Dynamic) { }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexBuffer::VertexBuffer(UsageType usageType)
        : usageType(usageType) { }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexBuffer::~VertexBuffer()
    {
        destroy();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexBuffer::VertexBuffer(VertexBuffer&& moved)
        : usageType(moved.usageType),
          m_vertexCount(moved.m_vertexCount), m_buffer(moved.m_buffer)
    {
        moved.m_buffer = 0;
        moved.m_vertexCount = 0;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexBuffer::create(size_t vertexCount)
    {
        create(nullptr, vertexCount);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexBuffer::create(const std::vector<Vertex>& vertices)
    {
        create(vertices.data(), vertices.size());
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexBuffer::create(const Vertex* vertices, size_t count)
    {
        // Delete and recreate the buffer if it already existed
        if(m_buffer)
        {
            glDeleteBuffers(1, &m_buffer);
        }

        m_vertexCount = count;
        glGenBuffers(1, &m_buffer);

        glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(Vertex),
                     vertices, toGLenum(usageType));
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexBuffer::update(const Vertex* vertices, size_t count, int offset)
    {
        m_vertexCount = count;

        glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
        glBufferSubData(GL_ARRAY_BUFFER, offset,
                        count * sizeof(Vertex), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexBuffer::update(const std::vector<Vertex>& vertices, int offset)
    {
        m_vertexCount = vertices.size();

        glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
        glBufferSubData(GL_ARRAY_BUFFER, offset,
                        m_vertexCount * sizeof(Vertex), vertices.data());
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void VertexBuffer::destroy() const
    {
        if(m_buffer)
        {
            glDeleteBuffers(1, &m_buffer);
        }
    }

    
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    unsigned int VertexBuffer::getHandle() const
    {
        return m_buffer;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    size_t VertexBuffer::getVertexCount() const
    {
        return m_vertexCount;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    unsigned int toGLenum(VertexBuffer::UsageType usageType)
    {
        switch(usageType)
        {
            case VertexBuffer::UsageType::Static:  return GL_STATIC_DRAW;
            case VertexBuffer::UsageType::Dynamic: return GL_DYNAMIC_DRAW;
            case VertexBuffer::UsageType::Stream:  return GL_STREAM_DRAW;
            default: return GL_ZERO;
        }
    }
}
