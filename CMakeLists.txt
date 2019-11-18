cmake_minimum_required(VERSION 2.8.11)

project(centerline)

set(CMAKE_CXX_STANDARD 11)


# CGAL and its components
find_package(CGAL QUIET COMPONENTS Core)

if (NOT CGAL_FOUND)

    message(STATUS "This project requires the CGAL library, and will not be compiled.")
    return()

endif ()

# include helper file
include(${CGAL_USE_FILE})


# Boost and its components
find_package(Boost REQUIRED)

if (NOT Boost_FOUND)

    message(STATUS "This project requires the Boost library, and will not be compiled.")

    return()

endif ()


include_directories(include)

add_executable(
        centerline
        src/main.cpp
        src/parse.cpp
        src/partition.cpp
        src/straight_skeleton.cpp
        src/simplify.cpp
        src/incident.cpp)
