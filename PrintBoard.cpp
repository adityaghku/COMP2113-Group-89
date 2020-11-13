#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int numberofDigits(int n){
  int count = 0;
  while (n != 0){
    n = n / 10;
    ++count;
  }
  return count;
}

int purse = 400, currentbet = 100, playercards = 3, dealercards = 3;
string playerCards[15] = {"A", "3", "Q"}, dealerCards[15] = {"3","K", "2"};

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

void PrintBoard(int purse,int currentbet, string playerCards[15], string dealerCards[15], int playercards, int dealercards){
  cout << setfill('-') << setw(72) << " " << endl;
  cout << setfill(' ');

  cout << "|" << setw(70) << "|" << endl;
  printdealerCards(dealercards);
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << setw(70) << "|" << endl;
  cout << "|" << "      Purse: " << "$" << purse;
  int l = 70 - 14 - numberofDigits(purse);
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


int main(){
  PrintBoard(purse, currentbet, playerCards, dealerCards, playercards, dealercards);
}
