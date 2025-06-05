#ifndef HUMAN_RESOURCES_H_INCLUDED
#define HUMAN_RESOURCES_H_INCLUDED
#include "doctor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <iomanip>
#include <windows.h>
#pragma once
using namespace std;
class Human_Resources
{
private:
   string User= "admin";
   string pas= "admin1234";
public:
    void Add_Doctor(string&);
    int select_spec();
    void Remove_Doctor();
    void showDoctors();
    void showPatients();
    void createDoctorFile(doctor&p);
    void createdoctorsched(doctor&p);
};


#endif // HUMAN_RESOURCES_H_INCLUDED
