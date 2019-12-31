#pragma once

#include "other/additional.h"
#include "write/WriteOptions.h"

class WriteBase {
 private:
  WriteBase(WriteBase &source) = delete;
  WriteBase &operator=(const WriteBase &source) = delete;

 public:
  explicit WriteBase(const WriteOptions &opt) : _opt(opt) { };
  virtual ~WriteBase() { };
  // Factory
  static WriteBase* createWriteIstance(const WriteOptions &opt);

  virtual void recordResult(const std::vector<std::string> &solution) const = 0;

 protected:
  const WriteOptions &_opt;
};