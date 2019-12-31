cmake_minimum_required(VERSION 3.3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}..)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header)


project(test)
set(TEST_EXEC
  src_cpp/ReadBase.cpp
  src_cpp/AlgoBase.cpp
  src_cpp/WriteBase.cpp

  src_cpp/Maze.cpp
  src_cpp/Solver.cpp

  src_cpp/ReadFile.cpp
  src_cpp/Parser.cpp
  src_cpp/AlgoManhattan.cpp

  src_cpp/main.cpp
)

   
# Executble
add_executable(test ${TEST_EXEC})