/*
* EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when data collection is empty.
 *
 */
#include <iostream>
#include <string>
#include "WrongPasswordException.h"

using std::string;
// Constructor
WrongPasswordException::WrongPasswordException(const string& message):
logic_error(string("WrongPasswordException: ") + message) {}
