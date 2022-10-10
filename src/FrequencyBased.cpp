#include "FrequencyBased.h"
#include "FileReader.h"
#include "RegExp.h"
#include "Exceptions.h"
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
  std::vector<fs::path> files = FileReader::getNonEmptyFiles(directory);

  for (const auto &row : files) {
    std::string output = FileReader::getFileContent(row);
    std::map<std::string, int> words = countFrequencies(
        RegExp::getMethodNames(output));
    appendFrequencies(totalFrequencies, words);
  }

  std::vector<std::pair<std::string, int>> sortedFreq = sortFrequencies(
      totalFrequencies);

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

  for (const std::string &s : methods) {
    ++frequencies[s];
  }

  return frequencies;
}

std::vector<std::string>* FrequencyBased::getSuggestions(
    const std::string query) {

  if (query.size() < 3)
    throw input_error("Your input size must be greater than 2");

  std::vector<std::string> *suggestions = new std::vector<std::string>();

  for (const auto &row : database) {
    std::string word = row.first;
    int freq = row.second;

    const std::regex e("\\b" + query);
    std::smatch m;

    if (std::regex_search(word, m, e, std::regex_constants::match_default)) {
      const std::string freqString = word + ":" + std::to_string(freq);

      //exact match should be at top
      if (word == query) {
        suggestions->insert(suggestions->begin(), freqString);
      } else {
        suggestions->push_back(freqString);
      }
    }
  }

  return suggestions;
}
