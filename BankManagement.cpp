/* 
 * BankManagement.cpp
 *
 * Description: Methods used for User Interface of the Bank Management System
 *
 * Author: Andy Bae
 * Date: June 2024
 */
 
#include <iostream>
#include <string>

// include BankManagement.h
#include "BankManagement.h"

using std::cout;
using std::cin;

void showBanner() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";
}

void undoTransaction() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t::UNDOING TRANSACTION::\n";
}

void showLoginInstructions() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t    ::OPTIONS::\n";
  cout << "\n\t\t1. LOGIN";
  cout << "\n\t\t2. SIGN UP";
  cout << "\n\n   CHOOSE AND INPUT A NUMBER\n >>";
}

void showChangeInstructions() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t    ::OPTIONS::\n";
  cout << "\n\t\t1.CHANGE NAME";
  cout << "\n\t\t2.CHANGE EMAIL";
}

void showInstructions() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t    ::MAIN MENU::\n";
  cout << "\n\t1. DEPOSIT AMOUNT";
  cout << "\n\t2. WITHDRAW AMOUNT";
  cout << "\n\t3. CHECK BALANCE";
  cout << "\n\t4. CLOSE ACCOUNT";
  cout << "\n\t5. MODIFY ACCOUNT";
  cout << "\n\t6. MODIFY PASSWORD";
  cout << "\n\t7. UNDO";
  cout << "\n\t8. EXIT";
  cout << "\n\n   CHOOSE AND INPUT A NUMBER\n >>";
}

void closeAccount() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t::CLOSING ACCOUNT::\n";
  cout << "\n\nARE YOU SURE YOU WANT TO CLOSE YOUR ACCOUNT?";
  cout << "\n\t1. YES";
  cout << "\n\t2. NO";
  cout << "\n\n   CHOOSE AND INPUT A NUMBER\n >>";
}

void errorStatement() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t      ::ERROR::\n";
  cout << "\n\tSORRY, COULDN'T UNDERSTAND WHAT YOU SAID.";
  cout << "\n\tPLEASE TRY AGAIN.\n\n  >>";
}

void exceededTryLimit() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t      ::ERROR::\n";
  cout << "\n\tEXCEEDED NUMBER OF TRIES LIMIT OF 5.";
  cout << "\n\tEXITING THE PROGRAM.\n\n  >>";
}

void wrongPassword() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t      ::ERROR::\n";
  cout << "\n\tWRONG PASSWORD.";
}

void emptyStack() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t   ::ERROR UNDOING::\n";
  cout << "\n   CANNOT UNDO: EMPTY STACK.\n";
}

void exitProgram() {
  cout << "\n\n\t======================\n";
  cout << "\tBANK MANAGEMENT SYSTEM";
  cout << "\n\t======================\n";

  cout << "\t::EXITING THE PROGRAM::\n";
  cout << "\n\tTHANK YOU HAVE A NICE DAY.";
}
