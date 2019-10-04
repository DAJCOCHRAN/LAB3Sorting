#include"unsorted.h"
class Appointment{
    private:
    int year, month, day;
    string description;
    public:
    void newAppointment();
    void outputAppointment();
    void compare();
    bool checkMonth(int m);
    bool checkDay(int d);
    bool checkYear(int y);
};