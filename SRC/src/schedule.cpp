#include "schedule.h"
using namespace std;
void schedule::createsched(int d, int sh,int eh){
        ndays=d;
        starthour=sh;
        endhour=eh;
        WH= (endhour - starthour)+1;
        days = new string[ndays];
        slots= new int[WH];

        for( int i=0; i<ndays; i++){
                getline(cin,days[i]);}
        for(int i=0; i<WH; i++){
            if(starthour < endhour+1){
            slots[i]=starthour;
            starthour++;}}

    }
    schedule::~schedule(){
    delete[] days;
    delete [] slots;}
