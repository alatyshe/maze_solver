#include "other/additional.h"
#include "algo/AlgoManhattan.h"

AlgoBase* AlgoBase::createAlgoInstance(algo::Algo type) {
  AlgoBase *obj;
  switch(type) {
    case algo::MANHATTAN: 
      obj = new AlgoManhattan();
      break;
    case algo::BRUTEFORCE:
    default:
      throw std::runtime_error("invalid algo type width");
  }
  return obj;
}