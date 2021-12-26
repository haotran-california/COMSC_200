//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <fstream> 
#include <vector>
#include <iterator>
#include <sstream>
using namespace std; 

//function prototypes 
vector<string> parseString(string); 
vector<string> tokens; 
void Shape(vector<string>); 
void Square(double); 
void Rectangle(double, double); 
void Cylinder(double, double); 
void Cube(double); 
void Triangle(double); 
void Circle(double); 
void Box(double, double, double); 
void Prism(double, double); 

//constants 
double PI = M_PI;
FILE *file; 

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  
  
  //open file stream and standard input and output objects 
  ifstream fin; 
  fin.open("Shapes.input.txt"); 
  file = fopen("Shapes.output.txt", "w"); 

  
  //read through file 
  string line = ""; 
  while(getline(fin, line)){
    tokens = parseString(line); 
    Shape(tokens); 
  }
  fin.close(); 
    
}

//function defintions 
vector<string> parseString(string str){
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);

}

void Square(double s){
  double area = (s * s); 
  double perimeter = (s * 4);   
  string str = ""; 
  printf("SQUARE side=%.2f area=%.2f perimeter=%.2f \n",s, area, perimeter); //print formatted string to console  
  fprintf(file, "SQUARE side=%.2f area=%.2f perimeter=%.2f \n",s, area, perimeter);  //print formtted string to file  
}
void Rectangle(double l, double w){
  double area = l * w; 
  double perimeter = 2*w + 2*l;
  printf("RECTANGLE length=%.2f width=%.2f area=%.2f perimeter=%.2f \n", l, w, area, perimeter); 
  fprintf(file,"RECTANGLE length=%.2f width=%.2f area=%.2f perimeter=%.2f \n", l, w, area, perimeter); 
}
void Cylinder(double r, double h){
  double s_area =  (2*PI*r*h) + (2*PI*r*r); 
  double volume = PI*r*r*h;
  printf("CYLINDER radius=%.2f height=%.2f surface area=%.2f volume=%.2f \n", r, h, s_area, volume); 
  fprintf(file,"CYLINDER radius=%.2f height=%.2f surface area=%.2f volume=%.2f \n", r, h, s_area, volume); 
}
void Cube(double s){
  double volume = s * s * s; 
  double s_area = 6 * (s * s); 
  printf("CUBE side=%.2f surface area=%.2f volume=%.2f \n", s, s_area, volume);
  fprintf(file,"CUBE side=%.2f surface area=%.2f volume=%.2f \n", s, s_area, volume); 
}
void Triangle(double s){
  double area = s / 2;
  double perimeter = s * 3;  
  printf("TRIANGLE side=%.2f area=%.2f perimeter=%.2f \n", s, area, perimeter); 
  fprintf(file,"TRIANGLE side=%.2f area=%.2f perimeter=%.2f \n", s, area, perimeter); 
}

void Circle(double r){
  double area = r * r * PI; 
  double perimeter = 2 * PI * r; 
  printf("CIRCLE radius=%.2f area=%.2f perimeter=%.2f \n", r, area, perimeter); 
  fprintf(file,"CIRCLE radius=%.2f area=%.2f perimeter=%.2f \n", r, area, perimeter);
}

void Box(double l, double w, double h){
  double s_area = 2*(l * w) + 2*(w * h) + 2*(l * h); 
  double volume = l * w * h; 
  printf("BOX length=%.2f width=%.2f height=%.2f surface area=%.2f volume=%.2f \n", l, w, h, s_area, volume);
  fprintf(file,"BOX length=%.2f width=%.2f height=%.2f surface area=%.2f volume=%.2f \n", l, w, h, s_area, volume); 
}

void Prism(double s, double h){
  double area = s * h; 
  double perimeter = 2 * s + 2 * h; 
  printf("PRISM side=%.2f height=%.2f area=%.2f perimeter=%.2f", s, h, area, perimeter); 
  fprintf(file,"PRISM side=%.2f height=%.2f area=%.2f perimeter=%.2f", s, h, area, perimeter);
}

void Shape(vector<string> token){
  string shape = ""; 
  string str = ""; 
  double num1, num2, num3; 

   //logic for handling the number of tokens
  if(token.size()==0){
    num1 = 0;  
    num2 = 0;
    num3 = 0;  
  }

  if(token.size() >= 1){
    shape = token[0]; 
  }

  if(token.size() >= 2){
    str = token[1]; 
    num1 = atof(str.c_str()); 
  }

  if(token.size() >= 3){
    str = token[2]; 
    num2 = atof(str.c_str()); 
  }

  if(token.size() == 4){
    str = token[3]; 
    num3 = atof(str.c_str()); 
  }

  //large if-statements handles which
  if(shape == "SQUARE"){
    Square(num1); 
  }else if(shape == "RECTANGLE"){
    Rectangle(num1, num2); 
  }else if(shape == "CYLINDER"){
    Cylinder(num1, num2); 
  }else if(shape == "CUBE"){
    Cube(num1);  
  }else if(shape == "TRIANGLE"){
    Triangle(num1); 
  }else if(shape == "CIRCLE"){
    Circle(num1); 
  }else if(shape == "PRISM"){
    Prism(num1, num2); 
  }
  else if(shape == "BOX"){
    Box(num1, num2, num3); 
  }
  else{
    if(token.size() == 0){
      cout << "";   
    }else{
      cout << shape << " invalid object \n"; 
    }
  }
}
