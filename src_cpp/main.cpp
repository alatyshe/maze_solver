#include "other/additional.h"
#include "other/Maze.h"

#include "read/ReadFile.h"
#include "parse/Parser.h"
#include "algo/AlgoManhattan.h"
#include "write/WriteFile.h"
#include "other/Solver.h"

int main(int argc, char *argv[]) {
  try {
    if (argc == 4) {
      std::string filename = argv[1];
      int x = std::stoi(argv[2]);
      int y = std::stoi(argv[3]);
      // Read
      ReadOptions r_opt;
      r_opt.filename = filename;
      ReadBase *read = ReadBase::createReadIstance(read::FILE, r_opt);
      std::vector<std::string> input = read->load();
      // Parse
      std::vector<std::string> source = Parser::parseMap(input, x, y);
      Maze maze(source, x, y);
      // Solve
      AlgoBase *algorithm = AlgoBase::createAlgoInstance(algo::MANHATTAN);
      std::vector<std::string> solution = algorithm->searchSolution(maze);
      // Write
      WriteBase *writer = WriteBase::createWriteIstance(write::FILE, WriteOptions());
      writer->recordResult(solution);
    } else {
      std::cout << "Usage:" << std::endl
        << "\t./test file.txt x y" << std::endl;
    }
  } catch (std::exception &e) { 
    std::cout << e.what() << std::endl;
  }
  return 0;
}

