#include "other/additional.h"
#include "read/ReadFile.h"

ReadBase* ReadBase::createReadIstance(read::Read type, const ReadOptions &opt) {
  ReadBase *obj;
  switch(type) {
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