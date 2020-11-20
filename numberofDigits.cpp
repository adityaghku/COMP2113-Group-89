//numberofDigits.cpp
#include <iostream>
#include <iomanip>
using namespace std;

/*
Purpose:
Inputs:
  - x:
Outputs:
  - y:
*/
int numberofDigits(int n){
  int count = 0;
  while (n != 0){
    n = n / 10;
    ++count;
  }
  return count;
}
