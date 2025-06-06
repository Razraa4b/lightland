#include <iostream>
#include "graphics/window.hpp"
#include "graphics/shader.hpp"
#include "graphics/opengl/vertex_array.hpp"
#include "graphics/opengl/vertex_buffer.hpp"

using namespace ad::graphics;

int main()
{
    std::cout << "AeroDesk Console Client" << std::endl;

    Window window("Test Window", { 100, 100, 1000, 600 });

    Shader v("#version 460\nin vec3 pos;in vec4 col;in vec2 tex;out vec4 outColor;void main(){ gl_Position = vec4(pos, 1.0); outColor = col; }", Shader::Type::Vertex);
    Shader f("#version 460\nin vec4 outColor;out vec4 FragColor;void main(){ FragColor = outColor; }", Shader::Type::Fragment);

    ShaderProgram program;
    program.attachShader(v, true);
    program.attachShader(f, true);
    program.link();

    Vertex vertices[] =
    {
        { { 0, 0, 1 }, { 1, 0, 0, 1 } },
        { { 1, 0, 1 }, { 0, 1, 0, 1 } },
        { { 0, 1, 1 }, { 0, 0, 1, 1 } }
    };
    VertexBuffer buffer;
    buffer.create(vertices, 3);

    VertexArray vao(buffer, PrimitiveType::Lines, 3);
    vao.create();

    while(window.isOpen())
    {
        window.clear();
        program.use();
        window.draw(vao);
        window.update();
    }

    return EXIT_SUCCESS;
}
