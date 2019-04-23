#include <stdio.h>
#include <stdlib.h>
#include "game_functions.h"
//
// Created by Bahaulddin
//
int main() {
    int bomb_location_info[4][4] =     { 1,1,1,0,
                                         1,0,2,1,
                                         1,1,2,0,
                                         0,0,1,1};

    int known_location_info[4][4] =  {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN,
                                      UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN,
                                      UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN,
                                      UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN};

    int of_bombs = 2;
    struct locations* pbombs = (struct locations * ) malloc(sizeof(struct locations)  * 2) ;

    pbombs[0].x = 1;
    pbombs[0].y  = 1;
    pbombs[0].found = false;

    pbombs[1].x = 2;
    pbombs[1].y  = 3;
    pbombs[1].found = false;

    int size = DIM;


    start_game(pbombs, bomb_location_info, DIM, known_location_info, of_bombs);

    free(pbombs);

    return 0;
}