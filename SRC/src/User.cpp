#include "User.h"
using namespace std;

User::User(string name, string mobileNo, string NID, string email, string adress, string BD, char g)
{
    {
		Name = name;
		mobileNum = mobileNo;
		NationalId = NID;
		Email = email;
		Adress = adress;
		birthdate = BD;
        gender = g;


		/*if (type == 'D') {
            counterDr++;
			Username = "Dr" + to_string(counterDr);
		}
		else if (type == 'P') {
		    counterP++;
			Username = "Patient" + to_string(counterP);

		}
		else
			cout << "You are not are not allowed to use our system, Please enter a valid type (D,P,N) " << endl;*/
	}
}
    void User::setuser(string user){Username=user;}
	string User:: getuser(){return Username;}
	string User::getpass(){return Password;}
	string User::getName(){return Name;}
    string User::getmobileNum(){return mobileNum;}
    string User::getNationalId(){return NationalId;}
    string User::getEmail(){return Email;}
    string User::getAdress(){return Adress;}
    char User::getgender(){return gender;}
	void User::ChangePassword(string pass) {Password = pass;}
	void User::ChangeMobile(string mob) {mobileNum = mob;}
//hUser::~User()
