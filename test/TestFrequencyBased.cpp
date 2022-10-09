#include "FrequencyBased.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

// TEST(TestCircle, illegal) {
//   EXPECT_THROW(new Circle(0), invalid_parameter_error);
//   EXPECT_THROW(new Circle(-1), invalid_parameter_error);
//   EXPECT_THROW(new Circle(-127), invalid_parameter_error);
// }

TEST(TestFrequencyBased, result) {
  std::string directory = "./data/chess/src";
  FrequencyBased *freqBased = new FrequencyBased();
  freqBased->readData(directory);
  std::vector<std::string>* suggestions = new std::vector<std::string>();
  suggestions = freqBased->getSuggestions("getX");

  EXPECT_EQ("getX", suggestions->at(0));

  delete freqBased;
}
 

