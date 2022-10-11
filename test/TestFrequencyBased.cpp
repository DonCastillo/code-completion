#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <regex>
#include "FrequencyBased.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestFrequencyBased, sortByVal) {
  std::pair<std::string, int> a = { "typeid", 3 };
  std::pair<std::string, int> b = { "getX", 4 };

  EXPECT_FALSE(FrequencyBased::sortByVal(a, b));
  EXPECT_TRUE(FrequencyBased::sortByVal(b, a));
}

TEST(TestFrequencyBased, sortFrequencies) {
  std::map<std::string, int> unsortedFreq { { "pathClear", 1 }, { "typeid", 4 },
      { "getX", 7 }, { "getY", 3 } };
  std::vector<std::pair<std::string, int>> sortedFreq;

  FrequencyBased *freqBased = new FrequencyBased();
  sortedFreq = freqBased->sortFrequencies(unsortedFreq);

  EXPECT_EQ("getX", sortedFreq.at(0).first);
  EXPECT_EQ(7, sortedFreq.at(0).second);

  EXPECT_EQ("pathClear", sortedFreq.at(3).first);
  EXPECT_EQ(1, sortedFreq.at(3).second);

  delete freqBased;
}

TEST(TestFrequencyBased, readData) {
  FrequencyBased *freqBased = new FrequencyBased();
  std::vector<std::pair<std::string, int>> database;
  freqBased->readData("data/sample");
  database = freqBased->database;
  EXPECT_TRUE(!database.empty());
  delete freqBased;
}

TEST(TestFrequencyBased, testAppend) {
  FrequencyBased *freqBased = new FrequencyBased();
  std::map<std::string, int> methods0;
  std::map<std::string, int> methods1 { { "typeid", 5 }, { "getX", 4 }, {
      "getY", 6 }, { "pathClear", 1 } };

  std::map<std::string, int> methods2 { { "typeid", 8 }, { "getX", 9 }, {
      "getY", 6 }, { "pathClear", 1 }, { "reload", 1 } };

  freqBased->appendFrequencies(methods0, methods1);
  freqBased->appendFrequencies(methods0, methods2);

  EXPECT_EQ(5, methods0.size());
  EXPECT_EQ(13, methods0.at("typeid"));
  EXPECT_EQ(1, methods0.at("reload"));

  delete freqBased;
}

TEST(TestFrequencyBased, testFrequencyCount) {
  FrequencyBased *freqBased = new FrequencyBased();
  std::vector<std::string> methods = { "typeId", "typeId", "reload",
      "pathClear", "typeId", "typeId", "toString" };

  std::map<std::string, int> methodCounts = freqBased->countFrequencies(
      methods);

  EXPECT_EQ(4, methodCounts.at("typeId"));

  delete freqBased;
}

TEST(TestFrequencyBased, illegal) {
  const std::string directory = "./data/chess/src";
  FrequencyBased *freqBased = new FrequencyBased();
  freqBased->readData(directory);

  EXPECT_THROW(freqBased->getSuggestions("ge"), input_error);
  EXPECT_THROW(freqBased->getSuggestions("g"), input_error);
  EXPECT_THROW(freqBased->getSuggestions(""), input_error);

  delete freqBased;
}

TEST(TestFrequencyBased, testSuggestion) {
  const std::string directory = "./data/chess/src";
  const std::regex PATTERN("\\b\\w{2,}(?=:)");
  std::vector<std::string> *suggestions;
  std::smatch c;

  FrequencyBased *freqBased = new FrequencyBased();
  freqBased->readData(directory);

  suggestions = freqBased->getSuggestions("getX");
  std::regex_search(suggestions->at(0), c, PATTERN);
  EXPECT_EQ("getX", c[0]);
  EXPECT_EQ(1, suggestions->size());

  suggestions = freqBased->getSuggestions("get");
  std::regex_search(suggestions->at(1), c, PATTERN);
  EXPECT_EQ("getY", c[0]);
  EXPECT_EQ(4, suggestions->size());

  delete freqBased;
  delete suggestions;
}

