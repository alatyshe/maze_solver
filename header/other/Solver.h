#pragma once

#include "other/additional.h"

#include "read/ReadFile.h"
#include "parse/Parser.h"
#include "algo/AlgoManhattan.h"
#include "write/WriteFile.h"

class Solver {
  Solver() = delete;
  Solver(const Solver &src) = delete;
  Solver& operator=(const Solver &src) = delete;

 public:
  Solver(const ReadOptions &r_opt, const algo::Algo &a_opt, const WriteOptions &w_opt);
  ~Solver() {};
  void solveMaze(int y, int x);

 private:
  std::unique_ptr<ReadBase> read;
  std::unique_ptr<AlgoBase> algo;
  std::unique_ptr<WriteBase> writer;
};