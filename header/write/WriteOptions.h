#pragma once

#include "other/additional.h"

struct WriteOptions {
  // params to result to File
  std::string filename = "result.txt";

  // params to result to Database
  // .....

  // params to result to server
  // .....

  WriteOptions() {
  }

  std::string info() const {
    std::stringstream ss;

    ss << filename << std::endl;
    return ss.str();
  }
};