//user.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "user.h"
#include "findNumberofCards.h"
#include "readScore.h"
using namespace std;

/*
Purpose: provides implementation for accepting and processing user's moves
Inputs:
- playerCards: string array of user's cards
- deck: string array of deck of cards
- topCardIndex: integer index of the 'next' card to be drawn from deck
- userScore: current score of user
- currentBet: user's current bet
- wallet: user's wallet amount
- doubleCheck: a boolean which turns true when the user selects the 'Double' move
Outputs:
  - a boolean which is false if this is the user's last move, and true otherwise
*/
bool user(string playerCards[], string deck[], int &topCardIndex,int &userScore, int &currentBet, int &wallet, bool &doubleCheck){

  char userMove;

  while (true){

    cout << char(27) << "[1m" << "Your moves:" << char(27) << "[0m" << endl<< endl;
    cout<< char(27) << "[1m" << " [H]it: Draw another card" << endl << " [D]ouble: Double initial bet and draw one last card" << endl << " [S]tand: End turn" << endl << endl << "What's the move? " << char(27) << "[0m";


    cin >> userMove;

    if (userMove == 'S' || userMove == 'D' || userMove == 'H'){
      break;
    }
    else{
      cout << "Invalid Input" << endl;
    }
  }

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
        doubleCheck = true;
      }
    }
  }
  //Check score for bust or max score
  if (userScore >= 21) {
    return false;
  }
  return true;
}
