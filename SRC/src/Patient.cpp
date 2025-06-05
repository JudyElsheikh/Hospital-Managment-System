#include "Patient.h"
#include "Appointments.h"
using namespace std;
Patient::Patient(string name, string mobileNo, string NID, string email, string adress, string BD, char g): User( name, mobileNo,  NID,  email, adress, BD, g){
          Patient_info = new Medical_info();}

void Patient::bookAppointment() {
        int spec_num = Patient_Appointments.select_spec();
        string doc_name = Patient_Appointments.select_doc(spec_num);
        Patient_Appointments.make_app(doc_name);
    }
void Patient::cancel_app()
    {
        string Doc_name,user_name;
        cout<<"Please enter your username to cancel your appointment: "<<endl;
        cin>>user_name;
        ifstream patientFile_info;
        string patientFile_name=user_name+".txt";
        patientFile_info.open(patientFile_name,ios::in);
        if(patientFile_info.is_open())
        {
            string line1;
            for(int i=0;i<6;i++)
            {
                getline(patientFile_info,line1);
            }
            int counter=1;
            while(getline(patientFile_info,line1))
            {
                cout<<counter<<"- Appointment with Dr. "<<line1<<endl;
                counter++;
            }

        cout<<"Enter the doctor's name: "<<endl;
        cin.ignore();
        getline(cin,Doc_name);
        ifstream sched_file;
        string filename = "Dr. " + Doc_name + " schedule.txt";
        sched_file.open(filename);
        int line_count = 0;
    string line2,str_days,str_hours;
    while (getline(sched_file, line2)) {
        ++line_count;
    }
    sched_file.clear();
    sched_file.seekg(0, ios::beg);
    string day_line,hours_line;

    // Skip two lines after reading total days and working hours
for (int i = 0; i < line_count - 2; ++i) {
    getline(sched_file, line2);
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

    int day_num, slot_num;
    cout << "When did you have the appointment? " << endl;
    for (int j = 0; j < days_num; j++){ cout <<j+1<< "- " << days[j] << endl;}
    cout << "Enter the day's number: " << endl;
    cin >> day_num;
    cout << "choose from the following hours: " << endl;
    for (int i = 0; i < working_hours; i++) {cout << i+1 << "- " << times[i] << endl;}
    cout << "Enter the hour's number: " << endl;
    cin >> slot_num;
    if (availability[day_num - 1][slot_num - 1]== "Free") {
        cout << "Slot not booked!" << endl;
        delete[] days;
        delete[] times;
        return;
    }
    sched_file.close();
    string words[3];
    string line = availability[day_num - 1][slot_num - 1];
    istringstream iss(line);
    int word_count = 0;
    while (iss >> words[word_count] && word_count < 3) {
        ++word_count;
    }
    if(words[2]==user_name)
    {
    availability[day_num - 1][slot_num - 1] = "Free";
    cout << "your appointment with Dr." << Doc_name << " on " << days[day_num - 1] << " at " << times[slot_num - 1] <<" is canceled."<<endl;

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
    int counter_lines = 0;
    ifstream patientFile;
    string patientfilename=user_name+".txt";
    patientFile.open(patientfilename, ios::in);
if (patientFile.is_open())
{
    string line_tocount;
    while (getline(patientFile,line_tocount))
    {
        counter_lines++;
    }

    // Reset file stream to read from the beginning
    patientFile.clear();
    patientFile.seekg(0, ios::beg);

    // Create an array to store file contents
    string *data_file = new string[counter_lines];
    string line_data;
    // Read lines from the file and store them in the array
    for (int i = 0; i < counter_lines; i++)
    {
        getline(patientFile, line_data);
        data_file[i]=line_data;
    }

    patientFile.close();
    string details=Doc_name+" on "+days[day_num-1]+" at "+times[slot_num-1];
    fstream new_patientfile;
    string new_patientname=user_name+".txt";
    new_patientfile.open(new_patientname,ios::out);
    if(new_patientfile.is_open())
    {
        for(int i=0;i<counter_lines;i++)
        {
            if(data_file[i]!=details)
                new_patientfile<<data_file[i]<<endl;
        }
    }
    new_patientfile.close();
    delete[] data_file;
}
else
{
    cout << "Error: Unable to open patient file." << endl;
}


    delete[] times;
    delete[] days;
        }
    }
}


void Patient::access_medicalinfo()
        {

                string user = Username + " info.txt";
                fstream myfile;
                myfile.open(user, ios::in);
                if (myfile.is_open()){
                    string line;
                    while(getline(myfile,line)){
                        cout << line << endl;
                }
                myfile.close();
            }}
void Patient::show_my_app()
{
    string user_name;
    cout << "Please enter your username to show your appointments: " << endl;
    cin >> user_name;
    ifstream patientFile_info;
    string patientFile_name = user_name + ".txt";
    patientFile_info.open(patientFile_name, ios::in);
    if (patientFile_info.is_open())
    {
        string line1;
        // Skip the first 6 lines
        for (int i = 0; i < 6; i++)
        {
            getline(patientFile_info, line1);
        }
        // Attempt to read the first appointment
        if (!getline(patientFile_info, line1))
        {
            cout << "You have no appointments." << endl;
            return;
        }
        else
        {
            int counter = 1;
            // Output the first appointment
            cout<<"Your appointments: "<<endl;
            cout <<"Appointment with Dr. " << line1 << endl;
            counter++;
            // Output the rest of the appointments
            while (getline(patientFile_info, line1))
            {
                cout<< "Appointment with Dr. " << line1 << endl;
                counter++;
            }
        }
    }
}
