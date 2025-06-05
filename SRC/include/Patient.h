#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
#pragma once

#include "User.h"
#include "Medical_info.h"
#include "Appointments.h"
using namespace std;
class Patient : public User {
private:
    Medical_info* Patient_info;
    Appointments Patient_Appointments;

public:
    Patient(string name, string mobileNo, string NID, string email, string adress, string BD, char g);
    void bookAppointment();
    void cancel_app();
    Medical_info * getMinfo(){return Patient_info;}
    void access_medicalinfo();
    void show_my_app();

};

#endif // PATIENT_H
