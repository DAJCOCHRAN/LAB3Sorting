#include "unsorted.h"
void menuSelect(int &input);
int main()
{
    //MAIN CODE
    cout << "Welcome to Appointment Manager!!"<<endl;
    bool loop = true;
    int input = 0;
    UnsortedType k;
    Appointment t;
    while (loop)
    {
        menuSelect(input);
        switch (input)
        {
        case 1: 
            k.printItems();
            break;
        case 2:
            if(t.newAppointment() == true)
                k.PutItem(t);
                break;
        case 3: 
            k.findItem();
            break;
        case 4: 
            k.DeleteItem();
            break;
        case 5: 
            loop = false; 
            break;
        default: cout << "wrong selection" << endl;
        }
    }
    cout << "you're out of the loop" << endl;
    return 0;
}
//Menu printing 
void menuSelect(int &input)
{
    cout << "             MENU               " << endl;
    cout << "~------------------------------~" << endl;
    cout << "1: Display all appointments" << endl;
    cout << "2: Add new appointment" << endl;
    cout << "3: Search appointment" << endl;
    cout << "4: Delete Appointment" << endl;
    cout << "5: Quit the program" << endl;
    cout << "~------------------------------~" << endl;
    cin.clear();
    cin >> input;
}