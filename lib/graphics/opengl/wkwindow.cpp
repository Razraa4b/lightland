#include <string.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "graphics/wkwindow.hpp"
#include "log.h"

// -----------------------------------
//  WorkingWindow class implementation
// -----------------------------------

namespace ad::graphics
{
    void framebufferSizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    WorkingWindow::WorkingWindow(const char* title, Rect rect, Style style)
    {
        glfwInit();
        // OpenGL 4.6
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        glfwWindowHint(GLFW_RESIZABLE, style == Style::NoResize ? GLFW_FALSE : GLFW_TRUE);
        glfwWindowHint(GLFW_DECORATED, style == Style::None ? GLFW_FALSE : GLFW_TRUE);
        // Hide window before its get ready
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_glfw_window = glfwCreateWindow(rect.size.x, rect.size.y, title, NULL, NULL);
        if(m_glfw_window == NULL)
        {
            lfatal("Failed to create GLFW window\n");
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(m_glfw_window);
        ldebug("GLFW window created and binded as current context\n");

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            lfatal("Failed to initialize GLAD\n");
            glfwTerminate();
            return;
        }
        ldebug("GLAD initialized\n");

        glViewport(0, 0, rect.size.x, rect.size.y);
        glfwSetFramebufferSizeCallback(m_glfw_window, framebufferSizeCallback);

        // Moves window to specified position
        move(rect.position);

        // Finally window is ready
        glfwShowWindow(m_glfw_window);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    WorkingWindow::~WorkingWindow()
    {
        close();
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void WorkingWindow::resize(Vec2d size)
    {
        glfwSetWindowSize(m_glfw_window, size.x, size.y);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void WorkingWindow::move(Vec2d position)
    {
        glfwSetWindowPos(m_glfw_window, position.x, position.y);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void WorkingWindow::clear() const
    {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void WorkingWindow::update() const
    {
        glfwSwapBuffers(m_glfw_window);
        glfwPollEvents();

        #ifdef _DEBUG
        int error_code = glGetError();
        if(error_code != GL_NO_ERROR)
        {
            lerror("OpenGL error code %d\n", error_code);
        }
        #endif
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void WorkingWindow::close() const
    {
        if(!m_isDisposed)
        {
            const char* tmp = glfwGetWindowTitle(m_glfw_window);
            char* title = new char[strlen(tmp)+1];
            strcpy(title, tmp);
        
            glfwDestroyWindow(m_glfw_window);
            glfwTerminate();
            m_isDisposed = true;

            ldebug("The window named \'Main Window\' has been destroyed\n", title);
            delete title;
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    bool WorkingWindow::isOpen() const
    {
        return !glfwWindowShouldClose(m_glfw_window);
    }
}
