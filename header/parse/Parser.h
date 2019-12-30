#pragma once

#include "other/additional.h"
#include "other/Maze.h"

class Parser {
  Parser() = delete;
  ~Parser() = delete;
  Parser(Parser &source) = delete;
  Parser &operator=(const Parser &source) = delete;
  
public:
  static std::vector<std::string> parseMap(std::vector<std::string> &input, int x, int y);
};