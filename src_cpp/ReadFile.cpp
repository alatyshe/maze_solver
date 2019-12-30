#include "read/ReadFile.h"

std::vector<std::string> ReadFile::load() {
  std::vector<std::string> result;
  std::ifstream filetoread;

  filetoread.open(_opt.filename);
  if (!filetoread) {
    throw std::runtime_error("Unable to open file");
  }
  while (filetoread) {
    std::string strInput;
    getline(filetoread, strInput);
    result.push_back(strInput);
  }
  filetoread.close();
  return result;
}