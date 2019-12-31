#include "other/Solver.h"

Solver::Solver(const ReadOptions &r_opt, const algo::Algo &a_opt, const WriteOptions &w_opt) : 
  read(ReadBase::createReadIstance(r_opt)),
  algo(AlgoBase::createAlgoInstance(a_opt)),
  writer(WriteBase::createWriteIstance(w_opt)) { }

void Solver::solveMaze(int y, int x) {
  std::vector<std::string> input = read->load();
  std::vector<std::string> source = Parser::parseMap(input, y, x);
  Maze maze(source, y, x);
  std::vector<std::string> solution = algo->searchSolution(maze);
  writer->recordResult(solution);
}