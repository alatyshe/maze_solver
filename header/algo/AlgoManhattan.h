#pragma once

#include "algo/AlgoBase.h"

class AlgoManhattan: public AlgoBase {
 public:
  AlgoManhattan() {};
  ~AlgoManhattan() {};

  std::vector<std::string> searchSolution(const Maze &maze_orig) const;

 private:
  mazeStatus::Status mapMarking(Maze &maze, int value) const;
  std::vector<std::string> solution(const Maze &maze, int y_start, int x_start) const;
  std::vector<std::string> impasse() const;
  
  std::vector<std::string> stepsToCmd(const std::vector<std::string> &steps) const;
};