#ifndef __utils__
#define __utils__
#include <bits/stdc++.h>
using namespace std;

typedef struct pd{
    string first_name, last_name;
    int age;
} personal_data;

typedef struct gd{
    string IGN;
    int no_games;
    vector<string> games;
}gamer_data;

typedef struct ld{
    string email, username, password;
}login_data;

int get_data(FILE*, personal_data&, gamer_data&, login_data&);
FILE* get_input(char filename[]);
FILE* get_output(char filename[]);

#endif