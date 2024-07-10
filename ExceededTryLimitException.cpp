/*
 * EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when data collection is empty.
 *
 */
#include <iostream>
#include <string>
#include "ExceededTryLimitException.h"

using std::string;
// Constructor
ExceededTryLimitException::ExceededTryLimitException(const string& message):
logic_error(string("ExceededTryLimitException: ") + message) {}