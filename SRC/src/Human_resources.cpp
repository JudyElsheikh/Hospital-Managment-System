#include "Human_resources.h"
#include "doctor.h"
#include <limits>
#include <string>
using namespace std;

void Human_Resources::createDoctorFile(doctor &p){
        ofstream myfile("Doctors.txt",ios::app);
        myfile.is_open();
        myfile << p.getuser()<<endl ;
        myfile << p.getpass()<< endl;
        myfile.close();
        string user= p.getuser() + ".txt";
        ofstream file;
        file.open(user, ios::out);
        file << p.getName() << endl;
        file << p.getspec() <<endl;
        file<< p.getjobtitle() << endl;
        file << p.getgender() << endl;
        file << p.getAdress() << endl;
        file << p.getmobileNum() << endl;
        file << p.getNationalId() << endl;
        file << p.getEmail() << endl;
        file << p.getsalary() << endl;
        file.close();
        string spec = p.getspec() + ".txt";
        ofstream specfile(spec,ios::app);
        specfile.is_open();
        specfile << p.getuser() << endl;
        specfile.close();
        specfile.close();}

void Human_Resources::createdoctorsched(doctor& p){
       fstream schedfile;
        string drschedule= "Dr. " + p.getName() + " schedule.txt";
        schedfile.open(drschedule,ios::out);
            for(int i=0; i<p.getsched()->WH; i++){
                if(p.getsched()->starthour < p.getsched()->endhour+1){
                p.getsched()->slots[i]=p.getsched()->starthour;
                p.getsched()->starthour++;}}
            for( int i=0; i<p.getsched()->ndays; i++){
                if(!p.getsched()->days[i].empty()){
                schedfile <<p.getsched()->days[i]<< endl;}}
            for( int i=0; i<p.getsched()->WH; i++){
                if (p.getsched()->slots[i]< p.getsched()->endhour){
                schedfile <<p.getsched()->slots[i]<< ":00"<< endl;}}
                //cout<<p.getsched()->ndays<<endl<<p.getsched()->WH;
        schedfile << p.getsched()->ndays-1 << endl;
        schedfile << p.getsched()->WH-1 << endl;
            for (int i = 0; i < p.getsched()->ndays-1; i++) {
                for (int j = 0; j < p.getsched()->WH-1; j++) {
                    schedfile << "Free" << endl;
                }
            }

        schedfile.close();
}


void Human_Resources::Add_Doctor(string& username)
    {
        int sal;
        string s,j,name,mobileNo,NID,email,address,BD,pass;
        char g;
        string Doc_spec[7]={"ENT","Internal medicine","General surgery","Dentistry","Dermatology","Physical medicine","Gynecology"};


        cout << "Enter Name: ";
        cin.ignore();
        getline(cin,name);

        cout << "Enter Mobile Number: ";
        cin >> mobileNo;
        while(mobileNo.length() != 11){
                        cout<< "Wrong input, please enter again: ";
                        cin>> mobileNo;
                    }

        cout << "Enter National ID: ";
        cin >> NID;
        while(NID.length() != 14 ){
                        cout<< "Wrong input, please enter again: ";
                        cin>> NID;
                    }

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter Address: ";
        cin.ignore();
        getline(cin,address);

        cout << "Enter Birthdate: ";
        cin >> BD;

        cout << "Enter Gender: ";
        cin >> g;
         while(g != 'M' && g != 'F'){
                         cout<< "Wrong input, please enter again: ";
                        cin>> g;
                    }
        cin.ignore();

        cout << "Enter a Specalization from the following: " << endl <<  "ENT,Internal medicine,General surgery,Dentistry,Dermatology,Physical medicine,Gynecology" << endl;

        getline(cin,s);
        bool flag=false;
        for(int i=0; i<7; i++){
            if(s== Doc_spec[i]){
                flag=true;
            break;}
        }
        while(flag==false){
            cout << "Wrong Specalization entered, Please try again: ";
            getline(cin,s);
            for(int i=0; i<7; i++){
            if(s== Doc_spec[i]){
                flag=true;
            break;}
        }
        }

        cout << "Enter Job Title: ";
        cin>>j;

        cout << "Enter Salary: ";
        cin >> sal;

        cout<<"Enter password of your new account: ";
        cin>> pass;
        doctor d(s,j,sal,name, mobileNo, NID, email, address,BD, g);
        d.setuser(username);
        d.ChangePassword(pass);
        createDoctorFile(d);
        int days_num;
        int SH,EH,WH;
        cout<<"enter number of working days: "<<endl;
        cin>>days_num;
        cout<<"enter starting hour: "<<endl;
        cin>>SH;
        cout<<"enter ending hour: "<<endl;
        cin>>EH;
        WH=EH-SH;
        d.getsched()->createsched(days_num+1,SH,EH);
        createdoctorsched(d);
    }
int Human_Resources::select_spec()
    {
        string Doc_spec[7]={"ENT","Internal medicine","General surgery","Dentistry","Dermatology","Physical medicine","Gynecology"};
        int counter=0,spec_num;
        for(int i=0;i<7;i++)
        {
            counter++;
            cout<<counter<<"-"<<Doc_spec[i]<<endl;
        }
        cout<<"enter number of specialization desired: "<<endl;
        cin>>spec_num;
        while(spec_num<1 || spec_num>7)
        {
            cout<<"please enter number between 1 and 7 to choose required specialization"<<endl;
            cin>>spec_num;
        }
        return spec_num;
    }
    void Human_Resources::Remove_Doctor()
    {
        string doc,username;
        int spec_num=select_spec();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"write doctor's name: ";
        cin>>doc;
        cout<<"write doctor's username: ";
        cin>>username;
        bool flag=false;
        string Doc_spec[7]={"ENT","Internal medicine","General surgery","Dentistry","Dermatology","Physical medicine","Gynecology"},Doc_name;
        fstream Myfile, Docfile,doctorsfile;
        string Myfile_name=Doc_spec[spec_num-1]+".txt";
        Myfile.open(Myfile_name,ios::in);
        doctorsfile.open("Doctors.txt",ios::in);
        while(!flag)
        {
                string line1,line2,Doc_filename,Doc_info_line;
                int counter_specfile=0,counter_doctorsfile=0;
                string line_counter1,line_counter2;
                if(Myfile.is_open())
                {
                    while(getline(Myfile,line_counter1))
                    {
                        counter_specfile++;
                    }
                }
                if(doctorsfile.is_open())
                {
                    while(getline(doctorsfile,line_counter2))
                    {
                        counter_doctorsfile++;
                    }
                }
                string* Spec_arr= new string[counter_specfile];
                string* doctors_arr=new string[counter_doctorsfile];
                Myfile.clear();
                Myfile.seekg(0,ios::beg);
                for(int i=0;i<counter_specfile;i++)
                {
                    getline(Myfile,Spec_arr[i]);
                }
                doctorsfile.clear();
                doctorsfile.seekg(0,ios::beg);
                for(int i=0;i<counter_specfile;i++)
                {
                    getline(Myfile,Spec_arr[i]);
                }
                Myfile.close();
                doctorsfile.close();
                bool removed=false;
                ofstream new_specfile;
                new_specfile.open(Myfile_name,ios::out);

                if(new_specfile.is_open()&&!removed)
                {
                    for(int i=0;i<counter_specfile;i++)
                    {
                        if(Spec_arr[i]!=username)
                        {
                            new_specfile<<Spec_arr[i]<<endl;
                        }
                    }
                }
                else
                {
                    removed=true;
                }
                removed=false;
                ofstream new_doctorsfile;
                new_doctorsfile.open("Doctors.txt",ios::out);
                if(new_doctorsfile.is_open()&&!removed)
                {
                    for(int i=0;i<counter_doctorsfile;i++)
                    {
                        if(doctors_arr[i]==username)
                        {
                            i++;
                        }
                        else if(doctors_arr[i]!=username)
                        {
                            new_doctorsfile<<doctors_arr[i]<<endl;
                        }
                    }
                }
                else{
                    removed=true;
                }

                    Doc_filename=username+".txt";
                    Docfile.open(Doc_filename,ios::in);
                    if (Docfile.is_open())
                    {
                        getline(Docfile,Doc_info_line);
                        Docfile.close();
                        if(Doc_info_line==doc)
                        {
                            flag=true;
                            int status = remove(Doc_filename.c_str());
                            string formatted_name = "Dr. " + doc + " schedule.txt";
                            int status2 = remove(formatted_name.c_str());
                            new_doctorsfile.close();
                            new_specfile.close();
                            break;
                        }
                    }

                }
            if(!flag)
            {
                cout<<"wrong name entered,enter again: "<<endl;
                cin>>doc;
            }

}
void Human_Resources::showDoctors()
    {
        int counter = 0;
        int spec_num=select_spec();
        string Doc_spec[7]={"ENT","Internal medicine","General surgery","Dentistry","Dermatology","Physical medicine","Gynecology"};
        fstream Myfile, Docfile;
        string Myfile_name = Doc_spec[spec_num - 1] + ".txt";
        Myfile.open(Myfile_name, ios::in);
        if (Myfile.is_open())
        {
            string line, Doc_filename, Doc_name;
            int counter = 0;
            while (getline(Myfile, line))
            {
                Doc_filename = line + ".txt";
                Docfile.open(Doc_filename, ios::in);
                if (Docfile.is_open())
                {
                    string Doc_info_line, Doc_name;
                    cout << ++counter << "- ";
                    for (int i = 0; i < 1; i++)
                    {
                        getline(Docfile, Doc_info_line);
                        cout <<"Dr. " <<Doc_info_line << endl;
                    }
                }
                Docfile.close();
            }
        }
    }
void Human_Resources::showPatients()
    {
        fstream PatientsFile;
        PatientsFile.open("Patients.txt", ios::in);
        if (PatientsFile.is_open())
        {
            string line;
            int lineNumber = 0,counter=0;
            while (getline(PatientsFile, line))
            {
                lineNumber++;
                if (lineNumber % 2 == 0)
                {
                    break;
                }
                    else{
                            counter++;
                            string filename = line + ".txt";
                            fstream patientFile;
                            patientFile.open(filename, ios::in);
                            if (patientFile.is_open())
                            {
                                string patientInfo;
                                if (getline(patientFile, patientInfo))
                                {
                                    cout << counter<<"- "<<patientInfo <<endl;
                                }
                                patientFile.close();
                    }
                }
            }

            PatientsFile.close();
        }
    }
