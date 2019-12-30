#pragma once

#include "write/WriteBase.h"

class WriteFile : public WriteBase {
 private:
  WriteFile(WriteFile &source) = delete;
  WriteFile &operator=(const WriteFile &source) = delete;
 public:
  explicit WriteFile(const WriteOptions &opt) : WriteBase(opt) { };
  ~WriteFile() { };
 
  void recordResult(const std::vector<std::string> &solution) const {
    std::ofstream myfile (_opt.filename);
    if (myfile.is_open()) {
      for (auto &line: solution)
        myfile << line;
      myfile.close();
    } else {
      throw std::runtime_error("Unable to open file");
    }
  }
};