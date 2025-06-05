#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
void createDoctorFile(doctor &p){
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

void createdoctorsched(doctor& p){
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

void openuserFile(string username){
    string user = username + ".txt";
    fstream myfile;
    myfile.open(user, ios::in);
    if (myfile.is_open()){
        string line;
        while(getline(myfile,line)){
            cout << line << endl;
    }
    myfile.close();
}}
void createpatientFile(Patient& p){
        ofstream myfile("Patients.txt",ios::app);
        myfile.is_open();
        myfile << p.getuser()<<endl ;
        myfile << p.getpass()<< endl;
        myfile.close();
        string user= p.getuser() + ".txt";
        ofstream file;
        file.open(user, ios::out);
        file << p.getName() << endl;
        file << p.getgender() << endl;
        file << p.getAdress() << endl;
        file << p.getmobileNum() << endl;
        file << p.getNationalId() << endl;
        file << p.getEmail() << endl;
        file.close();
}


#endif // FUNCTIONS_H_INCLUDED
