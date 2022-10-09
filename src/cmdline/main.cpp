// Minimal source file that allows the pipeline to pass.

#include "FrequencyBased.h"
#include <string>
#include <iostream>
#include "Exceptions.h"

int main() {
  std::cout << "\nWelcome to Code Complete 1.0 by Don & Karamullah"
            << std::endl;
  std::cout << "Copyright © 2022\n\n" << std::endl;
  std::cout << "Type x or exit to end the program any time.\n\n" << std::endl;

  std::string directory = "./data/chess/src";
  FrequencyBased *freqBased = new FrequencyBased();
  freqBased->readData(directory);
  std::vector<std::string> *suggestions;

  std::string input;
  while (true) {
    std::cout << "Query:";
    std::cin >> input;

    if (input == "x" || input == "exit") {
      std::cout << "Program exit." << std::endl;
      break;
    }

    suggestions = freqBased->getSuggestions(input);

    for (std::vector<std::string>::iterator t = suggestions->begin();
        t != suggestions->end(); ++t) {
      std::cout << *t << std::endl;
    }
    std::cout << "\n" << std::endl;

  }

  delete freqBased;
  return 0;
}
