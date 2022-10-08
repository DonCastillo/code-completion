// Minimal source file that allows the pipeline to pass.

#include "FrequencyBased.h"
#include <string>
#include <iostream>

int main() {
  std::string directory = "./data/chess/src";
  FrequencyBased *freqBased = new FrequencyBased();
  freqBased->readData(directory);
  std::vector<std::string>* test = freqBased->getSuggestions("get");
 
  delete freqBased;
  return 0;
}