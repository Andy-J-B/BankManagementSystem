/*
* DIRqlite.h
 *
 * Description: Methods used for CRUD methods to access database of Bank Management System
 *
 * Author: Andy Bae
 * Date: June 2024
 */
#include "Account.h"
#ifndef SQLITE_H
#define SQLITE_H

int createDBUI(const char* DIR);
static int createDB(const char* DIR);
static int createTable(const char* DIR);
static int deleteData(const char* DIR);
static int insertData(const char* DIR);
static int updateData(const char* DIR, string ACCOUNTBALANCE, string NAME, string EMAIL, string ID);
static int updateData(const char* DIR, string PASSWORD, string ID);
static int selectData(const char* DIR);
static int callback(void* NotUsed,  int argc, char** argv, char** azColName);
Account Login(const char* DIR);
Account Signup(const char* DIR);
void DeleteAccount(const char* DIR, string NAME, string EMAIL);
void UpdateAccount(const char* DIR, string EMAIL );
void UpdatePassword(const char* DIR, string EMAIL, string PASSWORD );


#endif //SQLITE_H
