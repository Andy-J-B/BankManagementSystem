/* 
 * Account.h
 *
 * Description: Account abstract data type
 *              Used to hold data of an account
 *
 * Author: Andy Bae
 * Date: June 2024
 */
 
#include <iostream>
#include <string>

#ifndef Account_H
#define Account_H

using std::string;

class Account {
    private:

    float accountBalance = 0.0;
    string name;
    string email;
    string password;

    public:
    // Default Constructor
    Account();

    // Constructor
    Account(string name, string email, string password);

    // Copy constructor
    Account(const Account&);

    // Destructor
    ~Account();

    // Overloaded assignment operator
    Account operator=(Account const & rhs);

    // Description: Adds money to the account balance
    // Time Efficiency: O(1)
    void addToAccount(float toBeAdded);

    // Description: Removes money from the account balance
    // Time Efficiency: O(1)
    void removeFromAccount(float toBeRemoved);

    // Description: Checks if password is right
    // Exceptions: Throws WrongPasswordException if the password is wrong
    // Time Efficiency: O(1)
    void checkPassword();

    // Description: Changes info (Name or Email)
    // Precondition: Password matches
    // Time Efficiency: O(1)
    void changeInfo();

    // Description: Changes Password
    // Precondition: Password matches
    // Time Efficiency: O(1)
    void changePassword(const char* DIR);

    // Description: Checks Balance
    // Postcondiiton: Account remains unchanged
    // Time Efficiency: O(1)
    void checkBalance() const;
    
    // Description: Get account balance
    // Postcondiiton: Account remains unchanged
    // Time Efficiency: O(1)
    float getAccountBalance() const;

    // Description: Get name
    // Postcondiiton: Account remains unchanged
    // Time Efficiency: O(1)
    string getName() const;

    // Description: Get email
    // Postcondiiton: Account remains unchanged
    // Time Efficiency: O(1)
    string getEmail() const;

};


#endif