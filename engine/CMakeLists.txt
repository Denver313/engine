cmake_minimum_required(VERSION 3.19)
project(engine CXX)

add_library(${PROJECT_NAME} SHARED source/engine.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

############################ SDL2 ##############################

find_package(sdl2 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

#################### COMPILATION OPTIONS #######################

# TARGET VERSION OF STANDARD C++
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# BUILD MODE
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Wextra -Wpedantic -Wfatal-errors -pthread")
# -O2            (optimization level: -O0, -O1, -O2, -O3, -Os, -Og, -Ofast)
# -Wall          (enables all compiler's warning messages)
# -Wextra        (nables some extra warning flags that are not enabled by -Wall)
# -Wpedantic     (issue all the warnings demanded by strict ISO C and ISO C++)
# -Wfatal-errors (compiler to abort compilation on the first error)
# -Werror        (warning == error)
# -pthread       (multithrading enable)