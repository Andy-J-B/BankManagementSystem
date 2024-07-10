/*
 * ExceededTryLimitException.h
 *
 * Class Description: Defines the exception that is thrown when max tries reached.
 *
 */

#ifndef EXCEEDEDTRYLIMITEXCEPTION_H
#define EXCEEDEDTRYLIMITEXCEPTION_H

#include <stdexcept>

using std::string;
using std::logic_error;

class ExceededTryLimitException : public logic_error {

public:
    // Constructor
    ExceededTryLimitException(const string& message);

};

#endif //EXCEEDEDTRYLIMITEXCEPTION_H
