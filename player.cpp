#include "player.hpp"
#include <bits/stdc++.h>

Player::Player(){
    fprintf(stderr, "You forgot to add the arguments");
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

