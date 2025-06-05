#include "Medical_info.h"
using namespace std;
// Setters
void Medical_info::set_sugar_level(double sl) {
    sugar_level = sl;
}

void Medical_info::set_oxygen_level(double ol) {
    oxygen_level = ol;
}

void Medical_info::set_pressure(double pres) {
    pressure = pres;
}

void Medical_info::set_weight(double w) {
    weight = w;
}

void Medical_info::set_height(double h) {
    height = h;
}

void Medical_info::set_chronic_illnesses(string& ci) {
    chronic_illnesses = ci;
}

void Medical_info::set_previous_surgeries(string& ps) {
    previous_surgeries = ps;
}

void Medical_info::set_blood_type(string& bt) {
    blood_type = bt;
}

void Medical_info::set_medication_list(string& ml) {
    medication_list = ml;
}

// Getters
double Medical_info::get_sugar_level()  {
    return sugar_level;
}

double Medical_info::get_oxygen_level()  {
    return oxygen_level;
}

double Medical_info::get_pressure()  {
    return pressure;
}

double Medical_info::get_weight()  {
    return weight;
}

double Medical_info::get_height()  {
    return height;
}

string Medical_info::get_chronic_illnesses()  {
    return chronic_illnesses;
}

string Medical_info::get_previous_surgeries()  {
    return previous_surgeries;
}

string Medical_info::get_blood_type()  {
    return blood_type;
}

string Medical_info::get_medication_list()  {
    return medication_list;
}
