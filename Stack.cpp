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
// Include
#include <iostream>


// Include Stack.h
#include "Stack.h"

// Include exceptions
#include "EmptyDataCollectionException.h"


// Constructor
Stack::Stack(){
    // Set head to nullptr
    head = nullptr;
}

// Deconstructor
Stack::~Stack(){
    // Use popAll function
    popAll();
}

// Copy constructor
Stack::Stack(const Stack * rhs){

    // Check if rhs is empty
    if(rhs->isEmpty()) {
        // If it is empty
        // Set head to nullptr
        head = nullptr;
        // return
        return;
    }

    // Set a new oldCurrent to rhs's head
    StackNode *oldCurrent = rhs->head;

    // Set head to a new StackNode
    head = new StackNode;

    // Set a newCurrent to head
    StackNode *newCurrent = head;

    // Make newCurrent's data same as oldCurrent's data
    newCurrent->data = oldCurrent->data;

    // Set newCurrent's next to nullptr
    newCurrent->next = nullptr;

    // While the oldCurrent's next doesn't equal to nullptr
    while (oldCurrent->next != nullptr) {
        // traverse through rhs
        oldCurrent = oldCurrent->next;

        // Make newCurrent's next point to a new Stacknode
        newCurrent->next = new StackNode;

        // Traverse through newCurrent
        newCurrent = newCurrent->next;
        
        // Make newCurrent's data equal to oldCurrent's data
        newCurrent->data = oldCurrent->data;

        // Make newCurrent's next point to nullptr
        newCurrent->next = nullptr;
    }

    // return
    return;
}

// Overloaded operator
Stack Stack::operator=(Stack const& rhs) {
    // Popall
    popAll();

    // Set head to a new StackNode
    head = new StackNode;

    // Set a newCurrent to head
    StackNode *newCurrent = head;

    // Set a new oldCurrent to rhs's head
    StackNode *oldCurrent = rhs.head;

    // Make newCurrent's data same as oldCurrent's data
    newCurrent->data = oldCurrent->data;

    // Set newCurrent's next to nullptr
    newCurrent->next = nullptr;

    // While the oldCurrent's next doesn't equal to nullptr
    while (oldCurrent->next != nullptr) {
        // traverse through rhs
        oldCurrent = oldCurrent->next;

        // Make newCurrent's next point to a new Stacknode
        newCurrent->next = new StackNode;

        // Traverse through newCurrent
        newCurrent = newCurrent->next;
        
        // Make newCurrent's data equal to oldCurrent's data
        newCurrent->data = oldCurrent->data;

        // Make newCurrent's next point to nullptr
        newCurrent->next = nullptr;
    }

    return this;
}

// Description: Removes the top element fom the stack
// Precondition: Stack is not empty
// Postcondition: StackNode located at top is deleted
// Exceptions: Throws EmptyDataCollectionException if the linked list is empty
// Time Efficiency: O(1)
bool Stack::pop(){

    // Check if linked list is empty
    if (isEmpty()) {
        throw EmptyDataCollectionException("pop() called with an empty stack.");
    }

    // Else delete head 

    // Set current pointer to head's next
    StackNode * current = head->next;

    // Delete head
    delete head;

    // Set head to current
    head = current;

    // Return true
    return true;
}

// Description: Adds new element to top of the list
// Postcondition: New StackNode with newElement is added to the end
// Time Efficiency: O(1)
void Stack::push(float newElement){

    // Check if the linked list is empty
    if (isEmpty()) {
        // Set head to a new StackNode
        head = new StackNode;
        // Set head's data to newElement
        head->data = newElement;
        // Set head's next to nullptr
        head->next = nullptr;

        // return
        return;
    }

    // Set a newNode pointer to a new StackNode
    StackNode * newNode = new StackNode;

    // Set newNode's data to newElement
    newNode->data = newElement;

    // Set newNode's next to head's next
    newNode->next = head->next;

    // Set head's next to newNode
    head->next = newNode;

    // Return
    return;
}

// Description: returns true if stack is empty
// Postcondition: Stack is unchanged
// Time Efficiency: O(1)
bool Stack::isEmpty() const{

    // Check if head isn't nullptr
    if(head != nullptr) {
        // Return false if it isn't empty
        return false;
    } else {
        // Return true if it is empty
        return true;
    }
}

// Description: Removes all element from stack
// Postcondition: Stack is in the state when first constructed
// Time Efficiency: O(n)
void Stack::popAll(){

    // Check if the linked list is empty
    if (isEmpty()) {
        // Return
        return;
    }
    
    // Set a new toBeRemoved pointer to head
    StackNode * toBeRemoved = head;

    // While the head isn't a nullptr
    while (head != nullptr) {
        // Set head to the next StackNode
        head = toBeRemoved->next;

        // Delete toBeRemoved
        delete toBeRemoved;

        // Set toBeRemoved to head
        toBeRemoved = head;
    }

    // Return
    return;
}

// Description: Returns the element at the top
// Precondition: The Linked list is not empty
// Postcondition: Stack is unchanged
// Exceptions: Throws EmptyDataCollectionException if the linked list is empty
// Time Efficiency: O(1)
float Stack::peek() const{

    // Check if the Linked List is empty
    if(isEmpty()){
        throw EmptyDataCollectionException("peek() called with an empty stack.");
    }

    // Return the current's data
    return head->data;
}