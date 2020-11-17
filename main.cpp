#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//class.cpp
class playerData{
  public:
    string name;
    int wallet;
    string key;

    int wins;
    int gamesPlayed; //Stats
    int winPercentage;
};

//printboard.cpp
int numberofDigits(int n);
void printdealerCards(int n);
void printplayerCards(int n);
void PrintBoard(int wallet,int currentbet, string playerCards[15], string dealerCards[15], int playercards, int dealercards);

//instructions
void displayInstructions();

int main(){

  bool istrue=true,didyouwin=false;
  int wallet,currentbet,cardnumber=0;

  playerData P = { };

  str playerCards[15], dealerCards[15], deck[52];

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

  cout << "Do you want to view the instructions? Y or N" << endl; //Instructions
  char instructions;
  cin >> instructions;
  if(instructions==Y){
    displayInstructions()
  }

  cout << "Begin game" << endl;
  createDeck(&deck); //Adds cards to array in sequential order

  while(istrue){
    cout << "How much do you want to bet (in an increment of 10)" << endl; //bet amount
    cin >> currentbet;
    wallet-=currentbet; //for user board display

    shuffleDeck(&deck); //shuffles the deck
    dealCards(deck,&playerCards,&dealerCards,&cardnumber); //Deals the cards to the player and the dealer

    PrintBoard(wallet,currentbet,playerCards,dealerCards); //Prints table for user visual appeal

    if blackjack(playerCards){ //checking if the player has blackjack
      wallet+=2.5*currentbet;
      cout << "You have blackjack" << endl;
      PrintBoard(wallet,currentbet,playerCards,dealerCards);
      didyouwin=true;
    }
    else{

      bool yourTurn=true,dealerTurn=true;
      while(yourTurn){
        cout << "What move will you make? H, S or D." << endl; //Players turn
        char move;
        cin >> move;

        User(&playerCards,deck,&cardnumber,move,&yourTurn); //Has moves and Printboard inside it, updates yourTurn on every move
      }

      while(dealerTurn){
        Dealer(&dealerCards,deck,&cardnumber,&dealerTurn); //Dealers Turn has PrintBoard inside it
      }
    }

    if(YouWon(playerCards,dealerCards)){ //Determine winner of game
      didyouwin=true;
    }

    if(didyouwin){ //Update bet amount of the player
      wallet+=2*currentbet
      cout << "You win" << endl;
      PrintBoard(wallet,currentbet,playerCards,dealerCards);
    }

    else{
      cout << "You lose" << endl;
      PrintBoard(wallet,currentbet,playerCards,dealerCards);
    }

    updateUsers(playerdata); //update users.txt

    if(wallet==0){
      cout << "You have no more money left, you lose" << endl; //Money check condition
      istrue=false;
    }

    cout << "Do you want to continue playing? Input Y or N" << endl; // Round playing
    char continue;
    cin >> continue;
    if(continue=='N'){
      istrue=false;
    }
  }

  if(wallet!=0){
    cout << playerdata.key << " is the key";
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

void printdealerCards(int n){
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

void printplayerCards(int n){
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

void PrintBoard(int wallet,int currentbet, string playerCards[15], string dealerCards[15], int playercards, int dealercards){
  cout << setfill('-') << setw(72) << " " << endl;
  cout << setfill(' ');

  cout << "|" << setw(70) << "|" << endl;
  printdealerCards(dealercards);
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      wallet: " << "$" << wallet;
  int l = 70 - 14 - numberofDigits(wallet);
  cout << setw(l) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      Bet Amount: " << "$" << currentbet;
  l = 70 - 19 - numberofDigits(currentbet);
  cout << setw(l) << "|" << endl;
  printplayerCards(playercards);
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;

  cout << setfill('-') << setw(72) << " " << endl;
}
//---------------PRINTBOARD END------------------------------------------

void displayInstructions(){
  cout << "Instructions will be printed here" << endl;
}
