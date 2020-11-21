//numberofDigits.cpp
#include <iostream>
#include <iomanip>
using namespace std;

/*
Purpose: To ease printing, returns number of digits of an integer
Inputs:
  - x: An integer
Outputs:
  - y: The number of digits in that integer
*/
int numberofDigits(int n){
  int count = 0;
  while (n != 0){
    n = n / 10;
    ++count;
  }
  return count;
}
