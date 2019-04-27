#include <stdio.h>
#include <stdlib.h>
#include "game_functions.h"
#include <string.h>

//
// Created by Bahaulddin
//
int main(int argc, char* argv[]) {
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
//    printf("Number of bombs %d\n", of_bombs);
//    printf("Number of argc %d\n", argc);
//    printf("clues? %s 1\n", argv[1]);

    if (argc == 2) {
        printf("Please provide the command line arguments");
    }
    int i;
    for (i=0;i<argc;i++) {
        printf("\n%s ", argv[i]);
    }
    printf("\nNumber of bombs %d", of_bombs);
    int compare = strcmp(argv[1], "clues");
    int compare1 = strcmp(argv[1], "noclues");

    int k;
    int randomNum1;
    int randomNum2;
    for (k=0;k<2;k++) {
        randomNum1 = rand() % 3 + 1;
        randomNum2 = rand() % 3 + 1;
        printf("\nrandom1: %d random2: %d\n", randomNum1, randomNum2);
        known_location_info[randomNum1][randomNum2] = bomb_location_info[randomNum1][randomNum2];
        known_location_info[randomNum1][randomNum2] = bomb_location_info[randomNum1][randomNum2];
    }


    if (compare ==0 ) {
        printf("\nCLUES\n");

        pbombs[0].x = 1;
        pbombs[0].y  = 1;
        pbombs[0].found = false;

        pbombs[1].x = 2;
        pbombs[1].y  = 3;
        pbombs[1].found = false;

        int size = DIM;

        start_game(pbombs, bomb_location_info, DIM, known_location_info, of_bombs);
    }
    else if (compare1 == 0) {
        printf("\nNOCLUES\n");
        pbombs[0].x = 1;
        pbombs[0].y  = 1;
        pbombs[0].found = false;

        pbombs[1].x = 2;
        pbombs[1].y  = 3;
        pbombs[1].found = false;

        int size = DIM;

        start_game(pbombs, bomb_location_info, DIM, known_location_info, of_bombs);
    }

    free(pbombs);

    return 0;
}