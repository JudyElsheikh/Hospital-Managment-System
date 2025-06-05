#include "doctor.h"
using namespace std;
doctor::doctor(string s, string j, int sal, string name, string mobileNo, string NID, string email, string adress, string BD, char g)
    : User(name, mobileNo, NID, email, adress, BD, g) {
    specialization = s;
    job_title = j;
    salary = sal;
    doctorSchedule = new schedule();
}

string doctor::getspec() {
    return specialization;
}

string doctor::getjobtitle() {
    return job_title;
}

int doctor::getsalary() {
    return salary;
}

schedule* doctor::getsched() {
    return doctorSchedule;
}

void doctor::access_medicalinfo(User p) {
    string user = p.getuser() + " info.txt";
    fstream myfile;
    myfile.open(user, ios::in);
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            cout << line << endl;
        }
        myfile.close();
    }
}

void doctor::editjobtitle() {
    string j;
    cout << "enter changed job title" << endl;
    cin >> j;
    job_title = j;
}

doctor::~doctor() {
    delete doctorSchedule;
}
