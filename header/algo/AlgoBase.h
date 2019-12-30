#pragma once

#include "other/additional.h"
#include "other/Maze.h"
#include "algo/AlgoManhattan.h"

class AlgoBase {
 public:
  AlgoBase() { };
  virtual ~AlgoBase() { };

  // Factory
  static AlgoBase* createAlgoInstance(algo::Algo type);
  
  virtual std::vector<std::string> searchSolution(const Maze &maze) const = 0;
};


