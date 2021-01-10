cmake_minimum_required(VERSION 3.17)
project(SiriusEngine)

set(CMAKE_CXX_STANDARD 17)

file(MAKE_DIRECTORY bin/${CMAKE_BUILD_TYPE}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(SFML/include)
include_directories(include)

add_library(Sirius SHARED include/Sirius/EntryPoint.h src/Sirius/Simulation.cpp include/Sirius/Simulation.h include/Sirius.h src/Sirius/Window.cpp include/Sirius/Window.h src/Sirius/Drawer.cpp include/Sirius/Drawer.h src/Sirius/Utilities/Vector.cpp include/Sirius/Utilities/Vector.h)

set(CMAKE_PREFIX_PATH "vendor/SFML/lib/cmake/SFML/")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(Sirius sfml-graphics sfml-window sfml-system)

add_executable(Test test/TestSim.cpp)
target_link_libraries(Test Sirius)

add_custom_command(
        TARGET Sirius POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/vendor/SFML/bin/
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
