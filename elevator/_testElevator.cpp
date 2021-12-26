// c++ _testElevator.cpp Elevator.cpp Floor.cpp Panel.cpp

#include <iostream>
using namespace std;

#include "Elevator.h"

struct Building
{
  static Elevator elevators[];
  static const int ELEVATORS;
};

Elevator Building::elevators[] =
{
  Elevator(20, 2, 0), // large slow elevator starting at floor index#0
  Elevator(12, 5, 1), // normal size/speed, starting at floor index#1
  Elevator(6, 15, 2) // small express speed, starting at floor index#1
};
const int Building::ELEVATORS = sizeof(elevators) / sizeof(Elevator);

int main()
{
  // test operator<<
  for (int e = 0; e < Building::ELEVATORS; e++)
    cout << Building::elevators[e] << endl;
  
  // test operator()
  for (int e = 1; e < Building::ELEVATORS; e++)
  {
    if (Building::elevators[e] < Building::elevators[e - 1])
      cout << "operator() error!\n";    
  }
}