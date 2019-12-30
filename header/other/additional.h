#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

#include <iomanip>
#include <limits>

#include <string>
#include <vector>
#include <deque>
#include <regex>

// Maze Field defines 
// prefix C_ means char and used in input
#define C_WALL  '1'
#define C_EMPTY '0'
// prefix I_ means integer and used in maze 
#define I_WALL  -1
#define I_ROAD  0
#define I_EMPTY 0

// regexp
#define INTEGERS "([0-1]+)"

namespace mazeStatus {
  enum Status {
    HAVENT_SOLUTION,
    HAS_SOLUTION,
    MARK
  };
};

namespace direct {
  enum Direct {
    UP=1,
    DOWN,
    LEFT,
    RIGHT,
    FINISH,
    INVALID
  };
};

namespace read {
  enum Read {
    FILE=1,
    DATABASE,
    SERVER,
    GENERATOR
  };
};

namespace write {
  enum Write {
    FILE=1,
    OUTPUT,
    SERVER
  };
};

namespace algo {
  enum Algo {
    MANHATTAN=1,
    BRUTEFORCE
  };
};