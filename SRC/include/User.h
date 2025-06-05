#ifndef USER_H
#define USER_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
using namespace std;

class User
{
protected:
	string Name, mobileNum, NationalId, Email, Adress, Username, Password, birthdate;
	char gender;
public:
	User(string, string, string , string , string , string , char ) ;
	void setuser(string);
	string getuser();
	string getpass();
	string getName();
    string getmobileNum();
    string getNationalId();
    string getEmail();
    string getAdress();
    char getgender();
	void ChangePassword(string) ;
	void ChangeMobile(string) ;



};

#endif // USER_H


