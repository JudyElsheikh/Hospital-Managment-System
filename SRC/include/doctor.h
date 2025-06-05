#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
#pragma once

#include "User.h"
#include "schedule.h"

using namespace std;

class doctor : public User {
protected:
    string specialization;
    string job_title;
    int salary;
    schedule* doctorSchedule;

public:
    doctor(string s,string j, int sal, string name, string mobileNo, string NID, string email, string adress, string BD, char g);
    string getspec();
    string getjobtitle();
    int getsalary();
    schedule* getsched();
    void access_medicalinfo(User p);
    void editjobtitle();
    ~doctor();
};

#endif
