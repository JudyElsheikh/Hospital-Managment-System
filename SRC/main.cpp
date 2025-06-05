#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
#include <limits>
#pragma once
#include "Appointments.h"
#include "doctor.h"
#include "labTech.h"
#include "Medical_info.h"
#include "Patient.h"
#include "schedule.h"
#include "User.h"
#include "Human_resources.h"


using namespace std;
int getCounterDr(){
    ifstream cfile("counter file.txt");
    string counterDrS;
    getline(cfile,counterDrS);
    int counterDrI = stoi(counterDrS);
    return counterDrI;

}
int getCounterP(){
    ifstream cfile("counter file.txt");
    string counterPS;
    getline(cfile,counterPS);
    getline(cfile,counterPS);
    int counterPI = stoi(counterPS);
    return counterPI;

}
int counterDr= getCounterDr() , counterP = getCounterP();
/*
void createDoctorFile(doctor &p){
        ofstream myfile("Doctors.txt",ios::app);
        myfile.is_open();
        myfile << p.getuser()<<endl ;
        myfile << p.getpass()<< endl;
        myfile.close();
        string user= p.getuser() + ".txt";
        ofstream file;
        file.open(user, ios::out);
        file << p.getName() << endl;
        file << p.getspec() <<endl;
        file<< p.getjobtitle() << endl;
        file << p.getgender() << endl;
        file << p.getAdress() << endl;
        file << p.getmobileNum() << endl;
        file << p.getNationalId() << endl;
        file << p.getEmail() << endl;
        file << p.getsalary() << endl;
        file.close();
        string spec = p.getspec() + ".txt";
        ofstream specfile(spec,ios::app);
        specfile.is_open();
        specfile << p.getuser() << endl;
        specfile.close();
        specfile.close();}

void createdoctorsched(doctor& p){
       fstream schedfile;
        string drschedule= "Dr. " + p.getName() + " schedule.txt";
        schedfile.open(drschedule,ios::out);
            for(int i=0; i<p.getsched()->WH; i++){
                if(p.getsched()->starthour < p.getsched()->endhour+1){
                p.getsched()->slots[i]=p.getsched()->starthour;
                p.getsched()->starthour++;}}
            for( int i=0; i<p.getsched()->ndays; i++){
                if(!p.getsched()->days[i].empty()){
                schedfile <<p.getsched()->days[i]<< endl;}}
            for( int i=0; i<p.getsched()->WH; i++){
                if (p.getsched()->slots[i]< p.getsched()->endhour){
                schedfile <<p.getsched()->slots[i]<< ":00"<< endl;}}
                //cout<<p.getsched()->ndays<<endl<<p.getsched()->WH;
        schedfile << p.getsched()->ndays-1 << endl;
        schedfile << p.getsched()->WH-1 << endl;
            for (int i = 0; i < p.getsched()->ndays-1; i++) {
                for (int j = 0; j < p.getsched()->WH-1; j++) {
                    schedfile << "Free" << endl;
                }
            }

        schedfile.close();
}
*/
void openuserFile(string username){
    string user = username + ".txt";
    fstream myfile;
    myfile.open(user, ios::in);
    if (myfile.is_open()){
        string line;
        while(getline(myfile,line)){
            cout << line << endl;
    }
    myfile.close();
}}
void createpatientFile(Patient& p){
        ofstream myfile("Patients.txt",ios::app);
        myfile.is_open();
        myfile << p.getuser()<<endl ;
        myfile << p.getpass()<< endl;
        myfile.close();
        string user= p.getuser() + ".txt";
        ofstream file;
        file.open(user, ios::out);
        file << p.getName() << endl;
        file << p.getgender() << endl;
        file << p.getAdress() << endl;
        file << p.getmobileNum() << endl;
        file << p.getNationalId() << endl;
        file << p.getEmail() << endl;
        file.close();
}
int main()
{
    int choice;
    cout<< "Welcome to El7a2ony Hospital" << endl;
    cout << "Are you A 1- Patient, 2- Doctor, 3- HR " << endl;
    cout << "Please enter your choice: " << endl;
    cin >> choice;
    while (choice<1 ||choice > 3){
            cout << "Wrong choice, Please Enter your choice again: " << endl;

            cin >> choice;}
    switch(choice){
        case 1:{
            int LorRchoice,counterLogin;
            cout << "Alf Salama 3alek" << endl;
            cout << "Do you want to 1- Login or 2- Register?" << endl;
            cin >> LorRchoice;
            while (LorRchoice<1 ||LorRchoice > 2){
                    cout << "Wrong choice, Please Enter your choice again: " << endl;
                    cin >> LorRchoice;}
            if(LorRchoice==1){
                string username, password;
                int action;
                cout << "Please Enter Username: " << endl;
                cin >> username;
                cout << "Please Enter Password: " << endl;
                cin >> password;
                fstream myfile;
                myfile.open("Patients.txt",ios::in);
                    if (myfile.is_open()){
                        string line;
                        while(getline(myfile,line)){
                            if (line==username)
                                counterLogin++;
                            if (line == password)
                            counterLogin++;
                    }}
                myfile.close();
                while (counterLogin < 2){
                    cout << "Error, Wrong Username or Password, Please Login Again." << endl;
                    cout << "Please Enter Username: " << endl;
                    cin >> username;
                    cout << "Please Enter Password: " << endl;
                    cin >> password;
                    }
                string user= username+".txt";
                string name,mobileNo,NID,email,adress,BD;
                char gender[2], type;
                ifstream pfile(user);
                if(pfile.is_open()){
                    getline(pfile,name);
                    pfile.getline(gender, 2);
                    getline(pfile,adress);
                    getline(pfile,mobileNo);
                    getline(pfile,NID);
                    getline(pfile,email);
                }

                Patient old(name,mobileNo,NID,email,adress,BD,gender[0]);


                cout<<"Do you want to\n" <<"1-Book an appoinment\n"<< "2-Show my appointments\n" << "3-Cancel my apppointment\n" << "4-Access Medical Information\n" << endl;
                cin>>action;
                while (action<1 ||action >4 ){
                    cout << "Wrong choice, Please Enter your choice again: " << endl;
                    cin >> action;}
                if (action==1){
                  old.bookAppointment();
                }
                else if(action==2){
                        old.show_my_app();}
                else if (action==3){
                    old.cancel_app();}
                else if(action==4){
                    old.access_medicalinfo();}


                        }
                if(LorRchoice==2){
                    string username = "Patient" + to_string(counterP);
                    string name,mobileNo,NID,email,adress,BD, password;
                    char gender;
                    cout << "Please Enter Name: ";
                    cin.ignore();
                     getline(cin,name);
                    cout << "Please Enter Mobile No: ";
                    cin >> mobileNo;
                    while(mobileNo.length() != 11){
                        cout<< "Wrong input, please enter again: ";
                        cin>> mobileNo;
                    }
                    cout << "Please Enter NID: ";
                    cin >> NID;
                    while(NID.length() != 14 ){
                        cout<< "Wrong input, please enter again: ";
                        cin>> NID;
                    }
                    cout << "Please Enter Email: ";
                    cin >> email;
                    cout << "Please Enter Address: ";
                    cin.ignore();
                    getline(cin,adress);
                    cout << "Please Enter Birth Date (DD/MM/YYYY): ";
                    cin >> BD;
                    cout << "Please Enter Gender (M/F): ";
                    cin >> gender;
                    while(gender != 'M' && gender != 'F'){
                         cout<< "Wrong input, please enter again: ";
                        cin>> gender;
                    }
                    Patient New(name,mobileNo,NID,email,adress,BD,gender);
                    New.setuser(username);
                    cout << "Your Username is: " << New.getuser() << endl;
                    cout << "Please set your Password: " << endl;
                    cin >> password;
                    New.ChangePassword(password);
                    createpatientFile(New);
                    cout << "We will now call our Lab Technichian Tarek to conduct your medical tests, And Take your medical history" << endl;
                    Sleep(2000);
                    labTech Tarek;
                    cout << "Hello I am Tarek and I will be your Lab technichian today" << endl;
                    Sleep(1000);
                    cout << "Tarek, Please enter the data for our new patient" << endl;
                    Tarek.createPatientMedicalinfo(New);
                    cout << "Your account was Created succesfully" << endl;
                    counterP++;
                    int action;
                    cout<<"Do you want to\n" <<"1-Book an appoinment\n"<< "2-Show my appointments\n" << "3-Cancel my apppointment\n" << "4-Access Medical Information\n" << endl;
                    cin>>action;
                    while (action<1 ||action >4 ){
                        cout << "Wrong choice, Please Enter your choice again: " << endl;
                        cin >> action;}
                    if (action==1){
                      New.bookAppointment();
                    }
                    else if(action==2){
                            New.show_my_app();}
                    else if (action==3){
                        New.cancel_app();}
                    else if(action==4){
                        New.access_medicalinfo();}


                }
                break;}


        case 2:{
            string username, password;
            int counterLogin2;
            int action;
                cout << "Please Enter Username: " << endl;
                cin >> username;
                cout << "Please Enter Password: " << endl;
                cin >> password;
                fstream myfile;
                myfile.open("Doctors.txt",ios::in);

                    if (myfile.is_open()){
                        string line;
                        while(getline(myfile,line)){
                            if (line==username)
                                counterLogin2++;
                            if (line == password)
                            counterLogin2++;
                    }}
                myfile.close();
                while (counterLogin2 < 2){
                    cout << "Error, Wrong Username or Password, Please Login Again." << endl;
                    cout << "Please Enter Username: " << endl;
                    //counterLogin-=2;
                    cin >> username;
                    cout << "Please Enter Password: " << endl;
                    cin >> password;
                    counterLogin2 = 0;
                    myfile.open("Doctors.txt", ios::in);
                    if (myfile.is_open()) {
                        string line;
                        while (getline(myfile, line)) {
                            if (line == username)
                                counterLogin2++;
                            if (line == password)
                                counterLogin2++;
                        }
                    }
                    myfile.close();
}


                cout<<"Do you want to \n"<<"1-Display Schedule\n"<<"2-Access Medical Information"<<endl;
                cin>>action;
                if(action==1){
                    string Name,line;
                    fstream dfile;
                    string Doc_filename=username+".txt";
                    dfile.open(Doc_filename,ios::in);

                        if (dfile.is_open()) {
                        if (getline(dfile, line)) {
                            Name = line;
                        }
                        dfile.close();
                    }

                    string user = "Dr. " + Name + " schedule.txt";

                    fstream myfile;
                    myfile.open(user, ios::in);
                        int line_count = 0;
                        string line2,str_days,str_hours;
                        while (getline(myfile, line2)) {
                            ++line_count;
                        }
                        cout<<"line count is: "<<line_count<<endl;
                        myfile.clear();
                        myfile.seekg(0, ios::beg);
                        string day_line,hours_line;

                        // Skip two lines after reading total days and working hours
                    for (int i = 0; i < line_count - 2; ++i) {
                        getline(myfile, line2); // Skip lines until the end of the file minus two lines
                    }

                    // Read the last two lines
                    getline(myfile, str_days);
                    getline(myfile, str_hours);
                        // Convert the read strings to integers
                        int days = stoi(str_days);
                        int hours = stoi(str_hours);


                string userDR = "Dr. " + Name + " schedule.txt";
                fstream ffile;
                    ffile.open(userDR, ios::in);
                    if (ffile.is_open()){
                        string line4;
                        cout << "Working Days:" << endl;
                        for(int i=0;i<days;i++){
                            if (getline(ffile, line4)) {
                            cout <<line4 << endl;
                            }}

                        cout << "Working Hours:" << endl;
                        for(int i=0;i<hours;i++){
                            getline(ffile, line4);
                            cout << "Slot " << i+1 << "->" << line4 << endl;
                            }

                        cout << "Slots Booked for the whole week:" << endl;
                        for(int i=0;i<hours*days;i++){
                            getline(ffile, line4);
                            cout << "Slot " << i+1 << " is " << line4<< endl;
                            }

    }
    ffile.close();
}
        if(action==2){
            string username;
            int counterp=0;
            cout << "Please enter the Patient's username: ";
            cin>>username;
            ifstream myfile("Patients.txt");

            if (myfile.is_open()) {
                        string line;
                        while (getline(myfile, line)) {
                            if (line == username){
                                counterp++;
                                break;}
                        }
                    }
            while(counterp<1){
            cout << "Error, Username wasn't found in registered patients." << endl;
                  cout << "Please Enter Username: " << endl;
                    cin >> username;
                    counterp = 0;
                    ifstream myfile("Patients.txt");
                    if (myfile.is_open()) {
                        string line;
                        while (getline(myfile, line)) {
                            if (line == username){
                                counterp++;
                                break;}

                        }
                    }



        }}
        break;}
           //string fileinfo = username + " info";
            //openuserFile(fileinfo);

    case 3 :{
                string username,password;
                int action;
                Human_Resources hr;
                cout << "Please Enter Username: " << endl;
                cin >> username;
                while(hr.get_Username()!=username && (hr.get_Password()!=password))
                {
                    cout<<"wrong username, please enter again"<<endl;
                    cin>>username;
                }
                cout << "Please Enter Password: " << endl;
                cin >> password;
                while(hr.get_Password()!=password)
                {
                    cout<<"wrong password, please enter again"<<endl;
                    cin>>password;
                }
                cout << "Welcome Back Alaa" << endl;
                cout<<"Do you want to "<<"\n"<<"1- Show current patients"<<endl<<"2- Show current doctors" <<endl<<
                "3- Edit Doctors"<<endl ;
                cin>>action;
                while (action<1 ||action >3 )
                {
                    cout << "Wrong choice, Please Enter your choice again: " << endl;
                    cin >> action;
                }
                if (action==1)
                {
                    hr.showPatients();

                }
                if (action==2)
                {
                    hr.showDoctors();
                }
                if (action==3)
                {
                    int editaction;
                    //either add or remove doctor
                    cout<<"Do you want to"<<"\n"<<"1- Remove Doctor "<<"\n"<<"2- Add Doctor "<<"\n";
                    cin>>editaction;
                    while (editaction<1 || editaction >2 )
                    {
                        cout << "Wrong choice, Please Enter number 1 or 2: " << endl;
                        cin >> editaction;
                    }

                    if(editaction==1)
                    {
                        hr.Remove_Doctor();
                    }
                    if (editaction==2)
                    {
                        string Username2 = "Dr" + to_string(counterDr);
                        hr.Add_Doctor(Username2);
                        counterDr++;

                    }
                }
                }}



    fstream cfile;
    cfile.open("counter file.txt", ios::out);
    if(cfile.is_open()){
    cfile << counterDr << endl;
    cfile << counterP << endl;}
    cfile.close();
    cout << "Changes were saved succesfully, Thank you for coming to El7a2ony Hospital" ;
    Sleep(3000);
    exit(0);

    }
