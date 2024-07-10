/*
* ExceededTryLimitException.h
 *
 * Class Description: Defines the exception that is thrown when max tries reached.
 *
 */

#ifndef WRONGPASSWORDEXCEPTION_H
#define WRONGPASSWORDEXCEPTION_H



#include <stdexcept>

using std::string;
using std::logic_error;

class WrongPasswordException : public logic_error {

public:
 // Constructor
 WrongPasswordException(const string& message);

};




#endif //WRONGPASSWORDEXCEPTION_H