cmake_minimum_required(VERSION 3.10)

project(Fractal-Explorer)

file(GLOB_RECURSE PROJ_SRC
        "sources/*.cpp"
        "includes/*.h"
        )
if ((NOT DEFINED VCPKG_TARGET_TRIPLET) AND ("${CMAKE_CXX_COMPILER}" MATCHES  g\\+\\+\\.exe) AND (${CMAKE_SIZEOF_VOID_P} EQUAL 4))
    message("Configuration pour MinGW 32")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/dependencies/SFML/lib/cmake/SFML" CACHE FILEPATH "The directory containing a CMake configuration file for SFML.")
endif()

add_executable(${PROJECT_NAME} ${PROJ_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/includes)

find_package(SFML COMPONENTS system window graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-system
        sfml-main
        sfml-window
        sfml-graphics
        )
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIR})
