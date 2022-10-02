#include "FrequencyBased.h"
#include <string>
#include <vector>

void FrequencyBased::readData(std::string directory) {

}

std::vector<std::string>* FrequencyBased::getSuggestions(
    const std::string query) {

  std::vector < std::string > *suggestions;
  suggestions->push_back("string1");
  suggestions->push_back("string2");
  return suggestions;
}
