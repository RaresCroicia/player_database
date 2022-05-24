#include "player.hpp"
#include <bits/stdc++.h>

Player::Player(){
    
}

Player::Player(personal_data p, gamer_data g, login_data l){
    p_data = p;
    g_data = g;
    l_data = l;
}

personal_data Player::get_personal_data(){
    return p_data;
}

gamer_data Player::get_gamer_data(){
    return g_data;
}

login_data Player::get_login_data(){
    return l_data;
}

void Player::set_personal_data(personal_data p){
    p_data = p;
}

void Player::set_gamer_data(gamer_data g){
    g_data = g;
}

void Player::set_login_data(login_data l){
    l_data = l;
}

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

map<string,bool> load_emails(vector<Player> database){
    map<string,bool> mails;
    for(int i = 0; i < database.size(); i++){
        mails.insert(pair<string,int>(database[i].get_login_data().email, true));
    }
    return mails;
}

map<string,bool> load_users(vector<Player> database){
    map<string,bool> users;
    for(int i = 0; i < database.size(); i++){
        users.insert(pair<string,int>(database[i].get_login_data().username, true));
    }
    return users;
}

void register_form(vector<Player>& database, map<string,bool> emails, map<string, bool> users){
    printf("\nWelcome to the registration page!\n");
    string email, user;
    printf("Insert your email: ");
    cin >> email;
    if(emails[email]){
        printf("Email already used!\n");
        printf("Do you want to start again? [Yes/No]\n");
        string choice;
        cin >> choice;
        if(choice == "Yes")
            register_form(database, emails, users);
        else
            return;
    }
    printf("Insert your user: ");
    cin >> user;
    if(users[user]){
        printf("User already used!\n");
        printf("Do you want to start again? [Yes/No]\n");
        string choice;
        cin >> choice;
        if(choice == "Yes")
            register_form(database, emails, users);
        else
            return;
    }
    printf("Insert your password: ");
    string password, secondtry;
    cin >> password;
    printf("Insert your password again: ");
    cin >> secondtry;
    if(password != secondtry){
        printf("Passwords don't match!\n");
        printf("Do you want to start again? [Yes/No]\n");
        string choice;
        cin >> choice;
        if(choice == "Yes")
            register_form(database, emails, users);
        else
            return;
    }
    Player to_add;
    to_add.set_login_data({email, user, password});

    string first_name, last_name;
    int age;
    printf("Insert your first name: ");
    cin >> first_name;
    printf("Insert your last name: ");
    cin >> last_name;
    printf("Insert your age: ");
    cin >> age;
    to_add.set_personal_data({first_name, last_name, age});

    string IGN;
    int no_games;
    vector<string> games;
    printf("Insert your IGN: ");
    cin >> IGN;
    printf("Insert the number of games you play: ");
    cin >> no_games;
    fgetc(stdin);
    for(int i = 0; i < no_games; i++){
        printf("Game #%d:\n", i);
        char tmp[256];
        fgets(tmp, 256, stdin);
        tmp[strcspn(tmp, "\n")] = '\0';
        games.push_back(string(tmp));
    }
    to_add.set_gamer_data({IGN, no_games, games});
    database.push_back(to_add);
    printf("Numarul de elemente din database: %ld\n", database.size());
    printf("You have been registered!\n");

}
