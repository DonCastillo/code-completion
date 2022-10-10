#include <vector>
#include <system_error>
#include <filesystem>
#include <string>
#include <cctype>
#include <fstream>
#include "FileReader.h"
#include "gtest/gtest.h"

TEST(TestFileReader, nonEmptyDirectory) {
  std::string directoryPath = "data/chess/src";
  std::vector<fs::path> files = FileReader::getNonEmptyFiles(directoryPath);

  EXPECT_EQ(15, files.size());
}

TEST(TestFileReader, emptyDirectory) {
  std::string directoryPath = "data/empty";
  std::vector<fs::path> files = FileReader::getNonEmptyFiles(directoryPath);

  EXPECT_EQ(0, files.size());
}

TEST(TestFileReader, blankFile) {
  std::string directoryPath = "data/blankfile";
  std::vector<fs::path> files = FileReader::getNonEmptyFiles(directoryPath);

  EXPECT_EQ(0, files.size());
}

TEST(TestFileReader, nonExistingDirectory) {
  std::string directoryPath = "data/nonexisting";
  EXPECT_THROW(FileReader::getNonEmptyFiles(directoryPath),
               std::filesystem::filesystem_error);
}

TEST(TestFileReader, existingFile) {
  std::filesystem::path directoryPath = "data/chess/src/Bishop.cpp";
  std::string output = FileReader::getFileContent(directoryPath);
  EXPECT_TRUE(!output.empty());
}

TEST(TestFileReader, blankFile) {
  std::filesystem::path directoryPath = "data/blankfile/sample.cpp";
  std::string output = FileReader::getFileContent(directoryPath);
  EXPECT_TRUE(output.empty());
}
