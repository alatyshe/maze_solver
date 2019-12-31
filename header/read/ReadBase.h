#pragma once

#include "other/additional.h"
#include "read/ReadOptions.h"

class ReadBase {
 private:
  ReadBase(ReadBase &source) = delete;
  ReadBase &operator=(const ReadBase &source) = delete;

 public:
  explicit ReadBase(const ReadOptions &opt) : _opt(opt) {};
  virtual ~ReadBase() { };
  // Factory
  static ReadBase* createReadIstance(const ReadOptions &opt);
  // Virtual
  virtual std::vector<std::string> load() = 0;
  
 protected:
  const ReadOptions &_opt;
};
