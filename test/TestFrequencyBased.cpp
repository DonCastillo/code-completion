#include "FrequencyBased.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestFrequencyBased, illegal) {
  std::string directory = "./data/chess/src";
  FrequencyBased *freqBased = new FrequencyBased();
  freqBased->readData(directory);
  std::vector<std::string> *suggestions = new std::vector<std::string>();

  EXPECT_THROW(freqBased->getSuggestions("ge"), input_too_small_error);

  delete freqBased;
  delete suggestions;
}

TEST(TestFrequencyBased, testSuggestion) {
  std::string directory = "./data/chess/src";
  FrequencyBased *freqBased = new FrequencyBased();
  freqBased->readData(directory);
  std::vector<std::string> *suggestions;
  suggestions = freqBased->getSuggestions("getX");

  EXPECT_EQ("getX", suggestions->at(0));

  suggestions = freqBased->getSuggestions("get");

  EXPECT_EQ(4, suggestions->size());
  EXPECT_EQ("getY", suggestions->at(1));

  delete freqBased;
  delete suggestions;
}

TEST(TestFrequencyBased, testAppend) {
  FrequencyBased *freqBased = new FrequencyBased();
  std::map<std::string, int> methods1 { { "typeid", 5 }, { "getX", 4 }, {
      "getY", 6 }, { "pathClear", 1 }, { "getX", 1 } };

  std::map<std::string, int> methods2 { { "typeid", 8 }, { "getX", 9 }, {
      "getY", 6 }, { "pathClear", 1 }, { "reload", 1 } };

  freqBased->appendFrequencies(methods1, methods2);

  EXPECT_EQ(5, methods1.size());
  EXPECT_EQ(13, methods1.at("typeid"));

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

