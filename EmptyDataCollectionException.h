/*
 * EmptyDataCollectionException.h
 *
 * Class Description: Defines the exception that is thrown when the data collection is empty.
 *
 */
 
#ifndef EMPTY_DATA_COLLECTION_EXCEPTION_H
#define EMPTY_DATA_COLLECTION_EXCEPTION_H

#include <stdexcept>

using std::string;
using std::logic_error;

class EmptyDataCollectionException : public logic_error {
 
   public:
      // Constructor
      EmptyDataCollectionException(const string& message);
   
}; 
#endif