//user.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "user.h"
#include "findNumberofCards.h"
#include "readScore.h"
using namespace std;

bool user(string playerCards[], string deck[], int &topCardIndex,int &userScore, int &currentBet, int &wallet){
  cout << "Your hand is: ";
  for (size_t i = 0; i < findNumberofCards(playerCards) - 1; i++) {
    cout << playerCards[i] << ", ";
  }
  cout << playerCards[findNumberofCards(playerCards) - 1] << endl;

  cout<< "[H]it: Draw another card" << endl;
  cout << "[D]ouble: Double initial bet and draw one last card" << endl;
  cout << "[S]tand: End turn" << endl << "What's the move? ";

  char userMove;
  cin >> userMove;
  cout << endl;
  if (userMove == 'S') return false;
  else{ // if not Stand then must be Hit or Double --> must draw an additional card
    playerCards[findNumberofCards(playerCards)] = deck[topCardIndex];
    topCardIndex += 1;
    userScore = readScore(playerCards);
    if (userMove == 'D'){
      if (wallet > currentBet) {
        wallet -= currentBet;
        currentBet = 2 * currentBet;
        return false;
      }
      else{
        cout << "You can not double your bet, but you can draw an extra card" << endl;
      }
    }
  }
  //Check score for bust or max score
  if (userScore >= 21) {
    return false;
  }
  return true;
}
