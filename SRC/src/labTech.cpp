#include "labTech.h"

using namespace std;

void labTech::createPatientMedicalinfo(Patient& p) {
    double sugar, oxygen, pressure, bmi, height, weight;
    string chronic_illnesses, previous_surgeries, blood_type, medication_list;
    string noticeSugar, noticeOxygen, noticePressure, noticeBMI;

    cout << "Enter sugar level: ";
    cin >> sugar;
    if (sugar < 0) {
        cout << "Invalid input, please try again" << endl;
        cin >> sugar;
    }
    if (sugar <= 10)
        noticeSugar = "Normal Level of sugar";
    else
        noticeSugar = "High Level of sugar, Risk of Diabetes, Action needs to be taken";

    cout << "Enter oxygen level: ";
    cin >> oxygen;
    if (oxygen < 0) {
        cout << "Invalid input, please try again" << endl;
        cin >> oxygen;
    }
    if (oxygen >= 95)
        noticeOxygen = "Normal Level of Oxygen";
    else
        noticeOxygen = "Low Level of oxygen, Risk occurs";

    cout << "Enter pressure: ";
    cin >> pressure;
    if (pressure < 0) {
        cout << "Invalid input, please try again" << endl;
        cin >> pressure;
    }
    if (pressure >= 80 && pressure <= 120)
        noticePressure = "Normal Level of Oxygen";
    else
        noticePressure = "Low Level of oxygen, Risk occurs";

    cout << "Enter weight: ";
    cin >> weight;
    if (weight < 0) {
        cout << "Invalid input, please try again" << endl;
        cin >> weight;
    }

    cout << "Enter height in meters: ";
    cin >> height;
    if (height < 0) {
        cout << "Invalid input, please try again" << endl;
        cin >> height;
    }

    cout << "Enter blood type: ";
    cin >> blood_type;
    if (blood_type != "A+" && blood_type != "A-" && blood_type != "AB+" && blood_type != "AB-" && blood_type != "B+" && blood_type != "B-" && blood_type != "O+" && blood_type != "O-") {
        cout << "Invalid input, please try again" << endl;
        cin >> blood_type;
    }
    bmi = weight / (height * height);
    if (bmi < 18.5) {
        noticeBMI = "Patient is underweight.";
    } else if (bmi >= 18.5 && bmi < 25) {
        noticeBMI = "Patient is normal weight.";
    } else if (bmi >= 25 && bmi < 30) {
        noticeBMI = "Patient is overweight.";
    } else {
        noticeBMI = "Patient are obese.";
    }

    cout << "Enter chronic illnesses: ";
    cin.ignore();
    getline(cin, chronic_illnesses);

    cout << "Enter previous surgeries: ";
    getline(cin, previous_surgeries);

    cout << "Enter medication list: ";
    getline(cin, medication_list);

    p.getMinfo()->set_blood_type(blood_type);
    p.getMinfo()->set_height(height);
    p.getMinfo()->set_weight(weight);
    p.getMinfo()->set_chronic_illnesses(chronic_illnesses);
    p.getMinfo()->set_previous_surgeries(previous_surgeries);
    p.getMinfo()->set_medication_list(medication_list);
    p.getMinfo()->set_oxygen_level(oxygen);
    p.getMinfo()->set_pressure(oxygen);
    p.getMinfo()->set_sugar_level(sugar);

    fstream infofile;
    string patient = p.getuser() + " info.txt";

    infofile.open(patient, ios::out);
    infofile << p.getMinfo()->get_blood_type() << endl;
    infofile << p.getMinfo()->get_height() << endl;
    infofile << p.getMinfo()->get_weight() << endl;
    infofile << p.getMinfo()->get_chronic_illnesses() << endl;
    infofile << p.getMinfo()->get_previous_surgeries() << endl;
    infofile << p.getMinfo()->get_medication_list() << endl;
    infofile << p.getMinfo()->get_oxygen_level() << endl;
    infofile << p.getMinfo()->get_pressure() << endl;
    infofile << p.getMinfo()->get_sugar_level() << endl;
    infofile << "Notices About the lab results:" << endl;
    infofile << noticeSugar << endl;
    infofile << noticeOxygen << endl;
    infofile << noticePressure << endl;
    infofile << "BMI is " << setprecision(4) << bmi << " , " << noticeBMI << endl;

    infofile.close();
}
