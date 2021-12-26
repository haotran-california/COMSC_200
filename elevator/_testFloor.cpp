// c++ _testFloor.cpp Floor.cpp Panel.cpp

#include <iostream>
using namespace std;

#include "Floor.h"

struct Building
{
  static Floor floors[];
  static const int FLOORS;
};

Floor Building::floors[] = 
{
  Floor(-200, "Sub-basement", "B2"),
  Floor(-100, "Basement", "B1"),
  Floor(0, "First Floor", "1"), 
  Floor(100, "Second Floor", "2"),
  Floor(200, "Third Floor", "3"),
  Floor(305, "Fourth Floor", "4"),
  Floor(410, "Fifth Floor", "5")
}; 
const int Building::FLOORS = sizeof(floors) / sizeof(Floor);

int main()
{
  // test operator<<
  for (int f = 0; f < Building::FLOORS; f++)
    cout << Building::floors[f] << endl;
  
  // test operator()
  for (int f = 1; f < Building::FLOORS; f++)
  {
    if (Building::floors[f] < Building::floors[f - 1])
      cout << "operator() error!\n";    
  }
}