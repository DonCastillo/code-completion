#include "RegExp.h"
#include <regex>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> RegExp::getMethodNames(
    const std::string &lines) {
  std::vector<std::string> finalMatches;

 // std::cout << "Inside getMatchingMethodNames" << std::endl;

  // select all statements with open-parentheses
  const std::regex PATTERN1("\\b(std::|::)?\\w{2,}(?=\\()");

  // select all statements starting with for, if, else, while, switch
  const std::regex PATTERN2("\\b(for|if|else|while|switch)\\b");

  // select all statements that has ::
  const std::regex PATTERN3("\\w*::");

  // select all statements that has std:: in the beginning
  const std::regex PATTERN4("\\bstd::");

  auto start = std::sregex_iterator(lines.begin(), lines.end(), PATTERN1);
  auto end = std::sregex_iterator();

  int index = 0;

  for (auto match = start; match != end; match++) {
    std::smatch m = *match;
    std::smatch c;
    // std::smatch v;

    std::string matchedString = m.str();

    // don't include if, else, while, for, switch
    if (std::regex_match(matchedString, c, PATTERN2)) {
      continue;
    }

    // don't include method definitions and retain std:: methods/constuctors
    if (std::regex_search(matchedString, c, PATTERN3)
        && !std::regex_search(matchedString, c, PATTERN4)) {
      continue;
    }

    finalMatches.push_back(matchedString);
  }
  return finalMatches;
}
