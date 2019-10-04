#include<ctime>
#include<string>
#include<iostream>

using namespace std;

class Appointment{
    private:
    int year, month, day, totalDate;
    string description;
    
    public:
    //CONSTRUCTOR
    Appointment();
    //FILLS INSTANCE OF A NEW APPOINTMENT IN THE OBJECT
    bool newAppointment();
    //CONFIRMS THAT THE APPOINTMENT HAS BEEN BOOKED AND READY TO BE ADDED TO THE LIST OBJECT
    void printAppointment(int m, int d, int y, string desc);
    //CHECKS THAT THE APPOINTMENT IS A VALID DATE
    int checkAppointment(int m, int d, int y);
    //ALLOWS USER TO TRY TO MAKE A NEW APPOINTMENT AGAIN
    bool prevSelect();
    friend class UnsortedType;
};