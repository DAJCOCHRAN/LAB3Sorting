#include "appointment.h"

Appointment::Appointment(){
    //INPUTS 
    year = 0;
    month = 0;
    day = 0;
    totalDate = 0;//FORMAT YYYYMMDD
    description = "";
}
bool Appointment::newAppointment(){
    //INPUT LOOP
    bool retry = true;
    while(retry){
    cout << "Please enter your appointment date (MM/DD/YYYY)" << endl << "Month?";
    cin.clear();
    cin >> month;
    cout << endl << "Day?";
    cin.clear();
    cin >> day;
    cout << endl <<"Year?";
    cin.clear();
    cin >> year;
    //CHECK APPOINTMENT CAN BE BOOKED
    totalDate = checkAppointment(month, day, year);
    //TOTAL DATE WILL BE 0 IF NOT BOOKED
    if (totalDate == 0){
        //PROMPT FOR RETRY APPOINTMNET
        if(prevSelect() == false)
            return false;
        }
        //NO NEED TO RETRY IF WE HAVE A VALID APPOINTMENT
    else if(totalDate != 0)
    retry = false;
    }
    cout << "The description for this appointment?" << endl;
    cin.ignore();
    getline(cin,description);
    cin.clear();
    printAppointment(month, day, year, description);
    //fullAppointment = to_string(totalDate) + ":" + description;
    return true;
}
void Appointment::printAppointment(int m, int d, int y, string desc)
{
    cout << "Appointment confirmation" << endl << "~-------------------------------------~" << endl;
    cout << m << "/" << d <<"/" << y << ":" << desc << endl << "~-------------------------------------~" << endl;;
}

int Appointment::checkAppointment(int m, int d, int y)
{ 
    int compYear = 0;
    int compMonth = 0;
    int compDay = 0;
    //used to compare dates and required data structure
    int reverseSum = 0;
    int compSum = 0;
    time_t now = time(0);
   //now is Number of sec since January 1,1970
   tm *ltm = localtime(&now);
    //pointer to access now in local time
   // print various components of tm structure.
   compYear = 1900 + ltm->tm_year;
   compMonth = 1 + ltm->tm_mon;
   compDay = ltm->tm_mday;

   if((m > 12 || m<= 0)||(d<=0 || d>= 31)||y<2019){
       cout << "Your date format is invalid!!" << endl;
       return 0;
   }
    compSum = compDay + (compMonth*100) + (compYear*10000);
    reverseSum = d + (m *100) + (y * 10000);

   if(compSum > reverseSum){
       cout << "your appoinment date is before today which is impossible to book" << endl;
       return 0;
   }
   else if(compSum == reverseSum){
       cout << "your appointment cannot be today" << endl;
    return 0;
   }
   else return reverseSum;
}

bool Appointment::prevSelect(){
    bool input = false;
    cout << "Would you like to go back to the main menu?" << endl 
    << "press any number to retry" << endl << "press 0 to return to main menu" << endl;
    cin.clear();
    cin >> input;
    switch(input){
        case 0: return false;
        case 1: return true;
    }
}
