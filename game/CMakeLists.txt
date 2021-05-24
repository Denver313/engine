cmake_minimum_required(VERSION 3.19)
project(game CXX)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC engine)

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