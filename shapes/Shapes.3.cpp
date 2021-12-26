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
double PI = M_PI; 

//declare function prototypes
vector<string> parseString(string); 
ostream& roundingTwo(ostream&); 

//declare structs for the shapes
struct Square{
  double side; 
  void outputSquare(ostream& out) const{
    double area = this->side * this->side; 
    double perimeter = 4 * this->side; 
    char buffer[50]; 
    sprintf(buffer, "SQUARE side=%.2f area=%.2f perimeter=%.2f \n", this->side, area, perimeter); 
    out << roundingTwo << buffer; 
  }
};

struct Rectangle{
  double length; 
  double width; 
  void outputRectangle(ostream& out) const{
    double area = this->length * this->width; 
    double perimeter = (2 * this->length) + (2* this->width); 
    char buffer[50]; 
    sprintf(buffer, "RECTANGLE length=%.2f width=%.2f area=%.2f perimeter=%.2f \n", this->length, this->width, area, perimeter); 
    out << roundingTwo << buffer; 
  } 
};

struct Circle{
  double radius; 
  void outputCircle(ostream& out) const{
    double area = PI * this->radius * this->radius;  
    double perimeter = 2 * PI * this->radius;
    char buffer[50]; 
    sprintf(buffer, "CIRCLE radius=%.2f area=%.2f perimeter=%.2f \n", this->radius, area, perimeter); 
    out << roundingTwo << buffer; 
  } 
};

struct Triangle{
  double side; 
  void outputTriangle(ostream& out) const{
    double area = this->side / 2; 
    double perimeter= this->side * 3; 
    char buffer[50]; 
    sprintf(buffer, "TRIANGLE side=%.2f area=%.2f perimeter=%.2f \n", this->side, area, perimeter); 
    out << roundingTwo << buffer; 
  }
};

struct Cube{
  double side; 
  void outputCube(ostream& out) const{
    double volume = this->side * this->side * this->side;  
    double s_area = 6 * this->side * this->side; 
    char buffer[50]; 
    sprintf(buffer, "CUBE side=%.2f volume=%.2f s_area=%.2f \n", this->side, volume, s_area); 
    out << roundingTwo << buffer; 
  } 
};

struct Box{
  double length; 
  double width; 
  double height; 
  void outputBox(ostream& out) const{
    double volume = this->length * this->width * this->height; 
    double s_area = 2 * (this->length * this->width) + 2 * (this->length * this->height) + 2 * (this->height * this->width); 
    char buffer[50]; 
    sprintf(buffer, "BOX length=%.2f width=%.2f area=%.2f perimeter=%.2f \n", this->length, this->width, volume, s_area); 
    out << roundingTwo << buffer; 
  }
};

struct Cylinder{
  double radius; 
  double height; 
  void outputCylinder(ostream& out) const{
    double volume =  PI * this->radius * this->radius * this->height; 
    double s_area = (2 * PI * this->radius * this->height) + (2 * PI * this->radius * this->radius); 
    char buffer[50]; 
    sprintf(buffer, "CYLINDER radius=%.2f height=%.2f area=%.2f perimeter=%.2f \n", this->radius, this->height, volume, s_area); 
    out << roundingTwo << buffer;  
  } 
}; 

struct Prism{
  double side; 
  double height; 
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
vector<void*> Bag; 
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
    double num1 = 0; 
    double num2 = 0; 
    double num3 = 0;     
    
    
    //logic for handling the number of tokens
    if(tokens.size() >= 1){
        shape = tokens[0]; 
    }
    
    num1 = (tokens.size() >= 2) ? atof(tokens[1].c_str()) : 0; //ternary operator for tokens 
    num2 = (tokens.size() >= 3) ? atof(tokens[2].c_str()) : 0;
    num3 = (tokens.size() >= 4) ? atof(tokens[3].c_str()) : 0;

    
    //logic for creating objects from tokens 
    if(shape == "SQUARE"){
        Square* square = new Square;
        square->side = num1; 
        Bag.push_back(square); 
        bagType.push_back('S'); 
    }else if(shape == "RECTANGLE"){
        Rectangle* rectangle = new Rectangle;
        rectangle->length = num1;
        rectangle->width = num2; 
        Bag.push_back(rectangle);
        bagType.push_back('R'); 
    }else if(shape == "CYLINDER"){
        Cylinder* cylinder = new Cylinder;
        cylinder->radius = num1; 
        cylinder->height = num2; 
        Bag.push_back(cylinder);
        bagType.push_back('L'); 
    }else if(shape == "CUBE"){ 
        Cube* cube = new Cube;
        cube->side = num1; 
        Bag.push_back(cube);
        bagType.push_back('C'); 
    }else if(shape == "TRIANGLE"){
        Triangle* triangle = new Triangle; 
        triangle->side = num1;  
        Bag.push_back(triangle);
        bagType.push_back('T'); 
    }else if(shape == "CIRCLE"){
        Circle* circle = new Circle; 
        circle->radius = num1;  
        Bag.push_back(circle);
        bagType.push_back('I'); 
    }else if(shape == "PRISM"){
        Prism* prism = new Prism; 
        prism->side = num1; 
        prism->height = num2;
        Bag.push_back(prism);
        bagType.push_back('P'); 
    }else if(shape == "BOX"){
        Box* box = new Box; 
        box->length = num1; 
        box->width = num2; 
        box->height = num3; 
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

  //iterate through bag and output to file 
    for(int i = 0; i < Bag.size(); i++){
    //square
    if(bagType[i] == 'S'){
      Square* pSquare = reinterpret_cast<Square*>(Bag[i]); 
      pSquare->outputSquare(fout); 
    }
    //rectangle 
    if(bagType[i] == 'R'){
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Bag[i]); 
      Rectangle& rRectangle = *pRectangle; 
      pRectangle->outputRectangle(fout); 
    }
    //triangle 
    if(bagType[i] == 'T'){
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Bag[i]); 
      pTriangle->outputTriangle(fout); 
    }
    //circle
    if(bagType[i] == 'I'){
      Circle* pCircle = reinterpret_cast<Circle*>(Bag[i]); 
      pCircle->outputCircle(fout); 
    } 
    //cylinder
    if(bagType[i] == 'L'){
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Bag[i]); 
      pCylinder->outputCylinder(fout); 
    }
    //cube
    if(bagType[i] == 'C'){
      Cube* pCube = reinterpret_cast<Cube*>(Bag[i]); 
      pCube->outputCube(fout); 
    }
    //box
    if(bagType[i] == 'B'){
      Box* pBox = reinterpret_cast<Box*>(Bag[i]); 
      pBox->outputBox(fout); 
    } 
    //prism
    if(bagType[i] == 'P'){
      Prism* pPrism = reinterpret_cast<Prism*>(Bag[i]); 
      pPrism->outputPrism(fout); 
    }
    //invalid shapes
    if(bagType[i] == 'Z'){
      fout << "SHAPE invalid object" << endl;  
    }
  }

    //iterate through bag and output to console 
    for(int i = 0; i < Bag.size(); i++){
    //square
    if(bagType[i] == 'S'){
      Square* pSquare = reinterpret_cast<Square*>(Bag[i]); 
      pSquare->outputSquare(cout); 
    }
    //rectangle 
    if(bagType[i] == 'R'){
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Bag[i]); 
      pRectangle->outputRectangle(cout); 
    }
    //triangle 
    if(bagType[i] == 'T'){
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Bag[i]); 
      pTriangle->outputTriangle(cout); 
    }
    //circle
    if(bagType[i] == 'I'){
      Circle* pCircle = reinterpret_cast<Circle*>(Bag[i]); 
      pCircle->outputCircle(cout); 
    } 
    //cylinder
    if(bagType[i] == 'L'){
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Bag[i]); 
      pCylinder->outputCylinder(cout); 
    }
    //cube
    if(bagType[i] == 'C'){
      Cube* pCube = reinterpret_cast<Cube*>(Bag[i]); 
      pCube->outputCube(cout); 
    }
    //box
    if(bagType[i] == 'B'){
      Box* pBox = reinterpret_cast<Box*>(Bag[i]); 
      pBox->outputBox(cout); 
    } 
    //prism
    if(bagType[i] == 'P'){
      Prism* pPrism = reinterpret_cast<Prism*>(Bag[i]); 
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


