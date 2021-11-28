cmake_minimum_required (VERSION 3.8)

add_executable (CMakeProject3 "CMakeProject3.cpp" "CMakeProject3.h")
target_link_libraries(CMakeProject3 PRIVATE cpr::cpr)