cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)

project (SoftwareRasterizer)

include_directories(header)

file(GLOB SOURCES "source/*.cpp")

add_executable(run ${SOURCES})
