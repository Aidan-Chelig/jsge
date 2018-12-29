cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

add_compile_definitions(GLEW_STATIC)

project(HelloWorld)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include/"
                    "/usr/include/")

add_executable(jsge
  ${source_files})

target_link_libraries(jsge sfml-graphics sfml-window sfml-system )
