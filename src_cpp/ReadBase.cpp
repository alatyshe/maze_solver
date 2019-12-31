#include "other/additional.h"
#include "read/ReadFile.h"

ReadBase* ReadBase::createReadIstance(const ReadOptions &opt) {
  ReadBase *obj;
  switch(opt.intput_type) {
    case read::FILE: 
      obj = new ReadFile(opt);
      break;
    case read::DATABASE:
    case read::SERVER:
    case read::GENERATOR:
    default:
      throw std::runtime_error("invalid read type");
  }
  return obj;
}