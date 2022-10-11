/**
 * @file Exceptions.h
 * @brief Handles exceptions
 */
#ifndef INCLUDE_EXCEPTIONS_H_
#define INCLUDE_EXCEPTIONS_H_

#include <stdexcept>

/**
 * Exception for an invalid size of query less than 3
 */
class input_error : public std::runtime_error {
 public:
  /**
   * @param errMessage An error message.
   */
  explicit input_error(const char *errMessage)
      :
      std::runtime_error(errMessage) {
  }
};

#endif  // INCLUDE_EXCEPTIONS_H_

