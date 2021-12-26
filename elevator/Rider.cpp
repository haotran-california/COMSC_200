//Programmer: Hao Tran
//ID: 1872272

#include "Rider.h"
#include "Building.h"

Rider::Rider(int f, int t)
:from(f), to(t){}

Rider& Rider::operator=(const Rider& r){
  const_cast<int&>(this->from) = r.from;
  const_cast<int&>(this->to) = r.to;
  const_cast<bool&>(this->goingUp) = r.goingUp;
  const_cast<bool&>(this->goingDown) = r.goingDown;
  return *this;
}
