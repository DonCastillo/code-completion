#include "FrequencyBased.h"
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

//using std::filesystem::recursive_directory_iterator;
//using std::filesystem::is_regular_file;
namespace fs = std::filesystem;

std::vector<fs::path> FrequencyBased::getNonEmptyFiles(std::string directory) {
  std::vector<fs::path> files;
  for (const fs::directory_entry &directory_entry : fs::recursive_directory_iterator(
      directory)) {
    if (directory_entry.exists() && directory_entry.is_regular_file()
        && !fs::is_empty(directory_entry.path())) {
      std::cout << directory_entry.path() << std::endl;
      files.push_back(directory_entry.path());
    }
  }
  return files;
}

void FrequencyBased::readData(std::string directory) {

  std::cout << "Start reading the data " << directory << std::endl;
  getNonEmptyFiles(directory);


}

std::vector<std::string>* FrequencyBased::getSuggestions(
    const std::string query) {

  std::vector<std::string> *suggestions;
  suggestions->push_back("string1");
  suggestions->push_back("string2");
  return suggestions;
}
