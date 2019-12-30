#pragma once

#include "read/ReadBase.h"
#include "algo/AlgoBase.h"
#include "write/WriteBase.h"


class Solver
{
 public:
  Solver(read::Read input_type, 
      algo::Algo algo_type, 
      write::Write output_type) {

  };
  ~Solver() {};

 protected:
  // std::unique_ptr<ReadBase>  reader;
  // std::unique_ptr<AlgoBase>  alogithm;
  // std::unique_ptr<WriteBase> writer;
};