#ifndef MEDICAL_INFO_H
#define MEDICAL_INFO_H
#include <iostream>
#include <string>
#include <fstream>
#include<set>
#include <iomanip>
#include <windows.h>
#pragma once
using namespace std;
class Medical_info {
private:
    double sugar_level;
    double oxygen_level;
    double pressure;
    double weight;
    double height;
    string chronic_illnesses;
    string previous_surgeries;
    string blood_type;
    string medication_list;

public:
    // Setters
    void set_sugar_level(double sugar_level);
    void set_oxygen_level(double oxygen_level);
    void set_pressure(double pressure);
    void set_weight(double weight);
    void set_height(double height);
    void set_chronic_illnesses(string& chronic_illnesses);
    void set_previous_surgeries(string& previous_surgeries);
    void set_blood_type(string& blood_type);
    void set_medication_list(string& medication_list);

    // Getters
    double get_sugar_level() ;
    double get_oxygen_level() ;
    double get_pressure() ;
    double get_weight() ;
    double get_height() ;
    string get_chronic_illnesses() ;
    string get_previous_surgeries() ;
    string get_blood_type() ;
    string get_medication_list() ;
};

#endif // MEDICAL_INFO_H
