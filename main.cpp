#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h> // for Random Number Generation
#include <ctime> // for Random Number Generation
using namespace std;

//class.cpp
class playerData{
  public:
    string name;
    int wallet = 100;
    string key = "12sdas";

    // fun stats
    int wins;
    int gamesPlayed;
    int winPercentage;
};

//printboard.cpp
int numberofDigits(int n);
void printdealerCards(int n, string dealerCards[15]);
void printplayerCards(int n, string playerCards[15]);
void PrintBoard(int wallet,int currentBet, string playerCards[15], string dealerCards[15], int playerCardsSize, int dealerCardsSize);

//general
int findNumberofCards(string cards[]);

int readScore(string cards[]);
bool User(string playerCards[], string deck[], int &topCardIndex,int &userScore, int &currentBet, int &wallet);
int Dealer(string dealerCards[], string deck[], int &topCardIndex,int &dealerScore, int userScore);
void Winner(int userScore, int dealerScore, int &wallet, int currentBet);
//instructions
void displayInstructions();

int main(){

//------------------------------INSTRUCTIONS --------------------------------------------

  cout << "Do you want to view the instructions? Y or N" << endl; //Instructions
  char instructions;
  cin >> instructions;
  if(instructions=='Y'){
    displayInstructions();
  }

  cout << "Begin game" << endl;

  //------------------------------SET UP GAME --------------------------------------------

  bool mainGameLoop = true; // the boolean variable for the game to continue
  bool didYouWin = false; // if player won previous round
  int wallet = 100;
  int currentBet;
  int userScore, dealerScore; // declare the userScore and dealerScore variables, which will be updated every round
  const string SEPERATOR = ""; // I will use this to store each indiv card and make it more readable - e.g. 7 + SEPERATOR + H refers to 7 of Hearts


  playerData P = { };

  string playerCards[15], dealerCards[15] = {}; // make array of user cards and dealer cards

//------------------------------LOAD GAME FUNCTIONALITY START--------------------------------------------

// SEE BOTTOM OF THIS DOC

//------------------------------LOAD GAME FUNCTIONALITY END--------------------------------------------


  //------------------------------GAME START--------------------------------------------
  while(mainGameLoop){
    cout << "How much do you want to bet (in an increment of 10)" << endl; //bet amount
    cin >> currentBet;
    wallet -= currentBet; //for user board display

    for(int i = 0; i < 15; i++) { // initialize the array of playerCards and dealerCards
        playerCards[i].clear();
        dealerCards[i].clear();
      }
    // -------CREATE DECK OF CARDS ------------
    string deck[52]; //a deck of cards
    string suits[4] = {"\u2764","\u2660","\u25C6", "\u2663"}; // ASCII characters for the 4 different suits
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
    playerCards[0] = deck[0]; // user gets dealt 2 cards
    playerCards[1] = deck[1];
    dealerCards[0] = deck[2]; // dealer gets dealt 2 cards
    dealerCards[1] = deck[3];

    int topCardIndex = 4; // the next card to be dealt will be on index = 4 in the deck array

    // -------DEAL CARDS -----------------------
    PrintBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards)); //Prints table for user visual appeal

    userScore = readScore(playerCards);
    dealerScore = readScore(dealerCards);
    if (readScore(playerCards) == 21){ //checking if the player has blackjack
      wallet+=2.5*currentBet;
      cout << "You have blackjack" << endl;
      PrintBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards));
      didYouWin=true;
    }
    else {
      // -------USER MOVE -----------------------
      bool continueUserTurn = true;
      while (continueUserTurn){ // user turn continues until function returns false

        continueUserTurn = User(playerCards,deck,topCardIndex,userScore, currentBet, wallet);
        PrintBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards));
      }
      for (size_t i = 0; i < findNumberofCards(playerCards); i++) {
        cout << playerCards[i] << ", ";
      }
      cout << endl << "Your final score: " << userScore << endl << endl;

      // -------DEALER MOVE -----------------------
      Dealer(dealerCards, deck, topCardIndex, dealerScore, userScore); // dealer's turn
      cout << endl << "Dealer's score: " << dealerScore << endl;
      PrintBoard(wallet,currentBet, playerCards, dealerCards, findNumberofCards(playerCards), findNumberofCards(dealerCards));
    }

    // ------- Check winner -----------------------
    Winner(userScore, dealerScore, wallet, currentBet);

    // ------- Update database -----------------------
    // updateUsers(playerdata); //update users.txt

    // -------Wallet balance check -----------------------

    if(wallet <= 0){
      cout << "You have no more money left, you lose" << endl; //Money check condition
      mainGameLoop = false;
    }

    // -------Play again check -----------------------
    cout << "Do you want to continue playing? Input Y or N" << endl; // Round playing
    char continueGame;
    cin >> continueGame;
    if(continueGame=='N'){
      mainGameLoop=false;
    }
  }
  // ------- Provide user's with key (given they have money to play again)-----------------------
  if(wallet!=0){
    cout << P.key << " is the key" << endl;
  }

  return 0;
}

//---------------PRINTBOARD START------------------------------------------
int numberofDigits(int n){
  int count = 0;
  while (n != 0){
    n = n / 10;
    ++count;
  }
  return count;
}

void printdealerCards(int n, string dealerCards[15]){
  int l = 34 - 7*(n-1);

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << " ---- " << " ";
    }
    else{
      cout << " ---- " << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(30) << "|" << dealerCards[i] << "   |" << " ";
    }
    else{
      cout << "|" << dealerCards[i] << "   |" << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << "|    |" << " ";
    }
    else{
      cout << "|    |" << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(30) << "|" << "   " << dealerCards[i] << "|" << " ";
    }
    else{
      cout << "|" << "   " << dealerCards[i] << "|" << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << " ---- " << " ";
    }
    else{
      cout << " ---- " << " ";
    }
  }
  cout << setw(l) << "|" << endl;
}

void printplayerCards(int n, string playerCards[15]){
  int l = 34 - 7*(n-1);

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << " ---- " << " ";
    }
    else{
      cout << " ---- " << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(30) << "|" << playerCards[i] << "   |" << " ";
    }
    else{
      cout << "|" << playerCards[i] << "   |" << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << "|    |" << " ";
    }
    else{
      cout << "|    |" << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(30) << "|" << "   " << playerCards[i] << "|" << " ";
    }
    else{
      cout << "|" << "   " << playerCards[i] << "|" << " ";
    }
  }
  cout << setw(l) << "|" << endl;

  for (int i = 0; i < n; i++){
    if (i == 0){
      cout << "|" << setw(35) << " ---- " << " ";
    }
    else{
      cout << " ---- " << " ";
    }
  }
  cout << setw(l) << "|" << endl;
}

void PrintBoard(int wallet,int currentBet, string playerCards[15], string dealerCards[15], int playerCardsSize, int dealerCardsSize){
  cout << setfill('-') << setw(72) << " " << endl;
  cout << setfill(' ');

  cout << "|" << setw(70) << "|" << endl;
  printdealerCards(dealerCardsSize, dealerCards);
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      wallet: " << "$" << wallet;
  int l = 70 - 14 - numberofDigits(wallet);
  cout << setw(l) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      Bet Amount: " << "$" << currentBet;
  l = 70 - 19 - numberofDigits(currentBet);
  cout << setw(l) << "|" << endl;
  printplayerCards(playerCardsSize, playerCards);
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;

  cout << setfill('-') << setw(72) << " " << endl;
}
//---------------PRINTBOARD END------------------------------------------

void displayInstructions(){
  cout << "Instructions will be printed here" << endl;
}

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

bool User(string playerCards[], string deck[], int &topCardIndex,int &userScore, int &currentBet, int &wallet){
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

int Dealer(string dealerCards[], string deck[], int &topCardIndex,int &dealerScore, int userScore){
  cout << "Dealer's cards: ";

  for (size_t i = 0; i < findNumberofCards(dealerCards); i++) {
    cout << dealerCards[i] << ", ";
  }
  // if user has 21 or above, then dealer's turn is over
  if (userScore > 21) return 0;

  // while dealer score less that 17, dealer must Hit
  while (readScore(dealerCards) < 17) {
    dealerCards[findNumberofCards(dealerCards)] = deck[topCardIndex];
    topCardIndex += 1;
    dealerScore = readScore(dealerCards);
    cout << endl << "dealer's cards: ";
    for (size_t i = 0; i < findNumberofCards(dealerCards); i++) {
      cout << dealerCards[i] << ", ";
    }
  }
}

void Winner(int userScore, int dealerScore, int &wallet, int currentBet){
  if (userScore > 21 || dealerScore > userScore) {
    cout << "You Lose" << endl;
  }

  else if (dealerScore > 21 || userScore > dealerScore){
    cout << "You win" << endl;
    wallet+=2*currentBet;
  }

  else{
    cout << "draw" << endl;
    wallet+=currentBet;
  }
}

//------------------------------LOAD GAME FUNCTIONALITY START--------------------------------------------

  //cout << "Load game or New?" << endl; //Load Game or New Game
  //string choice;
  //cin >> choice;

  //if (choice == "Load"){
    //cout << "Please enter your key: " << endl;
    //string inputkey;
    //cin >> inputkey;
    //loadGame(inputkey);
  //}

  //else{
    //cout << "What is your name?" << endl;
    //cin >> name; //Initialise the Cash, name, and key

    //generateKey(&key) //Make key only alphabets for simplicity

  //  cout << "How much money do you want to buy-in?" << endl;
  //  cin >> wallet;

  //  playerData playerdata[i] = {name, wallet, key};
//  }

//------------------------------LOAD GAME FUNCTIONALITY END--------------------------------------------
