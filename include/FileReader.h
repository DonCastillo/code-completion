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

    /**
   * Getting non empty files
   * @param directory directory of data
   * @return vector containing path of files 
   */
  static std::vector<fs::path> getNonEmptyFiles(std::string directory);

   /**
   * Reading file content
   * @param filepath file path to read
   * @return string of content from file
   */
  static std::string getFileContent(fs::path filePath);
};

#endif /* INCLUDE_FILEREADER_H_ */
