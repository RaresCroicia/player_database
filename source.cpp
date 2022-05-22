#include <bits/stdc++.h>
#include "player.hpp"
#include "utils.hpp"
using namespace std;

void output_data(char output[], vector<Player> players){
    ofstream fout(output);
    for(int i = 0; i < players.size(); i++){
        fout << players[i].get_personal_data().first_name << " " << players[i].get_personal_data().last_name << '\n';
        fout << players[i].get_personal_data().age << '\n';
        fout << players[i].get_gamer_data().IGN << '\n' << players[i].get_gamer_data().no_games << '\n';
        for(int j = 0; j < players[i].get_gamer_data().no_games; j++)
            fout << players[i].get_gamer_data().games[j] << '\n';
        fout << players[i].get_login_data().email << '\n';
        fout << players[i].get_login_data().username << '\n';
        fout << players[i].get_login_data().password;
        if(i < players.size() - 1)
            fout << '\n';
    }
    fout.close();
}

int main(){
    
    char database[256];
    printf("Name of the database file with extension: ");
    fscanf(stdin, "%s", database);
    FILE* input = get_input(database);
    personal_data p;
    gamer_data g;
    login_data l;

    printf("Inserting data ...\n");
    vector<Player> players_database;
    while(get_data(input, p, g, l)){
        players_database.push_back(Player(p, g, l));
    }
    printf("Data inserted!\n");
    fclose(input);
    printf("Name of the database to update: ");
    fscanf(stdin, "%s", database);
    FILE* output = get_output(database);
    fclose(output);
    printf("Writing data to %s ...\n", database);
    output_data(database, players_database);
    printf("Data written!\n");
    return 0;
}