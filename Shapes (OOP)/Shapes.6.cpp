//Programmer: Hao Tran
//ID: 1872272

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "pShapes.h"

vector<string> parseString(string);

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  ifstream fin;
  fin.open("Shapes.input.txt");
  vector<const Shape*> shapesBag;

  while (fin.good()){
    string curLine;
    getline(fin, curLine);
    vector<string> lineElems = parseString(curLine);
    if(lineElems.size() != 0){
      checkShape(lineElems, shapesBag);
    }
  }
  fin.close();

  for (unsigned int i = 0; i < shapesBag.size(); i++){
    cout << *shapesBag[i];
  }

  ofstream fout;
  fout.open("Shapes.output.txt");

  for (unsigned int i = 0; i < shapesBag.size(); i++){
    fout << *shapesBag[i];
  }

  fout.close();

  for (unsigned int i = 0; i < shapesBag.size(); i++){
    delete shapesBag[i];
  }
}

vector<string> parseString(string str){
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}