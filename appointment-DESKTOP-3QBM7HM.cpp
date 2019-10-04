#include "appointment.h"
void Appointment::newAppointment()
{
    cout << "Please enter your appointment date (MM/DD/YYYY)" << endl;
    cin >> month;
    cout << "/";
    cin >> day;
    cout << "/";
    cin >> year;

    

}
void Appointment::outputAppointment()
{
}
void Appointment::compare()
{
}

bool Appointment::checkMonth(int m)
{
    if(m > 12 || m <= 0)
        return false;
        else return true;
}
bool Appointment::checkDay(int d)
{
    if(d < 0 || d > 31){
        return false;
    }
    else return true;
}
bool Appointment::checkYear(int y)
{
    //lets try to pull system time and take any appointment ahead of pulled system time
}
