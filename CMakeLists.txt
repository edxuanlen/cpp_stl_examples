cmake_minimum_required(VERSION 3.4.1)
project(cpp_stl_examples VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
file(GLOB ALL_SOURCE "*/*/*/*.cpp" "*/*/*/*.cc")
file(GLOB ALL_HEAD "*/*/*/*.hpp" "*/*/*/*.h")

foreach(s ${ALL_SOURCE})
    string(REGEX MATCHALL "[0-9A-Za-z_]*.cc" s1 ${s})
    string(REGEX REPLACE ".cc" "" s2 ${s1})
    add_executable(${s2} ${s} ${ALL_HEAD})
endforeach()
