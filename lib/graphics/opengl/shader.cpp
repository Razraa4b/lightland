#include <string.h>
#include <glad/glad.h>
#include "graphics/shader.hpp"
#include "log.h"

// ------------------------------------------------
//  Shader and ShaderProgram classes implementation
// ------------------------------------------------

namespace ad::graphics
{
    /*-------------------------------------------------------------------------------------------------*/
    /*                                        Shader Class                                             */
    /*-------------------------------------------------------------------------------------------------*/
    
    Shader::Shader(const char* source, Type type) : m_type(type)
    {
        m_shader = glCreateShader(
            type == Type::Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER
        );
        // Add the shader source and compile it
        glShaderSource(m_shader, 1, &source, nullptr);
        glCompileShader(m_shader);

        // Check compile info log if its exists
        int logLength = 0;
        glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &logLength);
        if(logLength != 0)
        {
            char* logMessage = new char[logLength+1];
            glGetShaderInfoLog(m_shader, logLength+1, nullptr, logMessage);
            lcrit("Shader compilation info log: %s\n", logMessage);
            delete[] logMessage;
        }
        else
        {
            ldebug("Compilation of the shader was successful\n");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    Shader::~Shader()
    {
        if(!m_isDisposed)
        {
            dispose();
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    Shader::Type Shader::getType() const
    {
        return m_type;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void Shader::dispose() const
    {
        glDeleteShader(m_shader);
        m_isDisposed = true;
    }

    /*-------------------------------------------------------------------------------------------------*/
    /*                                        ShaderProgram Class                                      */
    /*-------------------------------------------------------------------------------------------------*/

    ShaderProgram::ShaderProgram()
    {
        m_program = glCreateProgram();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    ShaderProgram::~ShaderProgram()
    {
        if(!m_isDisposed)
        {
            dispose();
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void ShaderProgram::attachShader(const Shader& shader, bool dispose) const
    {
        glAttachShader(m_program, shader.m_shader);
        if(dispose)
        {
            shader.dispose();
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void ShaderProgram::link() const
    {
        glLinkProgram(m_program);

        // Check link info log if its exists
        int logLength = 0;
        glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &logLength);
        if(logLength != 0)
        {
            char* logMessage = new char[logLength+1];
            glGetProgramInfoLog(m_program, logLength+1, nullptr, logMessage);
            lcrit("Shader program linking info log: %s\n", logMessage);
            delete[] logMessage;
        }
        else
        {
            ldebug("Shader program linking was successful\n");
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void ShaderProgram::use() const
    {
        glUseProgram(m_program);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void ShaderProgram::dispose() const
    {
        glDeleteProgram(m_program);
        m_isDisposed = true;
    }
}
