//README: have not implemented blackjack funcitonality + double bet functionality + double value of A
//READMEL need to figure out how to incorporate findNumberofCards

#include<iostream>
#include <stdlib.h> // for Random Number Generation
#include <ctime> // for Random Number Generation
#include <string>
using namespace std;

int findNumberofCards(string cards[]){
  int numberofCards = 0;
  while (!(cards[numberofCards].empty())) {
    numberofCards++;
  }
  return numberofCards;
}
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
  return score;
}

bool User(string userCards[], string deck[], int &topCardIndex,int &userScore){
  for (size_t i = 0; i < findNumberofCards(userCards); i++) {
    cout << userCards[i] << ", ";
  }
  cout << endl << " Score: " << userScore << endl;

  cout<< "[H]it: draw one more card" << endl;
  cout << "[D]ouble: double initial bet and draw one last card" << endl;
  cout << "[S]tand: end turn" << endl << "What's the move? ";

  char userMove;
  cin >> userMove;

  if (userMove == 'S') return false;
  else{ // if not Stand then must be Hit or Double --> must draw an additional card
    userCards[findNumberofCards(userCards)] = deck[topCardIndex];
    topCardIndex += 1;
    userScore = readScore(userCards);
  }

  //Check score for bust or max score
  if (userScore >= 21) {
    return false;
  }
  return true;
}


int main(){
  const string SEPERATOR = " of "; // I will use this to store each indiv card and make it more readable - e.g. 7 + SEPERATOR + H refers to 7 of Hearts
  const int MAXCARDS = 15; //max number of cards a user or dealer can possibly have

  string userCards[15]; //make array of user cards
  string dealerCards[15]; //make array of dealer cards


  // -------CREATE DECK OF CARDS ------------
  string deck[52]; //a deck of cards
  string suits[4] = {"S","C","H","D"};
  string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 13; j++) {
      deck[13*i + j] = ranks[j] + SEPERATOR + suits[i];
    }
  }

  // -------SHUFFLE THIS DECK OF CARDS ------------
  string holderString;
  int randomIndex;
  srand(time(NULL));
  for (size_t i = 0; i < 52; i++) {
    randomIndex = rand() % 52;
    holderString = deck[i];
    deck[i] = deck[randomIndex];
    deck[randomIndex] = holderString;
  }
  // for (size_t i = 0; i < 52; i++) {
  //   cout << deck[i] << endl;
  // }

  // -------DEAL CARDS -----------------------
  userCards[0] = deck[0]; // user gets dealt 2 cards
  userCards[1] = deck[1];
  dealerCards[0] = deck[2]; // dealer gets dealt 2 cards
  userCards[1] = deck[3];

  int topCardIndex = 4; // the next card to be dealt will be on index = 4 in the deck array

  // ---NOTE THAT BLACKJACK CHECK WAS SKIPPED-----------
  //
  //

  // -------USER MOVE -----------------------
  int userScore = readScore(userCards);

  bool continueUserTurn = true;
  while (continueUserTurn){ // user turn continues until function returns false

    continueUserTurn = User(userCards,deck,topCardIndex,userScore);
  }
  for (size_t i = 0; i < findNumberofCards(userCards); i++) {
    cout << userCards[i] << ", ";
  }
  cout << endl << "Your final score: " << userScore << endl;

}
