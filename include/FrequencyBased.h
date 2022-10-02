// Minimal source file for a placebo class that does nothing but allows the
// pipeline to pass.

#ifndef FREQUENCY_BASED_H_INCLUDED
#define FREQUENCY_BASED_CLASS_H_INCLUDED

#include "CodeCompletion.h"
#include <string>
#include <vector>

class FrequencyBased : public CodeCompletion {
 public:
  FrequencyBased() {
  }
  virtual ~FrequencyBased() {
  }

  /**
   * Read files in a given directory (and sub-directories)
   * to populate the code completion database.
   * @param directory Relative path to the directory.
   */
  void readData(std::string directory);

  /**
   * Return a
   * @param query A string with which to query the code completion system.
   * @return A pointer to an ordered list of suggestions for the query in descending order of
   * relevance. The maximum number of suggestions is 7.
   */
  std::vector<std::string>* getSuggestions(const std::string query);
};

#endif //FREQUENCY_BASED_H_INCLUDED
