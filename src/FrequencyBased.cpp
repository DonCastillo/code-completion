#include "FrequencyBased.h"
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

using std::filesystem::recursive_directory_iterator;
using std::filesystem::is_regular_file;

void FrequencyBased::readData(std::string directory) {

  std::cout << "Start reading the data " << directory << std::endl;

  // scan directories and subdirectories
  for (const auto &file : recursive_directory_iterator(directory)) {
    std::cout << file.path() << std::endl;
    std::cout << is_regular_file(file.path()) << std::endl;

  }

}

std::vector<std::string>* FrequencyBased::getSuggestions(
    const std::string query) {

  std::vector<std::string> *suggestions;
  suggestions->push_back("string1");
  suggestions->push_back("string2");
  return suggestions;
}
