#ifndef INCLUDE_FILEREADER_H_
#define INCLUDE_FILEREADER_H_

#include <vector>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class FileReader {
 public:
  FileReader() {
  }
  virtual ~FileReader() {
  }

  // returns a list of paths of nonempty files
  static std::vector<fs::path> getNonEmptyFiles(std::string directory);

  // read a file and output the content
  static std::string getFileContent(fs::path filePath);
};

#endif /* INCLUDE_FILEREADER_H_ */
