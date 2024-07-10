/* 
 * Account.cpp
 *
 * Description: Account abstract data type
 *              Used to hold data of an account
 *
 * Author: Andy Bae
 * Date: June 2024
 */
 
#include <iostream>
#include <string>
#include <iomanip>

// include header files
#include "Account.h"
#include "Sqlite.h"
#include "BankManagement.h"
#include "WrongPasswordException.h"

// Use std methods
using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::setprecision;
using std::fixed;

// Default Constructor
Account::Account() {
    accountBalance = 0.0;
}

// Constructor
Account::Account(string name, string email, string password) {
    this->accountBalance = 0.0;
    this->name = name;
    this->email = email;
    this->password = password;
}

// Copy constructor does nothing
Account::Account(const Account&) {
    return;
}

Account::~Account() {
    accountBalance = 0.0;
    name = "";
    email = "";
    password = "";
}

// Overloaded assignment operator
Account Account::operator=(Account const & rhs) {
    accountBalance = rhs.accountBalance;
    name = rhs.name;
    email = rhs.email;
    password = rhs.password;

    return *this;
}

// Description: Adds money to the account balance
// Time Efficiency: O(1)
void Account::addToAccount(float toBeAdded) {
    accountBalance += toBeAdded;
    return;
}

// Description: Removes money from the account balance
// Time Efficiency: O(1)
void Account::removeFromAccount(float toBeRemoved) {
    accountBalance -= toBeRemoved;
    return;
}

// Description: Checks if password is right
// Exceptions: Throws WrongPasswordException if the password is wrong
// Time Efficiency: O(1)
void Account::checkPassword() {
    showBanner();
    string input;
    cout << "\t::CHECKING THE PASSWORD::\n";
    cout << "\nPLEASE ENTER YOUR PASSWORD";
    cin >> input;

    if(input != password) {
        throw WrongPasswordException("WRONG PASSWORD THROWN FOR CHANGE PASSWORD");
    }
    return;

}

// Description: Changes info (Name or Email)
// Precondition: Password matches
// Time Efficiency: O(1)
void Account::changeInfo() {
    checkPassword();
    showChangeInstructions();
    unsigned int option = 0;
    string changeValue;
    cin >> option;

    if (option == 1) {
        // Name
        showBanner();
        cout << "\t::CHANGING THE NAME::\n";
        cout << "\nPLEASE ENTER NEW NAME";
        cin >> changeValue;

        name = changeValue;
    } else if (option == 2) {
        // Email
        showBanner();
        cout << "\t::CHANGING THE EMAIL::\n";
        cout << "\nPLEASE ENTER NEW EMAIL";
        cin >> changeValue;

        email = changeValue;
    }
}

void Account::changePassword(const char* DIR) {
    // Password
    string changeValue;
    checkPassword();
    showBanner();
    cout << "\t::CHANGING THE PASSWORD::\n";
    cout << "\nPLEASE ENTER NEW PASSWORD";
    cin >> changeValue;

    password = changeValue;

    UpdatePassword(DIR, email, password);
}

// Description: Checks Balance
// Postcondiiton: Account remains unchanged
// Time Efficiency: O(1)
void Account::checkBalance() const {
    showBanner();

    cout << "\t::CHECKING ACCOUNT BALANCE::\n";
    cout << "\tYOU CURRENTLY HOLD : ";
    cout << fixed << setprecision(2) << accountBalance << "\n";
    return;
}

// Description: Get account balance
// Time Efficiency: O(1)
float Account::getAccountBalance() const {
    return accountBalance;
}

// Description: Get name
// Time Efficiency: O(1)
string Account::getName() const {
    return name;
}

// Description: Get email
// Time Efficiency: O(1)
string Account::getEmail() const {
    return email;
}