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

if(CMAKE_SIZEOF_VOID_P EQUAL 8) 
    set(arch "x64")
else() 
    set(arch "x86") 
endif()

include_directories("${PROJECT_SOURCE_DIR}/dependencies/include/"
  "${PROJECT_SOURCE_DIR}/dependencies/include/SDL2/"
  "${Project_SOURCE_DIR}/vendor/spdlog/include/")

add_executable(jsge ${source_files} ${header_files})

if(WIN32)
  add_compile_definitions(WINDOWS)
  file (GLOB_RECURSE static_libs "${PROJECT_SOURCE_DIR}/dependencies/lib/${arch}/*.dll")
  target_link_libraries(jsge GL)
elseif(APPLE)
  add_compile_definitions(MAC)
  file (GLOB_RECURSE static_libs "${PROJECT_SOURCE_DIR}/dependencies/lib/${arch}/*.dylib")
  target_link_libraries(jsge "-framework OpenGL")
else()
  add_compile_definitions(LINUX)
  file (GLOB_RECURSE static_libs "${PROJECT_SOURCE_DIR}/dependencies/lib/${arch}/*.so")
  target_link_libraries(jsge GL)
endif()

target_link_libraries(jsge ${static_libs} Threads::Threads)
