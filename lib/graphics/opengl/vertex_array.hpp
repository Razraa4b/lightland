#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

namespace wg::graphics
{
    class VertexBuffer;

    /// @brief Class providing methods for working with vertex array in OpenGL
    class VertexArray
    {
    public:
        /// @brief Initializes a class without a pre-prepared buffer for binding
        VertexArray();
        
        /// @brief Initializes buffer for bundle
        /// @param buffer Vertex buffer to bind
        VertexArray(VertexBuffer& buffer);
        
        /// @brief Initializes buffer data for bundle and vertex data
        /// @param buffer Vertex buffer to bind
        /// @param count Count of vertices
        /// @param startIndex Start index in buffer data
        VertexArray(VertexBuffer& buffer, int count, int startIndex = 0);

        /// @brief Transfers data from `moved` to a new VertexArray instance
        /// @param moved Movable instance
        VertexArray(VertexArray&& moved);

        /// @brief Calls `destroy()` method
        ~VertexArray();

        VertexArray(const VertexArray&) = delete;
        VertexArray& operator=(const VertexArray&) = delete;

        /// @brief Creates a vertex array and binds it to the vertex buffer if possible
        void create();
        
        /// @brief Binds the vertex array to the vertex buffer
        /// @param buffer Vertex buffer to bind
        void bindTo(VertexBuffer& buffer);

        /// @brief Deletes the vertex array object from memory
        void destroy() const;
    private:
        VertexBuffer* m_bindedBuffer;
        unsigned int m_array;
        int m_startIndex;
        int m_count;
    };
}

#endif
