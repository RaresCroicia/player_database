#include <bits/stdc++.h>
#include "utils.hpp"

int get_data(FILE* file, personal_data &p, gamer_data &g, login_data &l){
    if(feof(file))
        return 0;
    char tempBuff[256];
    strcpy(tempBuff, "\0");
    fscanf(file, "%s", tempBuff);
    p.first_name = string(tempBuff);
    strcpy(tempBuff, "\0");
    fscanf(file, "%s", tempBuff);
    p.last_name = string(tempBuff);
    strcpy(tempBuff, "\0");
    fscanf(file, "%d", &p.age);
    fscanf(file, "%s", tempBuff);
    g.IGN = string(tempBuff);
    strcpy(tempBuff, "\0");
    fscanf(file, "%d", &g.no_games);
    fgetc(file);
    while(!g.games.empty())
        g.games.pop_back();
    for(int i = 0; i < g.no_games; i++){
        fscanf(file, "%[^\n]s", tempBuff);
        g.games.push_back(string(tempBuff));
        strcpy(tempBuff, "\0");
        fgetc(file);
    }
    fscanf(file, "%s", tempBuff);
    l.email = string(tempBuff);
    strcpy(tempBuff, "\0");
    fscanf(file, "%s", tempBuff);
    l.username = string(tempBuff);
    strcpy(tempBuff, "\0");
    fscanf(file, "%s", tempBuff);
    l.password = string(tempBuff);
    strcpy(tempBuff, "\0");

    return 1;
}


FILE* get_input(char filename[]){
    FILE *input = fopen(filename, "r");
    if(input == NULL){
        fprintf(stderr, "Input file doesn't exist! Quitting program ...\n");
        exit(EXIT_FAILURE);
    }
    printf("File %s loaded!\n", filename);
    return input;
}

FILE* get_output(char filename[]){
    FILE* output = fopen(filename, "w");
    if(output == NULL){
        fprintf(stderr, "Output file doesn't exist! Quitting program ...\n");
        exit(EXIT_FAILURE);
    }
    printf("File %s loaded\n", filename);
    return output;
}