cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

add_compile_definitions(GLEW_STATIC)

project(HelloWorld)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

include_directories("/usr/include/GLFW/"
                    "/usr/include/GL/"
                    "${PROJECT_SOURCE_DIR}/include/")

add_executable(cpp_demo
  ${source_files})

target_link_libraries(cpp_demo glfw GL GLEW)
