#include<string>
#include <iostream>
#include"appointment.h"
using namespace std;

class UnsortedType 
{
public:
  //CONSTRUCTOR
  UnsortedType();
  //CONSTRUCTOR IF WE WANT A CERTAIN SIZE 
  UnsortedType(int size); //NOT IN USE
  //DECONSTRUCTOR
  ~UnsortedType();
  //INDEX OPERATOR OVERLOAD
  string &operator[] (int index); //NOT IN USE
  // CHECKS IF POINTER STORAGE IS FULL, IF SO WE CREATE A NEW POINTER TO ALLOCATE MEMORY
  bool checkIfFull(int size);
  //STORES APPOINTMENT OBJECT INSIDE TWO POINTERS WHEN WE CREATE AN APPOINTMENT INSTANCE
  void PutItem(const Appointment & app);
  //DELETES THE APPOINTMENT OF 2 POINTER INDEXES OF DATE AND DESCRIPTION
  //DELETEITEM() WAS BUILT OFF OF FINDITEM()
  void DeleteItem();
  // SORTS THE ENTIRE LIST OF APPOINTMENTS
  //void sortList(); //NOT IN USE
  //LOCATES APPOINTMENT BASED ON DATE FORMAT INPUT
  void findItem();
//TO PRINT THE ENTIRE APPOINTMENT LIST
void printItems();

private:
  int sizeOfPoint;
  int posOfInfo;
  int sizeOfInfo;
  string *copyPoint;
  string *point;
  int *pointI;
  int *copyPointI;
  string info;
  int currentPos;
};