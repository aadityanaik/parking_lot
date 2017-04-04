#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "file.h"

using namespace std;

int File::check_sectn(string username, string password)
{
  int sectn = 1;
  bool flag = false;
  string x, y;
  int row, column, time_in;
  ifstream iFile(name);
  while(iFile){
    iFile >> row >> column;
    iFile.ignore();
    getline(iFile, x);
    getline(iFile, y);
    iFile >> time_in;
    //cout << row << " " << column << endl << x << endl << y << endl << time_in << endl;
    //if(!(strcmp(x.c_str(), username.c_str()))&& !(strcmp(y.c_str(), password.c_str()))){
    if(!x.compare(username) && !y.compare(password)){
      flag = true;
      break;
    }
    else
      sectn++;
  }
  iFile.close();

  if(!flag){
    return 0;
  }
  
  else
    return sectn;
}

void File::append(int row, int column)
{
  ofstream oFile(name, ios::app);

  oFile << row << " " << column << endl;

  oFile.close();
}

void File::append(int time_in)
{
  ofstream oFile(name, ios::app);

  oFile << time_in << endl;

  oFile.close();
}

void File::append(string username, string password)
{
  ofstream oFile(name, ios::app);

  oFile << username << endl << password << endl;

  oFile.close();
}

int File::returnrow(int sectn)
{
  ifstream iFile(name);
  int row, column, time_in;
  string x, y;

  for(int i = 1; i <= sectn; i++){
    iFile >> row >> column;
    iFile.ignore();
    getline(iFile, x);
    getline(iFile, y);
    iFile >> time_in;
  }

  return row;
}

int File::returncolumn(int sectn)
{
  ifstream iFile(name);
  int row, column, time_in;
  string x, y;

  for(int i = 1; i <= sectn; i++){
    iFile >> row >> column;
    iFile.ignore();
    getline(iFile, x);
    getline(iFile, y);
    iFile >> time_in;
  }

  return column;
}

int File::returntime(int sectn)
{
  ifstream iFile(name);
  int row, column, time_in;
  string x, y;

  for(int i = 1; i <= sectn; i++){
    iFile >> row >> column;
    iFile.ignore();
    getline(iFile, x);
    getline(iFile, y);
    iFile >> time_in;
  }

  return time_in;
}
