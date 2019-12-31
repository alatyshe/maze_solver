#include "other/additional.h"
#include "write/WriteFile.h"

WriteBase* WriteBase::createWriteIstance(const WriteOptions &opt) {
  WriteBase *obj;
  switch(opt.output_type) {
    case write::FILE:
      obj = new WriteFile(opt);
      break;
    case write::OUTPUT:
    case write::SERVER:
    default:
      throw std::runtime_error("invalid output type");
  }
  return obj;
}