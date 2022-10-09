#ifndef INCLUDE_REGEXP_H_
#define INCLUDE_REGEXP_H_

#include <string>
#include <regex>
#include <vector>

class RegExp {
 public:
  RegExp() {
  }
  virtual ~RegExp() {
  }

  /**
   * Uses regex to get method names from lines of code in string
   * @param lines lines to get method names from
   */
  static std::vector<std::string> getMethodNames(const std::string &lines);
};

#endif /* INCLUDE_REGEXP_H_ */
