#include "parse/Parser.h"


std::vector<std::string> Parser::parseMap(std::vector<std::string> &input, int y, int x) {
  std::vector<std::string> output;
  bool empty_line = false;
  int curr_width;
  int width = -1;
  int height = 0;

  auto line = std::begin(input);
  while (line != std::end(input)) {
    // clean whitespaces
    *line = regex_replace((*line), std::regex("(^[\\s]+)|([\\s]+$)"), "");

    curr_width = (*line).length();
    if (width == -1) {
      width = (*line).length();
    }

    if (curr_width != 0 && empty_line) {
      throw std::runtime_error("empty line in the middle");
    } else if (curr_width == 0) {
      line = input.erase(line);
      empty_line = true;
    } else if (!std::regex_match((*line), std::regex(INTEGERS))) {
      throw std::runtime_error("sytax error");
    } else if (width != curr_width) {
      throw std::runtime_error("invalid maze width");
    } else {
      output.push_back(*line);
      line++;
      height++;
    }
  }
  // Check start point
  if (y >= 0 && y < height
      && x >= 0 && x < width
      && output[y][x] == C_EMPTY) {
    return output;
  }
  throw std::runtime_error("Invalid start points: x, y");  
}