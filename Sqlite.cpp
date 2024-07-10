/*
* Sqlite.cpp
 *
 * Description: Methods used for CRUD methods to access database of Bank Management System
 *
 * Author: Andy Bae
 * Date: June 2024
 */

#include <sqlite3.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "BankManagement.h"
#include "Account.h"

// include Stack.h
#include "Sqlite.h"

#include "ExceededTryLimitException.h"
#include "WrongPasswordException.h"

// #include <__filesystem/operations.h>

using namespace std;
using namespace filesystem;
string accountData[5];

int createDBUI(const char* DIR) {
	return createDB(DIR);
}

static int createDB(const char* DIR)
{
	sqlite3* DB;

	unsigned int exit = 0;

	if (!filesystem::exists(DIR)) {
		exit = sqlite3_open(DIR, &DB);
		createTable(DIR);
	} else {
		exit = sqlite3_open(DIR, &DB);
	}

	sqlite3_close(DB);

	return 0;
}

static int createTable(const char* DIR)
{
	sqlite3 *DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS ACCOUNTS("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"ACCOUNTBALANCE	FLOAT(10,2) NOT NULL DEFAULT '0.00', "
		"NAME      CHAR(25) NOT NULL, "
		"EMAIL     CHAR(50) NOT NULL, "
		"PASSWORD  CHAR(50) NOT NULL); ";

	try
	{
		unsigned int exit = 0;
		exit = sqlite3_open(DIR, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

	return 0;
}

static int insertData(const char* DIR, string NAME, string EMAIL, string PASSWORD)
{
	sqlite3* DB;
	char* messageError;

	string sql("INSERT INTO ACCOUNTS (NAME, EMAIL, PASSWORD) VALUES('" + NAME + "', '" + EMAIL + "', '" + PASSWORD + "');");

	unsigned int exit = sqlite3_open(DIR, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in insertData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records inserted Successfully!" << endl;

	return 0;
}

static int updateData(const char* DIR, string ACCOUNTBALANCE, string NAME, string EMAIL, string ID)
{
	sqlite3* DB;
	char* messageError;

	string sql("UPDATE ACCOUNTS SET ACCOUNTBALANCE = "+ACCOUNTBALANCE+", NAME = '" + NAME + "', EMAIL = '" + EMAIL + "' WHERE ID = "+ID+"");

	int exit = sqlite3_open(DIR, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in updateData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records updated Successfully!" << endl;

	return 0;
}

static int updateData(const char* DIR, string PASSWORD, string ID)
{
	sqlite3* DB;
	char* messageError;

	string sql("UPDATE ACCOUNTS SET PASSWORD = '" + PASSWORD + "' WHERE ID = "+ID+"");

	int exit = sqlite3_open(DIR, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in updateData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records updated Successfully!" << endl;

	return 0;
}

static int deleteData(const char* DIR, string NAME, string EMAIL)
{
	sqlite3* DB;
	char* messageError;

	string sql = "DELETE FROM ACCOUNTS WHERE NAME = '" + NAME + "' AND '" + EMAIL + "';";

	int exit = sqlite3_open(DIR, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in deleteData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records deleted Successfully!" << endl;

	return 0;
}

static int selectData(const char* DIR, string ACCOUNT_NAME)
{
	sqlite3* DB;
	char* messageError;

	string sql = "SELECT * FROM ACCOUNTS WHERE NAME='"+ACCOUNT_NAME+"'OR EMAIL='"+ACCOUNT_NAME+"';";

	int exit = sqlite3_open(DIR, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records selected Successfully!" << endl;

	return 0;
}

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (unsigned int i = 0; i < 5; i++) {
		accountData[i] = string(argv[i]);
	}


	return 0;
}

Account Login(const char* DIR) {

	// Make variables
	string accountName;
	string password;
	unsigned int option = 0;

	cout << "\n\n\t======================\n";
	cout << "\tBANK MANAGEMENT SYSTEM";
	cout << "\n\t======================\n";

	for (unsigned int i = 0; i < 5; i++) {
		cout << "\t    ::LOGGIN IN::\n";
		cout << "\n\t1. NAME OR 2. EMAIL? \n>>";
		cin >> option;

		if (option == 1) {
			// Name
			cout << "\n\t\tNAME: ";
			cin >> accountName;
			selectData(DIR, accountName);
			break;
		}

		else if (option == 2) {
			// Email
			cout << "\n\t\tEMAIL: ";
			cin >> accountName;
			selectData(DIR, accountName);
			break;
		}

		// Else again
		else {
			// If i == 4, exceeded number of tries
			if (i == 4) {
				exceededTryLimit();

				// Throw
				throw ExceededTryLimitException("Exceeded Try Limit");
			}

			// Otherwise error statement and try again
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			errorStatement();

		}
	}
	// Check password
	cout << "\n\n\t    ::CHECKING PASSWORD::\n";
	cout << "\n\t\tINPUT YOUR PASSWORD >>";
	cin >> password;

	if (password != accountData[4]) {
		// Not the same password
		wrongPassword();
		cout << "\n\tEXITING THE PROGRAM.\n\n  >>";
		// Throw
		throw WrongPasswordException("Wrong Password");
	}

	Account myAccount(accountData[2], accountData[3], accountData[4]);

	return myAccount;


}

Account Signup(const char* DIR) {
	cout << "\n\n\t======================\n";
	cout << "\tBANK MANAGEMENT SYSTEM";
	cout << "\n\t======================\n";

	// Create variables
	string NAME; string EMAIL; string PASSWORD;

	// Sign in
	cout << "\t    ::SIGNING IN::\n";
	cout << "\n\t\tNAME? >>";
	cin >> NAME;
	cout << "\n\t\tEMAIL? >>";
	cin >> EMAIL;
	cout << "\n\t\tPASSWORD? >>";
	cin >> PASSWORD;

	int dataInserted = insertData(DIR, NAME, EMAIL, PASSWORD);

	Account myAccount(NAME, EMAIL, PASSWORD);

	return myAccount;
}

void DeleteAccount(const char* DIR, string NAME, string EMAIL) {
	cout << "\n\n\t======================\n";
	cout << "\tBANK MANAGEMENT SYSTEM";
	cout << "\n\t======================\n";

	// Sign in
	cout << "\t    ::DELETING ACCOUNT::\n";

	deleteData(DIR, NAME, EMAIL);

	return;
}

void UpdateAccount(const char* DIR, string EMAIL ) {
	selectData(DIR, EMAIL);

	updateData(DIR, accountData[1], accountData[2],accountData[3],accountData[0]);
}

void UpdatePassword(const char* DIR, string EMAIL, string PASSWORD ) {
	selectData(DIR, EMAIL);

	updateData(DIR, PASSWORD,accountData[0]);
}