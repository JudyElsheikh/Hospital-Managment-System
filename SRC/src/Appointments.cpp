#include "Appointments.h"
#
using namespace std;
int Appointments::select_spec()
{
    int counter=0,spec_num;
    cout<<"enter number of specialization desired: "<<endl;
    for(int i=0;i<7;i++)
    {
        counter++;
        cout<<counter<<"-"<<Doc_spec[i]<<endl;
    }
    cin>>spec_num;
    return spec_num;
}
string Appointments::select_doc(int spec_num)
{
    fstream Myfile, Docfile;
    int counter=0;
    string Myfile_name=Doc_spec[spec_num-1]+".txt";
    Myfile.open(Myfile_name,ios::in);
    if(Myfile.is_open())
    {
        string line,Doc_filename,Doc_name;;
        int counter=0;
        while(getline(Myfile,line))
        {
            Doc_filename=line+".txt";
            Docfile.open(Doc_filename,ios::in);
                if(Docfile.is_open())
                {
                    string Doc_info_line,Doc_name;
                    cout<<++counter<<"-";
                    for(int i=0;i<4;i++)
                    {
                        getline(Docfile,Doc_info_line);
                        cout<<Doc_info_line<<endl;

                    }
                }
        }
    }
    Docfile.close();
    string *DocNames= new string[counter];
    fstream newfile, dfile;
    string newfile_name=Doc_spec[spec_num-1]+".txt";
    newfile.open(newfile_name,ios::in);
    if(newfile.is_open())
    {
        int counterdoctors=0;
        string line,Doc_filename;
        while(getline(newfile,line))
        {
            Doc_filename=line+".txt";
            dfile.open(Doc_filename,ios::in);
                if(dfile.is_open())
                {
                    for(int i=0;i<1;i++)
                    {
                        string Doc_info_line;
                        getline(dfile,Doc_info_line);
                        DocNames[counterdoctors]=Doc_info_line;
                        counterdoctors++;
                        dfile.close();


                    }

                }
        }
    }

    bool flag= false;
    cout<<"write doctor's name: "<<endl;
    cin.ignore();
    getline(cin,Doc_name);
    for(int i=0; i<counter ; i++){
        if(Doc_name == DocNames[i]){
            flag= true;
        }}
    if(flag==true){
            return Doc_name;
        }
    else{
            cout << "Wrong name Entered, Please Enter a Valid name" << endl;
            cin.ignore();
            getline(cin,Doc_name);
            return Doc_name;}

    }

void Appointments::make_app(string Doc_name) {
    ifstream sched_file;
    string filename = "Dr. " + Doc_name + " schedule.txt";
    sched_file.open(filename);
    if (!sched_file) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    int line_count = 0;
    string line,str_days,str_hours;
    while (getline(sched_file, line)) {
        ++line_count;
    }
    sched_file.clear();
    sched_file.seekg(0, ios::beg);
    string day_line,hours_line;


for (int i = 0; i < line_count - 2; ++i) {
    getline(sched_file, line);
}

// Read the last two lines
getline(sched_file, str_days);
getline(sched_file, str_hours);
    // Convert the read strings to integers
    int days_num = stoi(str_days);
    int working_hours = stoi(str_hours);
    string* days = new string[days_num];
    string* times = new string[working_hours];
    string availability[days_num][working_hours];
    sched_file.clear();
    sched_file.seekg(0, ios::beg);
    for (int i = 0; i < days_num; i++) {
        if (!getline(sched_file, days[i])) {
            cout << "Error: Could not read day " << i + 1 << endl;
            return;
        }
    }

    for (int j = 0; j < working_hours; j++) {
        if (!getline(sched_file, times[j])) {
            cout << "Error: Could not read time slot " << j + 1 << endl;
            return;
        }
    }
    string line_availability;
for (int i = 0; i < days_num; ++i) {
    for (int j = 0; j < working_hours; ++j) {
        if (!getline(sched_file, availability[i][j])) {
            cout << "Error: Could not read availability for day " << i + 1 << " and slot " << j + 1 << endl;
            return;
        }
    }
}
    sched_file.close();

    int counter = 0,day_num, slot_num;
    string username;
    cout << "Choose from the Days available: " << endl;
    for (int j = 0; j < days_num; j++){ cout <<j+1<< "- " << days[j] << endl;}
    cout << "Enter the number of the day you would like to book a slot on :" << endl;
    cin >> day_num;
    cout << "The available slots are: " << endl;
    for (int i = 0; i < working_hours; i++) {cout << i+1 << "- " << times[i] << endl;}
    cout << "Enter the number of the slot you would like to book :" << endl;
    cin >> slot_num;
    cout<<"Enter your username: "<<endl;
    cin>>username;
    string words[3],word;

    istringstream lineStream(availability[days_num][slot_num]);
    string firstWord;
    lineStream >> firstWord;
    if (firstWord == "Booked") {
        cout << "Slot on " << days[days_num] << " at " << times[slot_num] << " is already booked." << endl;
        delete[] days;
        delete[] times;
        return;
    }
    availability[day_num - 1][slot_num - 1] = "Booked by "+username;
    string details =Doc_name + " on " + days[day_num - 1] + " at " + times[slot_num - 1];

    cout << "You have booked with Dr." << Doc_name << " on " << days[day_num - 1] << " at " << times[slot_num - 1] << endl;

    fstream sched_new;
    sched_new.open(filename,ios::out);
    for(int i=0;i<days_num;i++)
    {
        sched_new<<days[i]<<endl;
    }
    for(int i=0;i<working_hours;i++)
    {
        sched_new<<times[i]<<endl;
    }
    for(int i=0;i<days_num;i++){
        for(int j=0;j<working_hours;j++)
        {
            sched_new<<availability[i][j]<<endl;
        }
    }
    sched_new<<days_num<<endl;
    sched_new<<working_hours<<endl;
    sched_new.close();
    ofstream patient_file;
    string patient_filename = username + ".txt";
    patient_file.open(patient_filename, ios::app);
    if (patient_file.is_open()) {

        patient_file << details << endl;
        patient_file.close();
    } else {
        cout << "Error: Could not open file " << patient_filename << endl;

    }
    delete[] times;
    delete[] days;
}
