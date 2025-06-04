#ifndef RENDER_INTERFACES_H
#define RENDER_INTERFACES_H

namespace ad::graphics
{
    class RenderCanvas;
    class ShaderProgram;

    /// @brief Contains options for rendering
    struct RenderOptions
    {
        const ShaderProgram* shaderProgram;
    };

    /// @brief The interface representing an entity that can be rendered
    class Drawable
    {
    public:
        /// @brief Draws the current object onto the `canvas` using the rendering `options`
        /// @param options Options for drawing
        /// @param canvas Render canvas
        virtual void draw(const RenderOptions& options,
                          const RenderCanvas&  canvas) const = 0;
    };

    /// @brief Represents an abstract class that allows you to draw on “yourself”
    class RenderCanvas
    {
    public:
        /// @brief Draws a `drawable` using the rendering `options`
        /// @param options Options for drawing
        /// @param drawable The object to be drawn
        inline void draw(const RenderOptions& options,
                         const Drawable&     drawable) const
        {
            drawable.draw(options, *this);
        }              
    };
}

#endif
