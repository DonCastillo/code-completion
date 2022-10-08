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
#include <utility>
#include <algorithm>

namespace fs = std::filesystem;

bool FrequencyBased::sortByVal(const std::pair<std::string, int> &a,
               const std::pair<std::string, int> &b) {
  return a.second > b.second;
}

std::vector<std::pair<std::string, int>> FrequencyBased::sortFrequencies(
    const std::map<std::string, int> &frequencies) {

  std::vector<std::pair<std::string, int>> freqPair;
  for (const auto &row : frequencies) {
    freqPair.push_back(std::make_pair(row.first, row.second));
  }

  std::sort(freqPair.begin(), freqPair.end(), sortByVal);
  return freqPair;
}

void FrequencyBased::readData(std::string directory) {
  std::map<std::string, int> totalFrequencies;
 
  std::cout << "Start reading the data " << directory << std::endl;

  std::vector<fs::path> files = FileReader::getNonEmptyFiles(directory);
//  fs::path firstFilePath = files[3];
 


  std::string output;
  std::map<std::string, int> words;
  for (const auto &row : files) {
       output = FileReader::getFileContent(row);
       words = countFrequencies(RegExp::getMethodNames(output));
       appendFrequencies(totalFrequencies, words); 
  }
 

  std::cout << "totalFrequencies:" << std::endl;
  std::vector<std::pair<std::string, int>> sortedFreq = sortFrequencies(
      totalFrequencies);
  for (const auto &row : sortedFreq) {
    std::cout << row.first << ": " << row.second << std::endl;
  }

  database = sortedFreq;

}

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

std::map<std::string, int> FrequencyBased::countFrequencies(
      const std::vector<std::string> &methods) {
 

    std::map<std::string, int> frequencies;

    for(const std::string& s : methods) {
         ++frequencies[s];
    }

    //std::cout << frequencies["Coordinate"] << std::endl;
 
      
    return frequencies;
  }


std::vector<std::string>* FrequencyBased::getSuggestions(
    const std::string query) {

   // std::cout << query << ": " << database[0].first << ": " << database[0].second << std::endl;

  std::vector<std::string> *suggestions;
  suggestions->push_back("string1");
  suggestions->push_back("string2");
  return suggestions;
}

