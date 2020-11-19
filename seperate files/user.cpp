//user.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "user.h"
#include "findNumberofCards.h"
#include "readScore.h"
using namespace std;

bool user(string playerCards[], string deck[], int &topCardIndex,int &userScore, int &currentBet, int &wallet){
  for (size_t i = 0; i < findNumberofCards(playerCards); i++) {
    cout << playerCards[i] << ", ";
  }
  cout << endl << " Score: " << userScore << endl;

  cout<< "[H]it: draw one more card" << endl;
  cout << "[D]ouble: double initial bet and draw one last card" << endl;
  cout << "[S]tand: end turn" << endl << "What's the move? ";

  char userMove;
  cin >> userMove;

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
