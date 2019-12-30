#pragma once

#include "other/additional.h"

class Maze {
 public:
  Maze();
  Maze(const Maze &src);
  Maze(std::vector<std::string> &source, int x, int y);

  Maze& operator=(const Maze& src);

  std::string info(bool displayMarkedMap=false) const;

  bool  isCoordValid(int y, int x) const;
  bool  isSolved(int y, int x) const;

  void  setCellValue(int y, int x, int value);
  void  setX(int val);
  void  setY(int val);

  int  getCellValue(int y, int x) const;
  int  getWidth() const;
  int  getHeight() const;
  int  getY() const;
  int  getX() const;

 private:
  int   height=0;
  int   width=0;
  int   y_coord=0;
  int   x_coord=0;
  std::vector<std::vector<int>> map;
};