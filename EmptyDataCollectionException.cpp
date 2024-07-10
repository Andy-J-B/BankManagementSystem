/*
 * EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when data collection is empty.
 *
 */
#include <iostream>
#include <string>
#include "EmptyDataCollectionException.h"  

using std::string;
// Constructor
EmptyDataCollectionException::EmptyDataCollectionException(const string& message): 
logic_error(string("EmptyDataCollectionException: ") + message) {}