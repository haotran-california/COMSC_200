//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <fstream>
using namespace std; 

class Leg{
  const char* const startCity; 
  const char* const endCity; 
  const double distance; 

  public: 
  Leg(const char* const, const char* const, const double); //constructor 
  Leg& operator=(const Leg&); //assignment operator
  double getDistance() const; //distance getter 
  void output(ostream&) const; //output getter 
};

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl; 

  //initalize array of legs
  Leg cities[] = {
    Leg("Honolulu", "O'ahu", 15),
    Leg("San Francisio", "Los Angeles", 800),
    Leg("Seatle", "Tacoma", 50),
    Leg("San Jose", "San Franciso", 48.4), 
    Leg("Berkley", "Napa", 20), 
    Leg("Seattle", "Spokane", 279), 
    Leg("Portland", "Salem", 45.8), 
    Leg("Eugene", "Redding", 316),
    Leg("Reno", "South Lake Tahoe", 61.4), 
    Leg("Los Angeles", "San Diego", 120), 
    Leg("Los Angeles", "Las Vegas", 271), 
    Leg("Phoenix", "Tucson", 113), 
    Leg("Albuquerque", "Santa Fe", 64.1), 
    Leg("San Antonio", "Austin", 79.7),
    Leg("Austin", "Huston", 165),
    Leg("Austin", "Dallas", 195),
    Leg("Dallas", "Oklahoma City", 206), 
    Leg("Dallas", "Fort Worth", 32), 
    Leg("New Orleans", "Lafayette", 135),
    Leg("Tampa", "Orlando", 84.4),
    Leg("Miami", "Tampa", 280), 
    Leg("Atlanta", "Jacksonville", 346), 
    Leg("Charlotte", "Atlanta", 245), 
    Leg("Baltimore", "Washington", 38.3),
    Leg("Minneapolis", "Milwaukee", 337),
    Leg("Milwaukee", "Chicago", 92.6), 
    Leg("Detroit", "Cleveland", 170), 
    Leg("Kansas City", "St. Louis", 248), 
    Leg("Louisville", "Cincinnati", 99.5), 
    Leg("Columbus", "Pittsburgh", 185), 
    Leg("Philadelphia", "New York", 94.1), 
    Leg("Denver", "Boulder", 29.6), 
    Leg("South Lake City", "Provo", 45.3), 
    Leg("Jackson", "Memphis", 210), 
    Leg("Richmond", "Virginia Beach", 107), 
    Leg("Boston", "Worcester", 47.4), 
    Leg("Syracuse", "Rochester", 88.2), 
    Leg("Hartford", "New Haven", 38.4), 
    Leg("New York", "Long Island", 51), 
    Leg("Fresno", "Baskersfield", 109), 
    Leg("Wichita", "Kansas City", 197)
  }; 

  int n = sizeof(cities)/sizeof(cities[0]); 

  //sort legs from shortest to longest 
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(cities[j].getDistance() > cities[j+1].getDistance()){
        swap(cities[j], cities[j+1]); 
      }else{
        continue;
      }
    }
  }

  //output list of sorted legs 
  for(int i = 0; i < sizeof(cities); i++){
    cities[i].output(cout); 
  }
}

//member function definitions 
Leg::Leg(const char* s, const char* const e, const double d)
:startCity(s), endCity(e), distance(d){}

Leg& Leg:: operator=(const Leg& l){
  Leg& newLeg = *this;
  if(this != &l){
    const_cast<const char*&>(newLeg.startCity) = l.startCity;
    const_cast<const char*&>(newLeg.endCity) = l.endCity;
    const_cast<double&>(newLeg.distance) = l.distance;
  }
  return newLeg;
}

void Leg::output(ostream& out) const{
  char buffer[50]; 
  sprintf(buffer, "Leg: %s to %s, %.1f miles", this->startCity, this->endCity, this->distance); 
  out << buffer << endl; 
}

double Leg::getDistance() const{
  return this->distance; 
}

void swap(Leg *a, Leg *b){
  Leg temp = *a; 
  *a = *b; 
  *b = temp; 
}

