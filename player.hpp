#ifndef __player__
#define __player__
#include <bits/stdc++.h>
#include "utils.hpp"
using namespace std;

class Player{
private:
    personal_data p_data;
    gamer_data g_data;
    login_data l_data;
public:
    Player();
    Player(personal_data, gamer_data, login_data);
    //Player(string, string, string, int, string, int, vector<string>, string, string, string);
    personal_data get_personal_data();
    gamer_data get_gamer_data();
    login_data get_login_data();
    void set_personal_data(personal_data);
    void set_gamer_data(gamer_data);
    void set_login_data(login_data);
};

#endif