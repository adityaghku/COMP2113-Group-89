//winner.cpp

#include <iostream>
#include "winner.h"
using namespace std;

/*
Purpose: evaluates the winner of the game and makes adjustments to the user's wallet
Inputs:
  - userScore: score of user for this round
  - dealerScore: score of dealer for this round
  - wallet: user's wallet amount
  - currentBet: user's current bet
  - blackjack: a boolean which is true if the user won via blackjack, and false otherwise
Outputs:
- randomIndex
*/
void winner(int userScore, int dealerScore, int &wallet, int currentBet, bool blackjack){
  if (blackjack){
      //
  }
  else if (userScore > 21) {
    cout << endl << char(27) << "[1m" << "What a shame…you lost." << char(27) << "[0m" << endl;

  }
  else if (dealerScore > userScore && dealerScore <= 21){
    cout << endl << char(27) << "[1m" << "What a shame…you lost." << char(27) << "[0m" << endl;
  }

  else if (dealerScore > 21 || userScore > dealerScore){
    cout << endl << char(27) << "[1m" << "Congratulations on your win!" << char(27) << "[0m" << endl;
    wallet+=2*currentBet;
  }

  else{
    cout << endl << char(27) << "[1m" << "It's a draw!!" << char(27) << "[0m" << endl;
    wallet+=currentBet;
  }
}
