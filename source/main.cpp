#include "pch.h"
#include "triangle.h"

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "EDGE", nullptr, nullptr);
    if (!window) return -1;

    bgfx::PlatformData platformData{};
    platformData.nwh = glfwGetWin32Window(window);
    bgfx::setPlatformData(platformData);

    bgfx::Init init;
    init.type = bgfx::RendererType::Count; // auto
    bgfx::init(init);

    EDGE::Triangle::InitTriangle();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        bgfx::touch(0);
        EDGE::Triangle::RenderTriangle();

        bgfx::frame();
    }

    EDGE::Triangle::ShutdownTriangle();

    bgfx::shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();
}
