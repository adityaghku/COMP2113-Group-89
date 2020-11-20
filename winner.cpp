//winner.cpp

#include <iostream>
#include "winner.h"
using namespace std;

void winner(int userScore, int dealerScore, int &wallet, int currentBet){
  if (userScore==21){
    cout << endl;
  }
  else if (userScore > 21 || dealerScore > userScore) {
    cout << "You Lose!" << endl;
  }

  else if (dealerScore > 21 || userScore > dealerScore){
    cout << "You Win!" << endl;
    wallet+=2*currentBet;
  }

  else{
    cout << "Draw" << endl;
    wallet+=currentBet;
  }
}
