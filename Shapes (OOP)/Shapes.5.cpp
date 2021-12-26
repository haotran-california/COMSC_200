//Programmer: Hao Tran
//ID: 1872272

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "iShapes.h"

vector<string> parseString(string);

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  ifstream fin;
  fin.open("Shapes.input.txt");
  vector<const Shape*> shapesBag;
  vector<string> shapesTypeBag;

  while (fin.good()){
    string curLine;
    getline(fin, curLine);
    vector<string> lineElems = parseString(curLine);
    if(lineElems.size() != 0){
      checkShape(lineElems, shapesBag, shapesTypeBag);
    }
  }
  fin.close();
  
  cout << "working 1" << endl; 
  for (int i = 0; i < shapesBag.size(); i++){
    if (shapesTypeBag[i] == "SQUARE"){
      const Square* const ps = reinterpret_cast<const Square*>(shapesBag[i]);
      const Square& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "RECTANGLE"){
      const Rectangle* const ps = reinterpret_cast<const Rectangle*>(shapesBag[i]);
      const Rectangle& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "CIRCLE"){
      const Circle* const ps = reinterpret_cast<const Circle*>(shapesBag[i]);
      const Circle& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "TRIANGLE"){
      const Triangle* ps = reinterpret_cast<const Triangle*>(shapesBag[i]);
      const Triangle& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "CUBE"){
      const Cube* const ps = reinterpret_cast<const Cube*>(shapesBag[i]);
      const Cube& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "BOX"){
      const Box* const ps = reinterpret_cast<const Box*>(shapesBag[i]);
      const Box& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "CYLINDER"){
      const Cylinder* const ps = reinterpret_cast<const Cylinder*>(shapesBag[i]);
      const Cylinder& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "PRISM"){
      const Prism* const ps = reinterpret_cast<const Prism*>(shapesBag[i]);
      const Prism& rs = *ps;
      rs.output(cout);
    }
    else {
      throw "ERROR";
    }
  }

  ofstream fout;
  fout.open("Shapes.output.txt");

  for (unsigned int i = 0; i < shapesBag.size(); i++){
    if (shapesTypeBag[i] == "SQUARE"){
      const Square* const ps = reinterpret_cast<const Square*>(shapesBag[i]);
      const Square& rs = *ps;
      rs.output(fout);
    }
    else if (shapesTypeBag[i] == "RECTANGLE"){
      const Rectangle*  const ps = reinterpret_cast<const Rectangle*>(shapesBag[i]);
      const Rectangle& rs = *ps;
      rs.output(fout);
    }
    else if (shapesTypeBag[i] == "CIRCLE"){
      const Circle* const ps = reinterpret_cast<const Circle*>(shapesBag[i]);
      const Circle& rs = *ps;
      rs.output(fout);
    }
    else if (shapesTypeBag[i] == "TRIANGLE"){
      const Triangle* const ps = reinterpret_cast<const Triangle*>(shapesBag[i]);
      const Triangle& rs = *ps;
      rs.output(fout);
    }
    else if (shapesTypeBag[i] == "CUBE"){
      const Cube* const ps = reinterpret_cast<const Cube*>(shapesBag[i]);
      const Cube& rs = *ps;
      rs.output(fout);
    }
    else if (shapesTypeBag[i] == "BOX"){
      const Box* const ps = reinterpret_cast<const Box*>(shapesBag[i]);
      const Box& rs = *ps;
      rs.output(fout);
    }
    else if (shapesTypeBag[i] == "CYLINDER"){
      const Cylinder* ps = reinterpret_cast<const Cylinder*>(shapesBag[i]);
      const Cylinder& rs = *ps;
      rs.output(fout);
    }
    else if (shapesTypeBag[i] == "PRISM"){
      const Prism* ps = reinterpret_cast<const Prism*>(shapesBag[i]);
      const Prism& rs = *ps;
      rs.output(fout);
    }
    else {
      throw "ERROR";
    }
  }

  fout.close();

  for (unsigned int i = 0; i < shapesBag.size(); i++){
    if (shapesTypeBag[i] == "SQUARE"){
      const Square* const ps = reinterpret_cast<const Square*>(shapesBag[i]);
      delete ps;
    }
    else if (shapesTypeBag[i] == "RECTANGLE"){
      const Rectangle*  const ps = reinterpret_cast<const Rectangle*>(shapesBag[i]);
      delete ps;
    }
    else if (shapesTypeBag[i] == "CIRCLE"){
      const Circle* const ps = reinterpret_cast<const Circle*>(shapesBag[i]);
      delete ps;
    }
    else if (shapesTypeBag[i] == "TRIANGLE"){
      const Triangle* const ps = reinterpret_cast<const Triangle*>(shapesBag[i]);
      delete ps;
    }
    else if (shapesTypeBag[i] == "CUBE"){
      const Cube* ps = reinterpret_cast<const Cube*>(shapesBag[i]);
      delete ps;
    }
    else if (shapesTypeBag[i] == "BOX"){
      const Box* ps = reinterpret_cast<const Box*>(shapesBag[i]);
      delete ps;
    }
    else if (shapesTypeBag[i] == "CYLINDER"){
      const Cylinder* ps = reinterpret_cast<const Cylinder*>(shapesBag[i]);
      delete ps;
    }
    else if (shapesTypeBag[i] == "PRISM"){
      const Prism* ps = reinterpret_cast<const Prism*>(shapesBag[i]);
      delete ps;
    }
    else {
      throw "ERROR";
    }
  }
}

vector<string> parseString(string str){
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}