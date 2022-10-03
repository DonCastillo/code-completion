#include "FrequencyBased.h"
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cctype>

//using std::filesystem::recursive_directory_iterator;
//using std::filesystem::is_regular_file;
namespace fs = std::filesystem;

std::string FrequencyBased::getFileContent(fs::path filePath) {
  std::string output;
  std::ifstream file(filePath);

  if (file.is_open()) {
    char c;
    while (file.get(c)) {
      if(c != '\t' && c != '\n') 
        output.push_back(c);
    }
  }
  return output;
}

void FrequencyBased::readData(std::string directory) {

  std::cout << "Start reading the data " << directory << std::endl;
  std::vector<fs::path> files = getNonEmptyFiles(directory);
  fs::path firstFilePath = files[1];
  std::cout << "Reading file from source " << firstFilePath << std::endl;
  std::string output = getFileContent(firstFilePath);
  std::cout << "Output is " << std::endl << output << std::endl;

}

std::vector<std::string>* FrequencyBased::getSuggestions(
    const std::string query) {

  std::vector<std::string> *suggestions;
  suggestions->push_back("string1");
  suggestions->push_back("string2");
  return suggestions;
}

std::vector<fs::path> FrequencyBased::getNonEmptyFiles(std::string directory) {
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
