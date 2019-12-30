#pragma once

#include "other/additional.h"

struct ReadOptions {
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