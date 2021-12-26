//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
using namespace std; 

#include <cstring>

class Leg{
  friend class Route; 
  friend class ShortestRoute; 
  const char* const startCity; 
  const char* const endCity; 
  const double distance; 

  public: 
  Leg(const char* const, const char* const, const double);
  Leg& operator=(const Leg&); 
  double getDistance() const; 
  void output(ostream&) const; 
};

class Route{
  friend class ShortestRoute; 
  vector<const Leg*> legs; 
  const double totalDis;

  public: 
  Route(const Leg&); 
  Route(const Route&, const Leg&); 
  Route& operator=(const Route&);
  friend bool operator<(const Route&, const Route&); 
  double getDistance() const {return totalDis;}
  void output(ostream&) const;  
};

class ShortestRoute{
  static const int legSize; 
  static const Leg allLegs[]; 

  public: 
  static const Route anyRoute(const char* const, const char* const); 
  static const Route shortestRoute(const char* const, const char* const);
};

//defined static member data outside of class 
const Leg ShortestRoute::allLegs[] = {
        Leg("San Francisco","Berkeley",14),
        Leg("San Francisco","San Jose",48),
        Leg("San Francisco","Santa Cruz",73),
        Leg("San Jose","Sacramento",120),
        Leg("Berkeley","Sacramento",78),
        Leg("Berkeley","Bakersfield",78),
        Leg("San Jose","Bakersfield",241),
        Leg("Santa Cruz","San Jose",32),
        Leg("Santa Cruz","Bakersfield",247),
        Leg("Santa Cruz","Reno",277),
        Leg("San Jose","Provo",810),
        Leg("Sacramento","Santa Fe",1141),
        Leg("Bakersfield","Santa Fe",864),
        Leg("Chicago","Pittsburgh",461),
        Leg("Oklahoma City","St. Louis",499),
        Leg("Memphis","Nashville",212),
        Leg("Oklahoma City","Nashville",678),
        Leg("Nashville","Greensboro",465),
        Leg("Denver","Omaha",537),
        Leg("Santa Fe","Omaha",880),
        Leg("Provo","Santa Fe",582),
        Leg("Provo","Denver",582),
        Leg("Bakersfield","Denver",1032),
        Leg("Greensboro","Baltimore",355),
        Leg("Baltimore","New York City",191),
        Leg("Pittsburgh","New York City",371),
        Leg("Pittsburgh","Baltimore",248),
        Leg("Sacramento","Reno",132),
        Leg("Denver","Oklahoma City",680),
        Leg("Santa Fe","Oklahoma City",680),
        Leg("Santa Fe","Dallas",637),
        Leg("Oklahoma City","Dallas",206),
        Leg("Denver","Memphis",1095),
        Leg("Chicago","Greensboro",738),
        Leg("Nashville","Pittsburgh",560),
        Leg("Oklahoma City","Memphis",467),
        Leg("Dallas","Memphis",452),
        Leg("Omaha","St. Louis",435),
        Leg("Dallas","Greensboro",1127),
        Leg("Omaha","Chicago",471),
        Leg("Bakersfield","Chicago",2032),
        Leg("St. Louis","Baltimore",821),
        Leg("Greensboro","Baltimore",355),
        Leg("St. Louis","Nashville",309),
        Leg("San Francisco","New York City",21000),
};

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  const Route route1 = ShortestRoute::anyRoute("San Francisco", "New York City");
  route1.output(cout);

  const Route route2 = ShortestRoute::shortestRoute("San Francisco", "New York City");
  route2.output(cout);
}

//member function definitions for leg
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

//member function definitions for route 
Route::Route(const Leg& l) : totalDis(l.getDistance()){
  legs.push_back(&l);
}

Route::Route(const Route& r, const Leg& l)
: legs(r.legs), totalDis(r.totalDis + l.getDistance()){

  if(r.legs.back()->endCity != l.startCity) throw "Error"; 

  legs.push_back(&l);
}

Route & Route:: operator=(const Route& r){
  Route& route = *this;
  if(this != &r){
    const_cast<double&>(route.totalDis) = r.getDistance();
    route.legs = r.legs;
  }
  return route;
}

void Route:: output(ostream& out) const{
  string message = "";
  double distance = 0;  
  for(int i = 0; i < legs.size(); i++){
    distance += legs[i]->distance; 
    message += legs[i]->startCity; 
    if(legs.size() - i > 1){
      message += " to"; 
    }
    message += " "; 
    
  }

  out << message; 
  out << fixed << setprecision(2) << distance << endl; 
  
}

//member functions for shortest route 
const Route ShortestRoute::anyRoute(const char* const start, const char* const end){
  for(int i = 0; i < 48; i++){
    if(strcmp(ShortestRoute::allLegs[i].endCity, end) == 0){
        if(strcmp(ShortestRoute::allLegs[i].startCity, start) == 0){
          Route r(allLegs[i]);
          return r; 
        }else{
          Route r2(ShortestRoute::anyRoute(start, ShortestRoute::allLegs[i].startCity), allLegs[i]); 
          return r2; 
        }
    }
  }
  Route r(allLegs[0]); 
  return r; 
}

const Route ShortestRoute::shortestRoute(const char* const start, const char* const end){
  set<Route> s;
  for (int i = 0; i < 44; i++) {
    for (int j = 0; j < 44; j++) {
      if (strcmp(ShortestRoute::allLegs[j].endCity, end) == 0) {
        if (strcmp(ShortestRoute::allLegs[j].startCity, start) == 0) {
          Route r(allLegs[j]);
          return r;
        }
        else {
          Route x(ShortestRoute::anyRoute(start, ShortestRoute::allLegs[j].startCity), allLegs[j]);
          s.insert(x);
        }
      }else{
        continue;
      }
    }
  }
  return *(s.begin());
}

bool operator<(const Route& a, const Route& b){
  return a.totalDis < b.totalDis;
}

void swap(Leg *a, Leg *b){
  Leg temp = *a; 
  *a = *b; 
  *b = temp; 
}
