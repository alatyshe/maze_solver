#include "other/Maze.h"

Maze::Maze() : 
    height(0),
    width(0),
    y_coord(-1),
    x_coord(-1) {
}

Maze::Maze(const Maze &src) : 
    height(src.height),
    width(src.width),
    y_coord(src.y_coord),
    x_coord(src.x_coord),
    map(src.map) {
}

Maze::Maze(std::vector<std::string> &source, int x, int y) :
    x_coord(x),
    y_coord(y),
    height(source.size()) {  
  width = -1;
  for (std::string &line : source) {
    if (width == -1)
      width = line.length();
    // convert string line to int vector.
    int number;
    std::vector<int> tmp_int_line;
    for(char& c : line) {
      // convert char to int
      number = c - '0';
      number *= -1;
      tmp_int_line.push_back(number);
    }
    map.push_back(tmp_int_line);
  }
}

Maze& Maze::operator=(const Maze& src) {
  if (this == &src)
    return *this;
  height = src.height;
  width = src.width;

  y_coord = src.y_coord;
  x_coord = src.x_coord;

  map = src.map;
  return *this;
}

bool  Maze::isCoordValid(int y, int x) const { return (y >= 0 && x >= 0 && y < height && x < width); }
bool  Maze::isSolved(int y, int x) const { return (y == 0 || x == 0 || x == width-1 || y == height-1); }

void  Maze::setCellValue(int y, int x, int value) { map[y][x] = value; }

void  Maze::setX(int val) { x_coord = val; }
void  Maze::setY(int val) { y_coord = val; }

int  Maze::getCellValue(int y, int x) const { return map[y][x]; }
int  Maze::getWidth() const { return width; }
int  Maze::getHeight() const { return height; }
int  Maze::getY() const { return y_coord; }
int  Maze::getX() const { return x_coord; }




std::string Maze::info(bool displayMarkedMap) const {
  std::stringstream ss;
  ss << "Maze::info()" 
    << std::endl
    << "[width=" << width << "]"
    << "[height=" << height << "]"
    << std::endl << "Start position:" << std::endl
    << "[x=" << x_coord << "]"
    << "[y=" << y_coord << "]"
    << std::endl;
  ss << "Map:" << std::endl;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // WALL
      if (map[y][x] == -1) {
        ss << std::setw(2) << 0 << ' ';
      } else if (y == y_coord && x == x_coord) {
        ss << "\033[1;31m" << std::setw(2) << 1 << "\x1b[0m" << ' ';
      } else  {
        ss << std::setw(2) << 1 << ' ';
      }
    }
    ss << std::endl;
  }
  if (displayMarkedMap) {
    ss << "Marked map:" << std::endl;
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        // WALL
        if (map[y][x] == -1) {
          ss << "\033[1;30m" << std::setw(2) << map[y][x] << "\x1b[0m" << ' ';
        } else if (y == y_coord && x == x_coord) {
          ss << "\033[1;31m" << std::setw(2) << map[y][x] << "\x1b[0m" << ' ';
        } else  {
          ss << std::setw(2) << map[y][x] << ' ';
        }
      }
      ss << std::endl;
    }
  }
  return ss.str();
}