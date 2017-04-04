#ifndef _FILE_H
#define _FILE_H

#include <iostream>

class File
{
  std::string name;

 public:
  File(std::string x = ""){
    name = x;
  }

  void append(int, int);  
  void append(std::string, std::string);
  void append(int);  
  int check_sectn(std::string, std::string);
  int returnrow(int);
  int returncolumn(int);
  int returntime(int);
};

#endif
