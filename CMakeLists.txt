cmake_minimum_required(VERSION 3.17)
project(pSFML)

set(CMAKE_CXX_STANDARD 17)

file(MAKE_DIRECTORY bin/${CMAKE_BUILD_TYPE}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(SFML/include)
include_directories(include)

add_library(pSFML SHARED include/pSFML/EntryPoint.h src/pSFML/Simulation.cpp include/pSFML/Simulation.h include/psfml.h src/pSFML/Window.cpp include/pSFML/Window.h src/pSFML/Drawer.cpp include/pSFML/Drawer.h src/pSFML/Utilities/Vector.cpp include/pSFML/Utilities/Vector.h include/psfpch.h)

set(CMAKE_PREFIX_PATH "vendor/SFML/lib/cmake/SFML/")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(pSFML sfml-graphics sfml-window sfml-system)

add_executable(Test test/TestSim.cpp)
target_link_libraries(Test pSFML)

add_custom_command(
        TARGET pSFML POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/vendor/SFML/bin/
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

target_precompile_headers(pSFML PUBLIC include/psfpch.h)
