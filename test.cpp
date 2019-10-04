#include <iostream>
#include <string>

using namespace std;

int main() {
   // current date/time based on current system
   string one = "one";
   int cube = 4;
   string cubestring = "";
   cubestring = to_string(cube);
   one.append(cubestring);

   cout << one;

}