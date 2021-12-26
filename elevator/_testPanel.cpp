// c++ _testPanel.cpp Panel.cpp

#include <iostream>
using namespace std;

#include "Panel.h"

int main()
{
  Panel p;
  p.addButton("1");
  p.addButton("2");
  p.addButton("3");
  p.addButton("4");
  if (p.areAnyLit()) cout << "\nERROR 1\n";
  if (p.isLit("2")) cout << "\nERROR 2\n";
  
  p.press("X");
  p.press("2");
  p.press("3");
  cout << "\nEXPECTED: [2][3]\n";
  cout << "ACTUAL:   " << p << endl;
  
  p.clear("Y");
  p.clear("2");
  cout << "\nEXPECTED: [3]\n";
  cout << "ACTUAL:   " << p << endl;
  
  cout << "\nEXPECTED: 3\n";
  cout << "ACTUAL:   " << p.getFirstLit() << endl;

  if (!p.areAnyLit()) cout << "\nERROR 3\n";
  if (p.isLit("2")) cout << "\nERROR 4\n";
  if (!p.isLit("3")) cout << "\nERROR 5\n";
}