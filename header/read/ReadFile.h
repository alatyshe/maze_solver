#pragma once

#include "read/ReadBase.h"

class ReadFile: public ReadBase {
 private:
  ReadFile(ReadFile &source) = delete;
  ReadFile &operator=(const ReadFile &source) = delete;
 public:
  explicit ReadFile(const ReadOptions &opt) : ReadBase(opt) { };
  ~ReadFile() { };

  std::vector<std::string> load();
};
