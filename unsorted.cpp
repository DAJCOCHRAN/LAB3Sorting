#include "unsorted.h"

UnsortedType::UnsortedType()
{
  //description array of pointers
  point = new string[3];
  //description array of copy pointers
  copyPoint = new string[3];
  //date integer pointer
  pointI = new int[3];
  //copy date integer pointer
  copyPointI = new int[3];
  //size of pointers
  sizeOfPoint = 3;
  //actual size of elements in pointer
  sizeOfInfo = 1;
  //actual position of latest element in pointer
  posOfInfo = 0;
}
//Not in use
UnsortedType::UnsortedType(int size)
{
  point = new string[size];
  copyPoint = new string[size];
  pointI = new int[size];
  copyPointI = new int[size];
  sizeOfPoint = size;
  sizeOfInfo = 1;
  posOfInfo = 0;
}
//delete all pointers
UnsortedType::~UnsortedType()
{
  delete[] point;
  delete[] copyPoint;
  delete[] pointI;
  delete[] copyPointI;
  copyPoint = nullptr;
  point = nullptr;
  copyPointI = nullptr;
  pointI = nullptr;
}
//checks if position of pointer and pointer size are the same
bool UnsortedType::checkIfFull(int size)
{
  if (size == sizeOfPoint)
    return true;
  else
    return false;
}
//overloads object
string &UnsortedType::operator[](int index)
{
  if (index >= sizeOfPoint)
  {
    cout << "Array index out of bound, exiting..." << endl;
    exit(0);
  }
  return point[index];
}

void UnsortedType::PutItem(const Appointment &app)
{
  //initialy double pointer size
  int newSize = sizeOfPoint * 2;
  //immediately assign appointment description and date into dynamic pointer
  point[posOfInfo] = app.description;
  pointI[posOfInfo] = app.totalDate;
  // sortList();
  
  if (checkIfFull(sizeOfInfo) == true)
  {
    for (int i = 0; i < sizeOfPoint; i++)
    {
      copyPoint[i] = point[i];
      copyPointI[i] = pointI[i];
    }
    delete[] point;
    delete[] pointI;
    point = nullptr;
    pointI = nullptr;
    //create original pointers again
    point = new string[newSize];
    pointI = new int[newSize];

    for (int i = 0; i < sizeOfPoint; i++)
    {
      point[i] = copyPoint[i];
      pointI[i] = copyPointI[i];
    }

    sizeOfPoint = newSize;

    delete[] copyPoint;
    delete[] copyPointI;
    copyPointI = nullptr;
    copyPoint = nullptr;

    copyPointI = new int[newSize];
    copyPoint = new string[newSize];
    cout << "new array initialized!!!" << endl;
  }
  posOfInfo++;
  sizeOfInfo++;
}

void UnsortedType::printItems()
{
  //if no element exists
  if (posOfInfo == 0)
  {
    cout << "there are no appointments to be displayed" << endl;
    return;
  }
  //print entire pointer up to the existing element
  cout << "YYYYMMDD:description" << endl;
  for (int i = 0; i < posOfInfo; i++)
  {
    cout << pointI[i] << ":" << point[i] << endl;
  }
  return;
}

void UnsortedType::findItem()
{
  int date = 0;
  bool found = false;
  cout << "Find your appointment by date you booked" << endl;
  cout << "what was the date in YYYYMMDD" << endl;
  cin >> date;
  cin.clear();
  for (int i = 0; i < sizeOfInfo; i++)
  {
    //match exact date
    if (date == pointI[i])
    {
      cout << "Was this the appointment?" << endl;
      cout << pointI[i] << ":" << point[i] << endl;
      found = true;
    }
  }
  if (found == false)
  {
    cout << "Sorry no appointment was found" << endl;
  }
}

void UnsortedType::DeleteItem()
{
  bool confirm = false;
  //no items stored
  if (posOfInfo == 0)
  {
    cout << "you have no items to delete" << endl;
    return;
  }
  //simply delete item if it is the only one
  else if (posOfInfo == 1)
  {
    cout << "your one appointment will be deleted. Are you sure?" << endl
         << "any number for yes and 0 for no" << endl;
    cin.clear();
    cin >> confirm;
    if (confirm == true)
    {
      pointI[posOfInfo - 1] = 0;
      point[posOfInfo - 1] = "";
      posOfInfo--;
      sizeOfInfo--;
      return;
    }
  }
  //majority of the remaining code is the same as find function
  int date = 0;
  bool found = false;
  cout << "To delete your appointment, find it by using date you booked" << endl;
  cout << "what was the date in YYYYMMDD - ex:20190308" << endl;
  cin >> date;
  cin.clear();
  for (int i = 0; i < sizeOfInfo; i++)
  {
    if (date == pointI[i])
    {
      cout << "Was this the appointment?" << endl;
      cout << pointI[i] << ":" << point[i] << endl;
      //once appointment was found...
      found = true;
      cout << "Are you sure this is the appointment you want to delete?" << endl
           << "any number for yes and 0 for no" << endl;
      cin.clear();
      cin >> confirm;
      //confirmation to delete
      if (confirm == true)
      {
        //once located last pointer element to delete and adjust tracking vars
        if(i == posOfInfo){
          point[i] = "";
          pointI[i] = 0;
          posOfInfo--;
          sizeOfInfo--;
          return;
        }
        //backtrack elements by one element once element has been removed
        for (int j = i + 1; j < sizeOfInfo; j++)
        {
          point[j - 1] = point[j];
          pointI[j - 1] = pointI[j];
          //once were at last element position of pointer
          if (j = posOfInfo)
          {
            point[j] = "";
            pointI[j] = 0;
            posOfInfo--;
            sizeOfInfo--;
            return;
          }
        }
      }
      else
        return;
    }
  }
  //nothing found :(
  if (found == false)
  {
    cout << "Sorry no appointment was found" << endl;
  }
}

/* MY CODE THAT NEEDS WORK!!!!
void UnsortedType::sortList(){
  int stopPoint = 0;
  for(int i=0; i<sizeOfPoint; i++){
    if(pointI[posOfInfo] < pointI[i]){
      for(int j=i; j<sizeOfPoint; j++){
        //iterate remaining copy points
      copyPointI[j] = pointI[j];
      copyPoint[j] = point[j];
      }
      //insert last point to assorted point
      pointI[i] = pointI[posOfInfo];
      point[i] = point[posOfInfo]; 
      stopPoint = i + 1;
      break;
    }
  }
  //assign copy points back to original pointers
  for(int i=stopPoint; i<sizeOfPoint; i++){
    pointI[i] = copyPointI[i];
    point[i] = copyPoint[i];
  }
  delete[] copyPoint;
  delete[] copyPointI;
  copyPoint = nullptr;
  copyPointI = nullptr;

  copyPoint = new string[sizeOfPoint];
  copyPointI = new int[sizeOfPoint];

  cout << "sorted list is..." <<endl;
  for(int i=0; i<sizeOfInfo; i++){
    cout << point[i] << " STRING" << endl;
    cout << pointI[i] << " INT" << endl;
  }
}
*/

