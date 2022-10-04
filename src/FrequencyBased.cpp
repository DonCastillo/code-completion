#include "FrequencyBased.h"
#include "FileReader.h"
#include "RegExp.h"
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cctype>

namespace fs = std::filesystem;

void FrequencyBased::readData(std::string directory) {

  std::cout << "Start reading the data " << directory << std::endl;
  
  std::vector<fs::path> files = FileReader::getNonEmptyFiles(directory);
  fs::path firstFilePath = files[0];
  
  std::cout << "Reading file from source " << firstFilePath << std::endl;
  std::string output = FileReader::getFileContent(firstFilePath);

  RegExp::getMatches(output);


}

std::vector<std::string>* FrequencyBased::getSuggestions(
    const std::string query) {

  std::vector<std::string> *suggestions;
  suggestions->push_back("string1");
  suggestions->push_back("string2");
  return suggestions;
}

