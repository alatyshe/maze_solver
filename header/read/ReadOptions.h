#pragma once

#include "other/additional.h"

namespace read {
  enum Read {
    FILE=1,
    DATABASE,
    SERVER,
    GENERATOR
  };
};

struct ReadOptions {
  read::Read  intput_type = read::FILE;

  // params to Read maze from File
  std::string filename = "";

  // params to Read maze from Database
  // .....

  // params to Read maze from server
  // .....

  // params to Read maze from generator
  // .....

  ReadOptions() {
  }

  std::string info() const {
    std::stringstream ss;

    ss << filename << std::endl;
    return ss.str();
  }
};