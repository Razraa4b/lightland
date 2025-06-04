#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "graphics/geometry.hpp"

namespace ad::graphics
{
    /// @brief Represents an interface of graphical window
    class Window
    {
    public:
        /// @brief Type of style used on windows
        enum class Style
        {
            None,
            Default,
            NoResize
        };

        virtual void resize(Vec2d size) = 0;
        virtual void move(Vec2d position) = 0;
        
        virtual void clear() const = 0;
        virtual void update() const = 0;

        virtual void close() const = 0;
        virtual bool isOpen() const = 0;
    };
}

#endif
