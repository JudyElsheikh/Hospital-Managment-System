#ifndef LABTECH_H
#define LABTECH_H
#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
#include <limits>
#pragma once
#include "Patient.h"

using namespace std;
class labTech {
private:
    string Username = "labtech11", Password = "1234";

public:
    void createPatientMedicalinfo(Patient& p);
};

#endif // LABTECH_H
