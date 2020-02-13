cmake_minimum_required(VERSION 3.10)
project(rgb2gray)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(${PROJECT_NAME} "rgb2gray.cxx")
target_link_libraries(${PROJECT_NAME} ${ITK_LIBRARIES})