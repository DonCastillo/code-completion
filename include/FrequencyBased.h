// Minimal source file for a placebo class that does nothing but allows the
// pipeline to pass.

#ifndef FREQUENCY_BASED_H_INCLUDED
#define FREQUENCY_BASED_CLASS_H_INCLUDED

#include "CodeCompletion.h"
#include <string>
#include <vector>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;

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
   * Return a vector of suggestions
   * @param query A string with which to query the code completion system.
   * @return A pointer to an ordered list of suggestions for the query in descending order of
   * relevance. The maximum number of suggestions is 7.
   */
  std::vector<std::string>* getSuggestions(const std::string query);



  /**
   * Combine maps contain freqencies
   * @param master main map to store into
   * @param toAppend the map to add to master
   * @return map of methods with their count
   */
  void appendFrequencies(std::map<std::string, int> &master,
                         std::map<std::string, int> &toAppend);



  /**
   * Count frquencies of methods in list
   * @param methods a vector of methods
   * @return map of methods with their count
   */
  std::map<std::string, int> countFrequencies(
      const std::vector<std::string> &methods);



  /**
   * Sort map from highest to lowest frequency count
   * @param frequencies map of methods with frequencies
   * @return sorted map of frequencies based on highest to lowest count
   */
  std::vector<std::pair<std::string, int>> sortFrequencies(
      const std::map<std::string, int> &frequencies);


  /**
   * Function used by sortFrequencies function to compare during sorting
   * @param a map of methods
   * @param b map of methods
   * @return whether a is greater than b
   */
  static bool sortByVal(const std::pair<std::string, int> &a,
                 const std::pair<std::string, int> &b);


  /**
   * Map of methods, sorted
   */
   std::vector<std::pair<std::string, int>> database;               
 
};

#endif //FREQUENCY_BASED_H_INCLUDED
