cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(DEP_DIR "${PROJECT_SOURCE_DIR}/dependencies")

add_compile_definitions(SFML_STATIC)


project(HelloWorld)

find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
find_library(SDL2_LIBRARY NAME SDL2)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
link_directories("${PROJECT_SOURCE_DIR}/dependencies/lib/")

file (GLOB_RECURSE source_files "${source_dir}/*.cpp")
file (GLOB_RECURSE header_files "${source_dir}/*.hpp")

file (GLOB static_libs "${PROJECT_SOURCE_DIR}/dependencies/lib/*.a")

include_directories("${PROJECT_SOURCE_DIR}/dependencies/include/"
  "/usr/include/SDL2/"
                    ${SDL2_INCLUDE_DIRS})

add_executable(jsge
  ${source_files}
  ${header_files})


target_link_libraries(jsge SDL2main SDL2 GL)
