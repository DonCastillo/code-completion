#include "FileReader.h"
#include <vector>
#include <filesystem>
#include <string>
#include <cctype>
#include <fstream>

namespace fs = std::filesystem;

std::vector<fs::path> FileReader::getNonEmptyFiles(std::string directory) {
  std::vector<fs::path> files;
  for (const fs::directory_entry &directory_entry : fs::recursive_directory_iterator(
      directory)) {
    if (directory_entry.exists() && directory_entry.is_regular_file()
        && !fs::is_empty(directory_entry.path())) {
      files.push_back(directory_entry.path());
    }
  }
  return files;
}

std::string FileReader::getFileContent(fs::path filePath) {
  std::string output;
  std::ifstream file(filePath);

  if (file.is_open()) {
    char c;
    while (file.get(c)) {
      if (c != '\t' && c != '\n')
        output.push_back(c);
    }
  }
  return output;
}
