#ifndef HUMAN_RESOURCES_H
#define HUMAN_RESOURCES_H
#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
#include <limits>
#pragma once

#include "doctor.h"
#include "Patient.h"
#include "Appointments.h"

using namespace std;

class Human_Resources
{
private:
   string User= "admin";
   string pas= "admin1234";
public:
    string get_Username(){return User;}
    string get_Password() {return pas;}
    void Add_Doctor(string &);
    int select_spec();
    void Remove_Doctor();
    void showDoctors();
    void showPatients();
    void createDoctorFile(doctor &p);
    void createdoctorsched(doctor &p);
};


#endif // HUMAN_RESOURCES_H
