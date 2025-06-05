#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H

#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
#pragma once
using namespace std;
class Appointments{

protected:

    string Doc_spec[7]={"ENT","Internal medicine","General surgery","Dentistry","Dermatology","Physical medicine","Gynecology"},
    slot,Doc_name;

public:

int select_spec();
string select_doc(int spec_num);
void make_app(string Doc_name);

};
#endif // APPOINTMENTS_H
