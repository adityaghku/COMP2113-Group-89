//printDealerCards.cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Purpose:
Inputs:
  - x:
Outputs:
  - y:
*/
void printDealerCards(int n, string dealerCards[15], bool userfinished){
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
      char temp;
      temp = dealerCards[i][0];
      if (temp=='1'){
        cout << "|" << setw(30) << "|";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << " |" << " ";
        }
        else{
          cout << "    |" << " ";
        }
      }
      else{
        cout << "|" << setw(30) << "|";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "  |" << " ";
        }
        else{
          cout << "    |" << " ";
        }
      }
    }
    else{
      char temp;
      temp = dealerCards[i][0];
      if (temp=='1'){
        cout << "|";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << " |" << " ";
        }
        else{
          cout << "    |" << " ";
        }

      }
      else{
        cout << "|";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "  |" << " ";
        }
        else{
          cout << "    |" << " ";
        }
      }
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
      char temp;
      temp = dealerCards[i][0];
      if (temp=='1'){
        cout << "|" << setw(30) << "|" << " ";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "|" << " ";
        }
        else{
          cout << "   |" << " ";
        }
      }
      else{
        cout << "|" << setw(30) << "|" << "  ";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "|" << " ";
        }
        else{
          cout << "   |" << " ";
        }

      }
    }
    else{
      char temp;
      temp = dealerCards[i][0];
      if (temp=='1'){
        cout << "|" << " ";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "|" << " ";
        }
        else{
          cout << "   |" << " ";
        }
      }
      else{
        cout << "|" << "  ";
        if(userfinished || i==0 ){
          cout << dealerCards[i] << "|" << " ";
        }
        else{
          cout << "  |" << " ";
        }

      }
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
