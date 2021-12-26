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

//declare structs for the shapes
struct Square{
  double side; 
};

struct Rectangle{
  double length; 
  double width; 
};

struct Circle{
  double radius; 
};

struct Triangle{
  double side; 
};

struct Cube{
  double side; 
};

struct Box{
  double length; 
  double width; 
  double height; 
};

struct Cylinder{
  double radius; 
  double height; 
}; 

struct Prism{
  double side; 
  double height; 
};

//declare vectors
vector<string> tokens; 
vector<void*> Bag; 
vector<char> type; 

//declare function prototypes
vector<string> parseString(string); 

//output function prototypes 
void outputSquare(ostream&, const Square&); 
void outputRectangle(ostream&, const Rectangle&); 
void outputCircle(ostream&, const Circle&); 
void outputTriangle(ostream&, const Triangle&); 
void outputCube(ostream&, const Cube&); 
void outputBox(ostream&, const Box&); 
void outputCylinder(ostream&, const Cylinder&); 
void outputPrism(ostream&, const Prism&); 


//constants
double PI = M_PI; 

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
    Square* square = new Square; 
    Rectangle* rectangle = new Rectangle;  
    Triangle* triangle = new Triangle; 
    Circle* circle = new Circle; 
    Cylinder* cylinder = new Cylinder;  
    Cube* cube = new Cube; 
    Box* box = new Box; 
    Prism* prism = new Prism; 
    
    //logic for handling the number of tokens
    if(tokens.size() >= 1){
        shape = tokens[0]; 
    }

    if(tokens.size() >= 2){
        str = tokens[1]; 
        num1 = atof(str.c_str()); 
    }

    if(tokens.size() >= 3){
        str = tokens[2]; 
        num2 = atof(str.c_str()); 
    }

    if(tokens.size() == 4){
        str = tokens[3]; 
        num3 = atof(str.c_str()); 
    } 

    //logic for creating objects from tokens 
    if(shape == "SQUARE"){
        square->side = num1; 
        type.push_back('S'); 
    }else if(shape == "RECTANGLE"){
        rectangle->length = num1;
        rectangle->width = num2; 
        Bag.push_back(rectangle);
        type.push_back('R'); 
    }else if(shape == "CYLINDER"){
        cylinder->radius = num1; 
        cylinder->height = num2; 
        Bag.push_back(cylinder);
        type.push_back('L'); 
    }else if(shape == "CUBE"){
        cube->side = num1; 
        Bag.push_back(cube);
        type.push_back('C'); 
    }else if(shape == "TRIANGLE"){
        triangle->side = num1;  
        Bag.push_back(triangle);
        type.push_back('T'); 
    }else if(shape == "CIRCLE"){
        circle->radius = num1;  
        Bag.push_back(circle);
        type.push_back('I'); 
    }else if(shape == "PRISM"){
        prism->side = num1; 
        prism->height = num2;
        Bag.push_back(prism);
        type.push_back('P'); 
    }
    else if(shape == "BOX"){
        box->length = num1; 
        box->width = num2; 
        box->height = num3; 
        Bag.push_back(box);
        type.push_back('B'); 
    }
    else{
        if(tokens.size() == 0){
        cout << "";   
        }else{
        cout << shape << " invalid object \n"; 
    }
  }
}

  for(int i = 0; i < Bag.size(); i++){
    //square
    if(type[i] == 'S'){
      Square* pSquare = reinterpret_cast<Square*>(Bag[i]); 
      Square& rSquare = *pSquare; 
      outputSquare(cout, rSquare); 
    }
    //rectangle 
    if(type[i] == 'S'){
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Bag[i]); 
      Rectangle& rRectangle = *pRectangle; 
      outputRectangle(cout, rRectangle); 
    }
    //triangle 
    if(type[i] == 'S'){
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Bag[i]); 
      Triangle& rTriangle = *pTriangle; 
      outputTriangle(cout, rTriangle); 
    }
    //circle
    if(type[i] == 'S'){
      Circle* pCircle = reinterpret_cast<Circle*>(Bag[i]); 
      Circle& rCircle = *pCircle; 
      outputCircle(cout, rCircle); 
    } 
    //cylinder
    if(type[i] == 'S'){
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Bag[i]); 
      Cylinder& rCylinder = *pCylinder; 
      outputCylinder(cout, rCylinder); 
    }
    //cube
    if(type[i] == 'S'){
      Cube* pCube = reinterpret_cast<Cube*>(Bag[i]); 
      Cube& rCube = *pCube; 
      outputCube(cout, rCube); 
    }
    //box
    if(type[i] == 'S'){
      Box* pBox = reinterpret_cast<Box*>(Bag[i]); 
      Box& rBox = *pBox; 
      outputBox(cout, rBox); 
    } 
    //prism
    if(type[i] == 'S'){
      Prism* pPrism = reinterpret_cast<Prism*>(Bag[i]); 
      Prism& rPrism = *pPrism; 
      outputPrism(cout, rPrism); 
    }
  }

  //text file output 
  for(int i = 0; i < Bag.size(); i++){
    //square
    if(type[i] == 'S'){
      Square* pSquare = reinterpret_cast<Square*>(Bag[i]); 
      Square& rSquare = *pSquare; 
      outputSquare(fout, rSquare); 
    }
    //rectangle 
    if(type[i] == 'S'){
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Bag[i]); 
      Rectangle& rRectangle = *pRectangle; 
      outputRectangle(fout, rRectangle); 
    }
    //triangle 
    if(type[i] == 'S'){
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Bag[i]); 
      Triangle& rTriangle = *pTriangle; 
      outputTriangle(fout, rTriangle); 
    }
    //circle
    if(type[i] == 'S'){
      Circle* pCircle = reinterpret_cast<Circle*>(Bag[i]); 
      Circle& rCircle = *pCircle; 
      outputCircle(fout, rCircle); 
    } 
    //cylinder
    if(type[i] == 'S'){
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Bag[i]); 
      Cylinder& rCylinder = *pCylinder; 
      outputCylinder(fout, rCylinder); 
    }
    //cube
    if(type[i] == 'S'){
      Cube* pCube = reinterpret_cast<Cube*>(Bag[i]); 
      Cube& rCube = *pCube; 
      outputCube(fout, rCube); 
    }
    //box
    if(type[i] == 'S'){
      Box* pBox = reinterpret_cast<Box*>(Bag[i]); 
      Box& rBox = *pBox; 
      outputBox(fout, rBox); 
    } 
    //prism
    if(type[i] == 'S'){
      Prism* pPrism = reinterpret_cast<Prism*>(Bag[i]); 
      Prism& rPrism = *pPrism; 
      outputPrism(fout, rPrism); 
    }
  }

  //deallocation 
  for(int i = 0; i < Bag.size(); i++){
    //square
    if(type[i] == 'S'){
      Square* pSquare = reinterpret_cast<Square*>(Bag[i]); 
      delete pSquare; 
    }
    //rectangle 
    if(type[i] == 'S'){
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(Bag[i]); 
      delete pRectangle; 
    }
    //triangle 
    if(type[i] == 'S'){
      Triangle* pTriangle = reinterpret_cast<Triangle*>(Bag[i]); 
      delete pTriangle; 
    }
    //circle
    if(type[i] == 'S'){
      Circle* pCircle = reinterpret_cast<Circle*>(Bag[i]); 
      delete pCircle; 
    } 
    //cylinder
    if(type[i] == 'S'){
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(Bag[i]); 
      delete pCylinder; 
    }
    //cube
    if(type[i] == 'S'){
      Cube* pCube = reinterpret_cast<Cube*>(Bag[i]); 
      delete pCube; 
    }
    //box
    if(type[i] == 'S'){
      Box* pBox = reinterpret_cast<Box*>(Bag[i]); 
      delete pBox; 
    } 
    //prism
    if(type[i] == 'S'){
      Prism* pPrism = reinterpret_cast<Prism*>(Bag[i]); 
      delete pPrism; 
    }
  }

  cout << "done"; 

}


//function definitions 
vector<string> parseString(string str){
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

//define member functions to calculate area and perimeter for each shape 
void outputSquare(ostream& out, const Square& s){
  double area = s.side * s.side; 
  double perimeter = 4 * s.side; 
  char buffer[50]; 
  sprintf(buffer, "SQUARE side=%.2f area=%.2f perimeter=%.2f \n", s.side, area, perimeter); 
  out << buffer; 
    
}
void outputRectangle(ostream& out, const Rectangle& r){
  double area = r.length * r.width; 
  double perimeter = (2 * r.length) + (2* r.width); 
  char buffer[50]; 
  sprintf(buffer, "RECTANGLE length=%.2f width=%.2f area=%.2f perimeter=%.2f \n", r.length, r.width, area, perimeter); 
  out << buffer; 
} 
void outputCircle(ostream& out, const Circle& c){
  double area = PI * c.radius * c.radius;  
  double perimeter = 2 * PI * c.radius;
  char buffer[50]; 
  sprintf(buffer, "CIRCLE radius=%.2f area=%.2f perimeter=%.2f \n", c.radius, area, perimeter); 
  out << buffer; 

} 
void outputTriangle(ostream& out, const Triangle& t){
  double area = t.side / 2; 
  double perimeter= t.side * 3; 
  char buffer[50]; 
  sprintf(buffer, "TRIANGLE side=%.2f area=%.2f perimeter=%.2f \n", t.side, area, perimeter); 
  out << buffer; 
} 
void outputCube(ostream& out, const Cube& c){
  double volume = c.side * c.side * c.side;  
  double s_area = 6 * c.side * c.side; 
  char buffer[50]; 
  sprintf(buffer, "CUBE side=%.2f volume=%.2f s_area=%.2f \n", c.side, volume, s_area); 
  out << buffer; 

} 
void outputBox(ostream& out, const Box& b){
  double volume = b.length * b.width * b.height; 
  double s_area = 2 * (b.length * b.width) + 2 * (b.length * b.height) + 2 * (b.height * b.width); 
  char buffer[50]; 
  sprintf(buffer, "BOX length=%.2f width=%.2f area=%.2f perimeter=%.2f \n", b.length, b.width, volume, s_area); 
  out << buffer; 
} 
void outputCylinder(ostream& out, const Cylinder& c){
  double volume =  PI * c.radius * c.radius * c.height; 
  double s_area = (2 * PI * c.radius * c.height) + (2 * PI * c.radius * c.radius); 
  char buffer[50]; 
  sprintf(buffer, "CYLINDER radius=%.2f height=%.2f area=%.2f perimeter=%.2f \n", c.radius, c.height, volume, s_area); 
  out << buffer; 
  
} 
void outputPrism(ostream& out, const Prism& p){
  double area = p.side * p.height; 
  double perimeter = (2 * p.side) + (2 * p.height); 
  char buffer[50]; 
  sprintf(buffer, "PRISM side=%.2f area=%.2f perimeter=%.2f \n", p.side, area, perimeter); 
  out << buffer; 
} 