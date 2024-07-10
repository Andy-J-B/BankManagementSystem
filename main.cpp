#include <iostream>
#include <string>

#include "BankManagement.h"
#include "Account.h"
#include "ExceededTryLimitException.h"
#include "Stack.h"
#include "Sqlite.h"
#include "WrongPasswordException.h"
#include "EmptyDataCollectionException.h"

using std::cin;
using std::cout;

int main() {
    // Constant variables
    const char* DIR = R"(/Users/Andy_1/Downloads/code/programs/BankManagementSystem/ACCOUNTS.db)";

    // Ask user if they want to log in or sign up
    showLoginInstructions();

    // Create DB if it doesn't exist
    createDBUI(DIR);

    Account myAccount;
    Stack * myStack = nullptr;

    for (unsigned int i = 0; i < 5; i++) {
        // Get what user wants
        unsigned int loginOption = 0;
        cin >> loginOption;

        // Log in
        if (loginOption == 1) {
            // Login
            try {
                myAccount = Login(DIR);
            } catch (WrongPasswordException& anException) {
                // cout << anException.what();
                return 1;
            } catch (ExceededTryLimitException& anException) {
                // cout << anException.what();
                return 1;
            }


            break;


        }

        // Sign up
        else if (loginOption == 2) {
            // Sign up
            myAccount = Signup(DIR);

            break;
        }

        // Else again
        else {
            // If i == 4, exceeded number of tries
            if (i == 4) {
                exceededTryLimit();

                return 1;
            }

            // Otherwise error statement and try again
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            errorStatement();

        }
    }

    myStack = new Stack;

    // Make variable
    int transactionChoice = 0;

    // Start while loop
    while (transactionChoice != -1) {
        // Show user all instructions and what they can do
        showInstructions();

        // Get choice
        cin >> transactionChoice;

        // Do transaction
        // Save transaction (withdraw or deposit) in Stack
        if (transactionChoice == 1) {
            // Deposit
            float toBeAdded = 0.0;

            cout << "\nHow much do you want to deposit? >>";
            cin >> toBeAdded;

            myAccount.addToAccount(toBeAdded);

            myStack->push(toBeAdded);
        } else if (transactionChoice == 2) {
            // Withdraw
            float toBeRemoved = 0.0;

            cout << "\nHow much do you want to withdraw? >>";
            cin >> toBeRemoved;

            myAccount.removeFromAccount(toBeRemoved);

            myStack->push(toBeRemoved*-1);
        } else if (transactionChoice == 3) {
            // Check Balance
            myAccount.checkBalance();
        } else if (transactionChoice == 4) {
            // Close Account
            closeAccount();
            int areYouSure;
            cin >> areYouSure;

            if (areYouSure == 1) {
                // Yes
                try {
                    myAccount.checkPassword();
                    DeleteAccount(DIR, myAccount.getName(), myAccount.getEmail());
                    // Delete Stack
                    delete myStack;
                    myStack = nullptr;
                    exitProgram();
                    return 0;
                } catch (WrongPasswordException& anException) {
                    wrongPassword();
                    // Continue
                }
            } else if (areYouSure == 2) {
                // No
                // Continue
            } else {
                errorStatement();
            }
        } else if (transactionChoice == 5) {
            // Modify Account Details (Name, Email)
            try {
                // Change info
                myAccount.changeInfo();
            } catch (WrongPasswordException& anException) {
                // Wrong Password
                wrongPassword();
                // Continue
            }
        } else if (transactionChoice == 6) {
            // Modify Account Password
            try {
                // Change info
                myAccount.changePassword(DIR);
            } catch (WrongPasswordException& anException) {
                // Wrong Password
                wrongPassword();
                // Continue
            }
        }else if (transactionChoice == 7) {
            // Undo
            try {
                undoTransaction();
                float lastTransaction = myStack->peek();
                myStack->pop();

                myAccount.addToAccount(lastTransaction);
            } catch (EmptyDataCollectionException& anException) {
                // Empty Stack
                emptyStack();

            }

        } else if (transactionChoice == 8) {
            // Exit if they want
            exitProgram();
            break;
        }
    }

    // Delete Stack
    delete myStack;
    myStack = nullptr;
    // Save Account
    UpdateAccount(DIR, myAccount.getEmail());
    // Exit program
    return 0;
}