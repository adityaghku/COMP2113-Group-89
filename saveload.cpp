#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include "saveload.h"
using namespace std;


string filename = "users.txt";

string generateKey(){
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    string random_string;

    for (size_t i = 0; i < 6; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

int load_data(playerData * &arrayofPlayers, int &arrayofPlayers_size){
  ifstream fin;
  fin.open(filename.c_str());
  if (fin.fail())
  {
      cout << "Error in file opening." << endl;
      return 0;
  }

  int i = 0;
  string line;
  while (getline(fin, line)){
  if (i >= arrayofPlayers_size)
    grow_file(arrayofPlayers, arrayofPlayers_size);

  // extract information from line
  if (i < arrayofPlayers_size) {
        istringstream iss(line);
        if (!getline(iss, arrayofPlayers[i].name,','))
            break;
        string temp;
        if (getline(iss, temp,','))

            arrayofPlayers[i].wallet = stoi(temp);

        if (!getline(iss, arrayofPlayers[i].key))
            break;
        ++i;
    }
  }

  fin.close();
  return i;
}


void grow_file(playerData * &arrayofPlayers, int &arrayofPlayers_size){
	// create a new dynamic array with a new size = max_size + n
	playerData *pd_new = new playerData[arrayofPlayers_size + 3];

	// copy all the records from the original array to the new dynamic array
	for (int i = 0; i < arrayofPlayers_size; i++)
	{
		pd_new[i] = arrayofPlayers[i];
	}

	// destroy the old dynamic array to free up the memory allocated to it
	delete [] arrayofPlayers;
	// assign the pointer to the new dynamic array to the pointer variable
	arrayofPlayers = pd_new;
	// update the size of the array
	arrayofPlayers_size += 3;

	return;
}

int addUser(playerData arrayofPlayers[], int arrayofPlayers_size)
{
	char ans;
	string str;

	getline(cin, str); // flush the keyboard buffer
	cout << "Please enter a name: ";
	getline(cin, arrayofPlayers[arrayofPlayers_size].name);

  cout << "How much money do you want to buy-in?" << endl;
  cin >> arrayofPlayers[arrayofPlayers_size].wallet;

  string key;
  key = generateKey();
  arrayofPlayers[arrayofPlayers_size].key = key;
	cout << endl;
	arrayofPlayers_size++;

	return arrayofPlayers_size;
}

int save_file(string filename, playerData arrayofPlayers[], int arrayofPlayers_size)
{
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i;
    for (i = 0; i < arrayofPlayers_size; i++)
    {
        fout << arrayofPlayers[i].name << "," << arrayofPlayers[i].wallet << "," << arrayofPlayers[i].key << endl;
    }

    fout.close();
    return i;
}
