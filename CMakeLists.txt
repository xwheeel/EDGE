cmake_minimum_required(VERSION 3.24.0 FATAL_ERROR)

project(EDGE C CXX)
set(PROJECT_NAME EDGE)

set(WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/source/PCH.h>"
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/source"
    #"${CMAKE_CURRENT_SOURCE_DIR}/include/glm"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/bgfx/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/bgfx/3rdparty"
)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/include/glfw")
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
)