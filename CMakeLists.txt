cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(jsge)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
link_directories("${PROJECT_SOURCE_DIR}/dependencies/lib/")

file (GLOB_RECURSE source_files "${source_dir}/*.cpp")
file (GLOB_RECURSE header_files "${source_dir}/*.h")

file (GLOB_RECURSE static_libs "${PROJECT_SOURCE_DIR}/dependencies/lib/*.dylib")

include_directories("${PROJECT_SOURCE_DIR}/dependencies/include/v8/"
                    "${PROJECT_SOURCE_DIR}/dependencies/include/SDL2/"
                    "${PROJECT_SOURCE_DIR}/dependencies/include/GL/"
                    "${Project_SOURCE_DIR}/vendor/spdlog/include/")

add_executable(jsge ${source_files} ${header_files})

target_link_libraries(jsge ${static_libs} Threads::Threads)
