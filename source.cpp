#include <bits/stdc++.h>
#include "player.hpp"
#include "utils.hpp"
using namespace std;



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

    map<string, bool> emails = load_emails(players_database);
    map<string, bool> users = load_users(players_database);
    register_form(players_database, emails, users);
    
    
    printf("Name of the database to update: ");
    fscanf(stdin, "%s", database);
    FILE* output = get_output(database);
    fclose(output);
    printf("Writing data to %s ...\n", database);
    output_data(database, players_database);
    printf("Data written!\n");
    return 0;
}