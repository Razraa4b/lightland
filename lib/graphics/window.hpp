#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "graphics/window_base.hpp"
#include "graphics/render_ifs.hpp"

struct GLFWwindow;

namespace ad::graphics
{
    /// @brief Represents the implementation of a working graphical window
    class Window : public WindowBase, public RenderCanvas
    {
    public:
        /// @brief Creates a window
        /// @param title Window title
        /// @param rect Initial window size and position
        /// @param style Window style
        Window(const char* title, Rect rect, Style style = Style::Default);

        /// @brief Closes the window and destroys its context
        ~Window();

        /// @brief Resizes the window to `size`
        void resize(Vec2d size) override;

        /// @brief Moves the window to `position`
        void move(Vec2d position) override;

        /// @brief Cleans the window surface by filling with black color
        void clear() const override;

        /// @brief Updates the current window frame with the new one
        void update() const override;

        /// @brief Closes window and destroys his context
        void close() const override;

        /// Returns the window open status
        /// @return `true` if window is open, otherwise `false`
        bool isOpen() const override;
    private:
        GLFWwindow* m_glfw_window;
        mutable bool m_isDisposed;
    };
}

#endif
