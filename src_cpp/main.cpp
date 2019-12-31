#include "other/additional.h"
#include "other/Maze.h"

#include "other/Solver.h"
#include "parse/Parser.h"
#include "algo/AlgoManhattan.h"
#include "write/WriteFile.h"

int main(int argc, char *argv[]) {
  try {
    if (argc == 4) {
      std::string filename = argv[1];
      int x = std::stoi(argv[2]);
      int y = std::stoi(argv[3]);
      
      ReadOptions r_opt;
      r_opt.filename = filename;
      Solver sol(r_opt, algo::MANHATTAN, WriteOptions());
      sol.solveMaze(y, x);

    } else {
      std::cout << "Usage:" << std::endl
        << "\t./test file.txt x y" << std::endl;
    }
  } catch (std::exception &e) { 
    std::cout << e.what() << std::endl;
  }
  return 0;
}

