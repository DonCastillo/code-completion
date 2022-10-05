#include "FrequencyBased.h"
#include "FileReader.h"
#include "RegExp.h"
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cctype>
#include <map>

namespace fs = std::filesystem;

void FrequencyBased::appendFrequencies(std::map<std::string, int> &master,
                                       std::map<std::string, int> &toAppend) {
  for (const auto &row : toAppend) {
    std::string key = row.first;
    int value = row.second;

    auto search = master.find(key);
    if (search != master.end()) {
      master[key] = master[key] + toAppend[key];
    } else {
      master[key] = toAppend[key];
    }
  }
}

void FrequencyBased::readData(std::string directory) {
  std::map<std::string, int> totalFrequencies;
  std::map<std::string, int> methods1 { { "typeid", 5 }, { "getX", 4 }, {
      "getY", 6 }, { "pathClear", 1 } };
  std::map<std::string, int> methods2 { { "typeid", 2 }, { "getX", 1 }, {
      "isCheck", 1 }, { "Coordinate", 1 } };

  std::cout << "Start reading the data " << directory << std::endl;

  std::vector<fs::path> files = FileReader::getNonEmptyFiles(directory);
  fs::path firstFilePath = files[0];

  std::cout << "Reading file from source " << firstFilePath << std::endl;
  std::string output = FileReader::getFileContent(firstFilePath);

  std::vector<std::string> matches = RegExp::getMatchingMethodNames(output);
  // for(int i = 0; i < matches.size(); ++i) {
  //   std::cout << i + 1 << " " << matches[i] << std::endl; 
  // }
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);
  appendFrequencies(totalFrequencies, methods1);
  appendFrequencies(totalFrequencies, methods2);

  std::cout << "totalFrequencies:" << std::endl;
  for (const auto &row : totalFrequencies) {
    std::cout << row.first << ": " << row.second << std::endl;
  }

}

std::vector<std::string>* FrequencyBased::getSuggestions(
    const std::string query) {

  std::vector<std::string> *suggestions;
  suggestions->push_back("string1");
  suggestions->push_back("string2");
  return suggestions;
}

