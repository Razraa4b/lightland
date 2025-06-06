#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include <vector>
#include "graphics/opengl/primitive.hpp"
#include "graphics/vertex.hpp"

namespace ad::graphics
{
    /// @brief Class providing methods for working with vertex buffer in OpenGL
    class VertexBuffer
    {
    public:
        /// @brief Buffer data usage type
        enum class UsageType
        {
            Static,
            Dynamic,
            Stream
        };
        UsageType usageType;
        
        /// @brief Initializes class fields with default values
        VertexBuffer();
        
        /// @brief Initializes class fields with default values
        /// @param usageType Initial value for the buffer usage type
        VertexBuffer(UsageType usageType);
        
        /// @brief Calls `destroy()` method
        ~VertexBuffer();

        /// @brief Transfers data from `moved` to a new VertexBuffer instance
        /// @param moved Movable instance
        VertexBuffer(VertexBuffer&& moved);
        
        VertexBuffer(const VertexBuffer&) = delete;
        VertexBuffer& operator=(const VertexBuffer&) = delete;

        /// @brief Creates a buffer by allocating memory for `n` vertices
        /// @param vertexCount The `n`
        void create(size_t vertexCount);
        
        /// @brief Creates a buffer and fills it with data
        /// @param vertices Pointer to vertex data
        /// @param count Vertex data count
        void create(const Vertex* vertices, size_t count);
        
        /// @brief Creates a buffer and fills it with data
        /// @param vertices Vector of vertices
        void create(const std::vector<Vertex>& vertices);
        
        /// @brief Updates buffer data
        /// @param vertices Pointer to vertex data
        /// @param count Vertex data count
        /// @param offset Offset for the start of data update
        void update(const Vertex* vertices, size_t count, int offset = 0);
        
        /// @brief Updates buffer data
        /// @param vertices Vector of vertices 
        /// @param offset Offset for the start of data update
        void update(const std::vector<Vertex>& vertices, int offset = 0);
        
        /// @brief Deletes the vertex buffer object from memory
        void destroy() const;

        /// @brief Returns OpenGL buffer handle
        unsigned int getHandle() const;
        
        /// @brief Returns vertex count
        size_t getVertexCount() const;
    private:
        unsigned int m_buffer = 0;
        size_t m_vertexCount  = 0;
    };

    unsigned int toGLenum(VertexBuffer::UsageType usageType);
}

#endif
