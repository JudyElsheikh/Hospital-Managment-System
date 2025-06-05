#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
#pragma once
using namespace std;
class schedule {
public:
    int ndays, WH, starthour, endhour;
    string* days;
    int* slots;

    //schedule() : ndays(0), WH(0), starthour(0), endhour(0), days(nullptr), slots(nullptr) {}schedule() : ndays(0), WH(0), starthour(0), endhour(0), days(nullptr), slots(nullptr) {}
    void createsched(int d, int sh, int eh);
    ~schedule();
};

#endif // SCHEDULE_H
