// saveload.h
#ifndef SAVELOAD_H
#define SAVELOAD_H

class playerData{
  public:
    std::string name;
    int wallet;
    std::string key;
};

std::string generateKey();
int load_data(playerData * &arrayofPlayers, int &arrayofPlayers_size);
void grow_file(playerData * &arrayofPlayers, int &arrayofPlayers_size);
void addUser(playerData * &arrayofPlayers, int &numberofPlayers, int arrayofPlayers_size);
int save_file(std::string filename, playerData arrayofPlayers[], int arrayofPlayers_size);


#endif
