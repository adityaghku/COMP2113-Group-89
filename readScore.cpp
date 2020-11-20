//readScore.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "readScore.h"
#include "findNumberofCards.h"

using namespace std;

/*
Purpose: calculate the score of a given hand (user or dealer's cards)
Inputs:
  - cards: string array of cards
Outputs:
  - score: sum of point values of all cards
*/
int readScore(string cards[]){
  int maxIndex = findNumberofCards(cards); // see how many cards there are in the array

  int score = 0; // calculate score
  char tempRank;
  for (size_t i = 0; i < maxIndex; i++) {
    tempRank = cards[i][0];
    if(tempRank=='A')score+=1; else if(tempRank=='2')score+=2; else if(tempRank=='3')score+=3;
    else if(tempRank=='4')score+=4; else if(tempRank=='5')score+=5; else if(tempRank=='6')score+=6;
    else if(tempRank=='7')score+=7; else if(tempRank=='8')score+=8; else if(tempRank=='9')score+=9;
    else score+= 10;
  }
  int numberOfAces = 0;
  for (size_t i = 0; i < maxIndex; i++) {
    if (cards[i][0] == 'A') {
      numberOfAces += 1;
      score += 10;
    }
  }
  for (size_t i = 0; i < numberOfAces; i++) {
    if (score > 21) {
      score -= 10;
    }
  }
  return score;
}
