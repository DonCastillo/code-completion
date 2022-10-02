// Minimal source file that allows the pipeline to pass.

#include "FrequencyBased.h"
#include <string>
int main() {

  std::string directory = "./data/chess/src";
  FrequencyBased *freqBased = new FrequencyBased();
  freqBased->readData(directory);

  delete freqBased;
  return 0;
}
