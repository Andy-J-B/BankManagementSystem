/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 *              Used for undo functionality of the Bank Management System
 * Class Invariant: LIFO order
 *                  Top of Stack located at the Front of SHSL list.
 *
 * Author: Andy Bae
 * Date: June 2024
 */
 
#include <iostream>
#include <string>

#ifndef Stack_H
#define Stack_H

using std::string;

class Stack {

  private:

    class StackNode {
      public:
        float data;
        StackNode * next;
    };

    // Set head pointer
    StackNode* head;
 
  public:
    // Default Constructor
    Stack();

    // Destructor
    ~Stack();

    // Copy Constructor
    Stack(const Stack* rhs);

    // Overloaded operator =
    Stack operator=(Stack const& rhs);

    // Description: Removes the top element fom the stack
    // Precondition: Stack is not empty
    // Postcondition: StackNode located at top is deleted
    // Exceptions: Throws EmptyDataCollectionException if the linked list is empty
    // Time Efficiency: O(1)
    bool pop();

    // Description: Adds new element to top of the list
    // Postcondition: New StackNode with newElement is added to the end
    // Time Efficiency: O(1)
    void push(float newElement);

    // Description: returns true if stack is empty
    // Postcondition: Stack is unchanged
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Removes all element from stack
    // Postcondition: Stack is in the state when first constructed
    // Time Efficiency: O(n)
    void popAll();

    // Description: Returns the element at the top
    // Precondition: The Linked list is not empty
    // Postcondition: Stack is unchanged
    // Exceptions: Throws EmptyDataCollectionException if the linked list is empty
    // Time Efficiency: O(1)
    float peek() const;
    

};

#endif