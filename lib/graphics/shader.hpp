#ifndef SHADER_HPP
#define SHADER_HPP

namespace wg::graphics
{
    #define SHADER unsigned int
    #define SHADER_PROGRAM unsigned int

    /// @brief The class representing functions for creating and managing shaders
    class Shader
    {
    public:
        friend class ShaderProgram;

        /// @brief Shader type
        enum class Type
        {
            Vertex,
            Fragment
        };

        /// @brief Creates a shader type `type`
        /// @param source Shader source code
        /// @param type Shader type
        Shader(const char* source, Type type);

        /// @brief Deletes the shader
        ~Shader();

        /// @brief Returns shader type
        Type getType() const;
        
        /// @brief Frees memory from the shader by deleting it
        void dispose() const;
    private:
        Type m_type;
        mutable bool m_isDisposed;
        SHADER m_shader;
    };

    class ShaderProgram
    {
    public:
        /// @brief Creates a shader program
        ShaderProgram();
        
        /// @brief Deletes the shader program
        ~ShaderProgram();

        /// @brief Binds the shader to the program
        /// @param shader Binding shader
        /// @param dispose Flag whether the shader should be deleted after it has been attached
        void attachShader(const Shader& shader, bool dispose = false) const;
        
        /// @brief Links the shader program
        void link() const;
        
        /// @brief Uses the shader program
        void use() const;
        
        /// @brief Deletes the shader program
        void dispose() const;
    private:
        mutable bool m_isDisposed;
        SHADER_PROGRAM m_program;
    };
}

#endif
