cmake_minimum_required(VERSION 3.10)
project(MORAC C)

# Force GCC
set(CMAKE_C_COMPILER "gcc")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# GCC specific flags
add_compile_options(-Wall -Wextra -pedantic)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")

set(SOURCES
    src/token.c
    src/lexer.c
    src/lexer/chartype.c
    src/lexer/state.c
    src/lexer/state_utils.c
)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(morac_lib STATIC ${SOURCES})

add_executable(test_lexer tests/test_lexer.c)
target_link_libraries(test_lexer morac_lib)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose build type: Debug or Release" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C Flags: ${CMAKE_C_FLAGS}")