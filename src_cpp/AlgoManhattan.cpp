#include "algo/AlgoManhattan.h"

std::vector<std::string> AlgoManhattan::searchSolution(const Maze &maze_orig) const {
  int start_y = maze_orig.getY();
  int start_x = maze_orig.getX();
  mazeStatus::Status status;
  Maze maze_copy(maze_orig);
  int value = 1;

  // Will be used as exit in maze;
  maze_copy.setY(-1);
  maze_copy.setX(-1);
  maze_copy.setCellValue(start_y, start_x, value);
  // Fills the maze until we find a way out or completely fill all map
  // (which means that there is no exit).
  status = mazeStatus::MARK;
  while (status == mazeStatus::MARK) {
    status = mapMarking(maze_copy, value++);
  }
  if (status == mazeStatus::HAS_SOLUTION)
    return solution(maze_copy, start_y, start_x);
  else
    return impasse();
};

mazeStatus::Status AlgoManhattan::mapMarking(Maze &maze, int value) const {
  mazeStatus::Status status = mazeStatus::HAVENT_SOLUTION;

  for (int y = 0; y < maze.getHeight(); y++) {
    for (int x = 0; x < maze.getWidth(); x++) {
      if (maze.getCellValue(y, x) == value) {

        if (maze.isCoordValid(y, x-1) && maze.getCellValue(y, x-1) == I_EMPTY) {
          maze.setCellValue(y, x-1, value+1);
          status = mazeStatus::MARK;
        }
        if (maze.isCoordValid(y, x+1) && maze.getCellValue(y, x+1) == I_EMPTY) {
          maze.setCellValue(y, x+1, value+1);
          status = mazeStatus::MARK;
        }
        if (maze.isCoordValid(y-1, x) && maze.getCellValue(y-1, x) == I_EMPTY) {
          maze.setCellValue(y-1, x, value+1);
          status = mazeStatus::MARK;
        }
        if (maze.isCoordValid(y+1, x) && maze.getCellValue(y+1, x) == I_EMPTY) {
          maze.setCellValue(y+1, x, value+1);
          status = mazeStatus::MARK;
        }

        if (maze.isSolved(y, x)) {
          maze.setY(y);
          maze.setX(x);
          return mazeStatus::HAS_SOLUTION;
        }
      }
    }
  }
  return status;
};

std::vector<std::string> AlgoManhattan::solution(const Maze &maze, int y_start, int x_start) const {
  std::vector<std::string> steps;
  std::string step("");
  int y = maze.getY();
  int x = maze.getX();

  // We move from the exit to the starting coordinates
  while (x != x_start || y != y_start) {
    int best_value = INT_MAX;
    int current_value = 0;
    int tmp_y = y;
    int tmp_x = x;

    if (maze.isCoordValid(y-1, x)
        && maze.getCellValue(y-1, x) != I_WALL
        && maze.getCellValue(y-1, x) < best_value) {
      tmp_x = x;
      tmp_y = y-1;
      best_value = maze.getCellValue(y-1, x);
      step = "Down";
    }

    if (maze.isCoordValid(y+1, x)
        && maze.getCellValue(y+1, x) != I_WALL
        && maze.getCellValue(y+1, x) < best_value) {
      tmp_x = x;
      tmp_y = y+1;
      best_value = maze.getCellValue(y+1, x);
      step = "Up";
    }

    if (maze.isCoordValid(y, x-1)
        && maze.getCellValue(y, x-1) != I_WALL
        && maze.getCellValue(y, x-1) < best_value) {
      tmp_x = x-1;
      tmp_y = y;
      best_value = maze.getCellValue(y, x-1);
      step = "Right";
    }

    if (maze.isCoordValid(y, x+1)
        && maze.getCellValue(y, x+1) != I_WALL
        && maze.getCellValue(y, x+1) < best_value) {
      tmp_x = x+1;
      tmp_y = y;
      best_value = maze.getCellValue(y, x+1);
      step = "Left";
    }
    x = tmp_x;
    y = tmp_y;
    steps.push_back(step);
  }
  return stepsToCmd(steps);
};

std::vector<std::string> AlgoManhattan::impasse() const {
  std::vector<std::string> res;
  res.push_back("The maze has no way out");
  return res;
};



std::vector<std::string> AlgoManhattan::stepsToCmd(const std::vector<std::string> &steps) const {
  std::vector<std::string> commands;
  std::stringstream ss;
  std::string prev;

  int step_cntr = 0;
  int cmd_cntr = 1;
  if (!steps.empty())
    prev = *(steps.end()-1);
  for (auto curr = steps.end(); curr != steps.begin();) {
    --curr;
    if (prev != *curr || (curr == steps.begin() && ++step_cntr)) {
      
      ss << cmd_cntr << ". " << step_cntr;
      if (step_cntr == 1)
        ss << " step ";
      else 
        ss << " steps ";
      ss << prev << std::endl;
      commands.push_back(ss.str());

      step_cntr = 0;
      ++cmd_cntr;
      ss.str("");
    }
    ++step_cntr;
    prev = *curr;
  }
  ss.str("");
  ss << "Exit" << std::endl;
  commands.push_back(ss.str());

  return commands;
};


