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

  static std::vector<std::string> getMatchingMethodNames(
      const std::string &lines);
};

#endif /* INCLUDE_REGEXP_H_ */
