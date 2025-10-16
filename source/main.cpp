#include "pch.h"

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

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        bgfx::frame();
    }

    bgfx::shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();
}
