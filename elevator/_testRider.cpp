// c++ _testRider.cpp Rider.cpp

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#include "Rider.h"

int main()
{
  Rider a(0, 1); // starting on floor #0, going to floor #1
  Rider b(1, 2); // starting on floor #1, going to floor #2

  queue<Rider> q;
  q.push(a);
  
  vector<Rider> v;
  v.push_back(a);
  
  a = b;
}