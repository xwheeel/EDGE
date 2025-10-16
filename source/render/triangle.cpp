#include "triangle.h"

// Simple vertex struct
struct PosColorVertex {
    float x, y, z;
    uint32_t abgr;
};

// Vertex declaration for bgfx
static bgfx::VertexLayout layout;

static bgfx::VertexBufferHandle vbo = BGFX_INVALID_HANDLE;
static bgfx::IndexBufferHandle ibo = BGFX_INVALID_HANDLE;
static bgfx::ProgramHandle program = BGFX_INVALID_HANDLE;

namespace EDGE::Triangle {

void InitTriangle() {
    // Define vertex layout
    layout.begin()
        .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
        .end();

    // Triangle vertices
    static PosColorVertex vertices[] = {
        { 0.0f, 0.5f, 0.0f, 0xff0000ff }, // red
        { 0.5f, -0.5f, 0.0f, 0xff00ff00 }, // green
        { -0.5f, -0.5f, 0.0f, 0xffff0000 } // blue
    };

    // Indices
    static const uint16_t indices[] = { 0, 1, 2 };

    // Create vertex and index buffers
    vbo = bgfx::createVertexBuffer(
        bgfx::makeRef(vertices, sizeof(vertices)),
        layout
    );
    ibo = bgfx::createIndexBuffer(
        bgfx::makeRef(indices, sizeof(indices))
    );

    // Load shaders (you can generate shaders via bgfx tools)
    // For testing, assume shaders are precompiled into .bin
    program = bgfx::createProgram(
        bgfx::createShader(bgfx::makeRef("vs_triangle.bin", sizeof("vs_triangle.bin"))),
        bgfx::createShader(bgfx::makeRef("fs_triangle.bin", sizeof("fs_triangle.bin"))),
        true
    );
}

void RenderTriangle() {
    // Set view and clear
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, 800, 600);

    // Submit triangle
    bgfx::setVertexBuffer(0, vbo);
    bgfx::setIndexBuffer(ibo);
    bgfx::submit(0, program);
}

void ShutdownTriangle() {
    if (bgfx::isValid(vbo)) bgfx::destroy(vbo);
    if (bgfx::isValid(ibo)) bgfx::destroy(ibo);
    if (bgfx::isValid(program)) bgfx::destroy(program);
}

} // namespace Test
