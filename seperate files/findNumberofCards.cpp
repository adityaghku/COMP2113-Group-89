//findNumberofCards.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "findNumberofCards.h"
using namespace std;

int findNumberofCards(string cards[]){
  int numberofCards = 0;
  while (!(cards[numberofCards].empty())) {
    numberofCards++;
  }
  return numberofCards;
}
