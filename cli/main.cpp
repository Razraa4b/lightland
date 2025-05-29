#include <iostream>
#include "graphics/wkwindow.hpp"
#include "graphics/opengl/vertex_buffer.hpp"

using namespace wg::graphics;

int main()
{
    std::cout << "Wingets Console Client" << std::endl;

    WorkingWindow window("Test Window", { 100, 100, 1000, 600 });

    Vertex vertices[] =
    {
        { { 0, 0, 1 }, { 1, 1, 1, 1 } },
        { { 1, 0, 1 }, { 1, 1, 1, 1 } },
        { { 0, 1, 1 }, { 1, 1, 1, 1 } }
    };
    VertexBuffer buffer;
    buffer.create(vertices, 3);

    return EXIT_SUCCESS;
}
