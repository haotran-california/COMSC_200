//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

//constants
const double PI = M_PI; 

//declare function prototypes
vector<string> parseString(string); 
ostream& roundingTwo(ostream&); 

//declare structs for the shapes
struct Square{
  private: 
    const double side; 

  public: 
   Square(const vector<string> token):
   side{(token.size() >= 2) ? atof(token[1].c_str()) : 0}{}
    
    void outputSquare(ostream& out) const{
      double area = this->side * this->side; 
      double perimeter = 4 * this->side; 
      char buffer[50]; 
      sprintf(buffer, "SQUARE side=%.2f area=%.2f perimeter=%.2f \n", this->side, area, perimeter); 
      out << roundingTwo << buffer; 
    }
};

struct Rectangle{
  private: 
    const double length; 
    const double width; 

  public: 
    Rectangle(const vector<string> token):
    length{(token.size() >= 2) ? atof(token[1].c_str()) : 0}, 
    width{(token.size() >= 3) ? atof(token[2].c_str()) : 0}{}

    void outputRectangle(ostream& out) const{
      double area = this->length * this->width; 
      double perimeter = (2 * this->length) + (2* this->width); 
      char buffer[50]; 
      sprintf(buffer, "RECTANGLE length=%.2f width=%.2f area=%.2f perimeter=%.2f \n", this->length, this->width, area, perimeter); 
      out << roundingTwo << buffer; 
    } 
};

struct Circle{
  private: 
    const double radius = 0; 

  public: 
    Circle(const vector<string> token):
    radius{(token.size() >= 2) ?  atof(token[1].c_str()) : 0}{}

    void outputCircle(ostream& out) const{
      double area = PI * this->radius * this->radius;  
      double perimeter = 2 * PI * this->radius;
      char buffer[50]; 
      sprintf(buffer, "CIRCLE radius=%.2f area=%.2f perimeter=%.2f \n", this->radius, area, perimeter); 
      out << roundingTwo << buffer; 
    } 
};

struct Triangle{
  private: 
    const double side = 0; 

  public: 
    Triangle(const vector<string> token):
    side{(token.size() >= 2) ? atof(token[1].c_str()) : 0}{}
    
    void outputTriangle(ostream& out) const{
      double area = this->side / 2; 
      double perimeter= this->side * 3; 
      char buffer[50]; 
      sprintf(buffer, "TRIANGLE side=%.2f area=%.2f perimeter=%.2f \n", this->side, area, perimeter); 
      out << roundingTwo << buffer; 
    }
};

struct Cube{
  private: 
    const double side = 0; 

  public: 
    Cube(const vector<string> token):
      side{(token.size() >= 2) ? atof(token[1].c_str()) : 0}{}
    
    void outputCube(ostream& out) const{
      double volume = this->side * this->side * this->side;  
      double s_area = 6 * this->side * this->side; 
      char buffer[50]; 
      sprintf(buffer, "CUBE side=%.2f volume=%.2f s_area=%.2f \n", this->side, volume, s_area); 
      out << roundingTwo << buffer; 
    } 
};

struct Box{
  private: 
    const double length = 0; 
    const double width = 0; 
    const double height = 0; 

  public: 
    Box(const vector<string> token): 
      length{(token.size() >= 2) ? atof(token[1].c_str()) : 0}, 
      width{(token.size() >= 3) ? atof(token[2].c_str()) : 0}, 
      height{(token.size() >= 4) ? atof(token[3].c_str()) : 0}{}
    
    void outputBox(ostream& out) const{
      double volume = this->length * this->width * this->height; 
      double s_area = 2 * (this->length * this->width) + 2 * (this->length * this->height) + 2 * (this->height * this->width); 
      char buffer[50]; 
      sprintf(buffer, "BOX length=%.2f width=%.2f area=%.2f perimeter=%.2f \n", this->length, this->width, volume, s_area); 
      out << roundingTwo << buffer; 
    }
};

struct Cylinder{
  private: 
    const double radius = 0; 
    const double height = 0; 

  public: 
    Cylinder(const vector<string> token):
      radius{(token.size() >= 2) ? atof(token[1].c_str()) : 0},
      height{(token.size() >= 3) ? atof(token[2].c_str()) : 0}{} 
    

    void outputCylinder(ostream& out) const{
      double volume =  PI * this->radius * this->radius * this->height; 
      double s_area = (2 * PI * this->radius * this->height) + (2 * PI * this->radius * this->radius); 
      char buffer[50]; 
      sprintf(buffer, "CYLINDER radius=%.2f height=%.2f area=%.2f perimeter=%.2f \n", this->radius, this->height, volume, s_area); 
      out << roundingTwo << buffer;  
    } 
}; 

struct Prism{
  private: 
    const double side = 0; 
    const double height = 0; 

  public: 
    Prism(const vector<string> token):
      side{(token.size() >= 2) ? atof(token[1].c_str()) : 0},
      height{(token.size() >= 3) ? atof(token[2].c_str()) : 0}{}
    
    void outputPrism(ostream& out) const{
      double area = this->side * this->height; 
      double perimeter = (2 * this->side) + (2 * this->height); 
      char buffer[50]; 
      sprintf(buffer, "PRISM side=%.2f area=%.2f perimeter=%.2f \n", this->side, area, perimeter); 
      out << roundingTwo << buffer; 
    } 
};

//declare vectors
vector<string> tokens; 
vector<const void*> Bag; 
vector<char> bagType; 

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  //declare variables 
  ifstream fin; 
  ofstream fout; 
  fin.open("Shapes.input.txt"); 
  fout.open("Shapes.output.txt"); 
  string line = "";

  //process input and fill bag 
  while(getline(fin, line)){
     
    tokens = parseString(line); 
    
    string shape = ""; 
    string str = ""; 
    
    //logic for handling the number of tokens
    if(tokens.size() >= 1){
        shape = tokens[0]; 
    }
    
    //logic for creating objects from tokens 
    if(shape == "SQUARE"){
        const Square* square = new Square(tokens);  
        Bag.push_back(square); 
        bagType.push_back('S'); 
    }else if(shape == "RECTANGLE"){
        const Rectangle* rectangle = new Rectangle(tokens); 
        Bag.push_back(rectangle);
        bagType.push_back('R'); 
    }else if(shape == "CYLINDER"){
        const Cylinder* cylinder = new Cylinder(tokens);  
        Bag.push_back(cylinder);
        bagType.push_back('L'); 
    }else if(shape == "CUBE"){ 
        const Cube* cube = new Cube(tokens);  
        Bag.push_back(cube);
        bagType.push_back('C'); 
    }else if(shape == "TRIANGLE"){
        const Triangle* triangle = new Triangle(tokens);   
        Bag.push_back(triangle);
        bagType.push_back('T'); 
    }else if(shape == "CIRCLE"){
        const Circle* circle = new Circle(tokens); 
        Bag.push_back(circle);
        bagType.push_back('I'); 
    }else if(shape == "PRISM"){
        const Prism* prism = new Prism(tokens); 
        Bag.push_back(prism);
        bagType.push_back('P'); 
    }else if(shape == "BOX"){
        const Box* box = new Box(tokens); 
        Bag.push_back(box);
        bagType.push_back('B'); 
    }else{
        if(tokens.size() == 0){
        cout << "";   
        }else{
        bagType.push_back('Z'); 
      }
    }
  } 

  fin.close();
  //sorting group like objects 
  for(int j = 0; j < 8; j++){
  //iterate through bag and output to file 
    for(int i = 0; i < Bag.size(); i++){
    //square
    if(bagType[i] == 'S' && j == 0){
      const Square* const pSquare = reinterpret_cast<const Square*>(Bag[i]); 
      pSquare->outputSquare(fout); 
    }
    //rectangle 
    if(bagType[i] == 'R' && j == 1){
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(Bag[i]); 
      pRectangle->outputRectangle(fout); 
    }
    //triangle 
    if(bagType[i] == 'T' && j == 2){
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(Bag[i]); 
      pTriangle->outputTriangle(fout); 
    }
    //circle
    if(bagType[i] == 'I' && j == 3){
      const Circle* const pCircle = reinterpret_cast<const Circle*>(Bag[i]);
      pCircle->outputCircle(fout); 
    } 
    //cylinder
    if(bagType[i] == 'L' && j == 4){
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(Bag[i]); 
      pCylinder->outputCylinder(fout); 
    }
    //cube
    if(bagType[i] == 'C' && j == 5){
      const Cube* const pCube = reinterpret_cast<const Cube*>(Bag[i]); 
      pCube->outputCube(fout); 
    }
    //box
    if(bagType[i] == 'B' && j == 6){
      const Box* const pBox = reinterpret_cast<const Box*>(Bag[i]); 
      pBox->outputBox(fout); 
    } 
    //prism
    if(bagType[i] == 'P' && j == 7){
      const Prism* pPrism = reinterpret_cast<const Prism*>(Bag[i]); 
      pPrism->outputPrism(fout); 
    }
    //invalid shapes
    if(bagType[i] == 'Z' && j == 8){
      fout << "SHAPE invalid object" << endl;  
      }
    }
  }

    //iterate through bag and output to console 
    for(int i = 0; i < Bag.size(); i++){
    //square
    if(bagType[i] == 'S'){
      const Square* const pSquare = reinterpret_cast<const Square*>(Bag[i]); 
      pSquare->outputSquare(cout); 
    }
    //rectangle 
    if(bagType[i] == 'R'){
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(Bag[i]); 
      pRectangle->outputRectangle(cout); 
    }
    //triangle 
    if(bagType[i] == 'T'){
      const Triangle*  const pTriangle = reinterpret_cast<const Triangle*>(Bag[i]); 
      pTriangle->outputTriangle(cout); 
    }
    //circle
    if(bagType[i] == 'I'){
      const Circle* pCircle = reinterpret_cast<const Circle*>(Bag[i]); 
      pCircle->outputCircle(cout); 
    } 
    //cylinder
    if(bagType[i] == 'L'){
      const Cylinder* pCylinder = reinterpret_cast<const Cylinder*>(Bag[i]); 
      pCylinder->outputCylinder(cout); 
    }
    //cube
    if(bagType[i] == 'C'){
      const Cube* pCube = reinterpret_cast<const Cube*>(Bag[i]); 
      pCube->outputCube(cout); 
    }
    //box
    if(bagType[i] == 'B'){
      const Box* pBox = reinterpret_cast<const Box*>(Bag[i]); 
      pBox->outputBox(cout); 
    } 
    //prism
    if(bagType[i] == 'P'){
      const Prism* pPrism = reinterpret_cast<const Prism*>(Bag[i]); 
      pPrism->outputPrism(cout); 
    }
    //invalid shapes
    if(bagType[i] == 'Z'){
      cout << "SHAPE invalid object" << endl;  
    }
  }
}

//function definitions 
vector<string> parseString(string str){
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

ostream& roundingTwo(ostream& out){
  out.setf(ios::fixed);
  out.precision(2); // 2 decimal digits
  return out;
}


