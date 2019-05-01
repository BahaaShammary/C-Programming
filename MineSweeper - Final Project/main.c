#include <stdio.h>
#include <stdlib.h>
#include "game_functions.h"
#include <string.h>
#include <time.h>

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

    pbombs[0].x = 1;
    pbombs[0].y  = 1;
    pbombs[0].found = false;

    pbombs[1].x = 2;
    pbombs[1].y  = 3;
    pbombs[1].found = false;

    int size = DIM;

    if (argc == 2) {
        printf("Please provide the command line arguments:");
    }
    time_t t;
    srand((unsigned) time(&t));

    int i,r0,r1, r2,r3,r4,r5;
    for (i = 0; i<5;i++) {
        r0 = rand() % 4; // create the random number then assign it to a row
        if (i == 0) {
            r1 = r0;
        }
        else if (i == 1) {
            r2 = r0;
        }
        else if (i == 2) {
            r3 = r0;
        }
        else if (i == 3) {
            r4 = r0;
        }
        else if (i == 4) {
            r5 = r0;
        }
    }
    printf("r1 -> \n%d\n", r1);
    printf("r2 -> %d\n", r2);
//    printf("r3 -> %d\n", r3);
//    printf("r4 -> %d\n", r4);
//    printf("r5 -> %d\n", r5);

    int j,c0,c1, c2,c3,c4,c5;
    for (j = 0; j<5;j++) {
        c0 = rand() % 4; // create the random number then assign it to a column
        if (j == 0) {
            c1 = c0;
        }
        else if (j == 1) {
            c2 = c0;
        }
        else if (j == 2) {
            c3 = c0;
        }
        else if (j == 3) {
            c4 = c0;
        }
        else if (j == 4) {
            c5 = c0;
        }
    }

    printf("\nc1 -> %d\n", c1);
    printf("c2 -> %d\n", c2);
//    printf("c3 -> %d\n", c3);
//    printf("c4 -> %d\n", c4);
//    printf("c5 -> %d\n", c5);

    // check if the two random numbers are the coordinates of a bomb, if so, create two new random numbers and check them again
    bool again = true;
    while (again) {
        if (r1 == pbombs[0].x && c1 == pbombs[0].y) {
            r1 = rand() % 4;
            c1 = rand() % 4;
            printf("r1 %d c1 %d", r1, c1);
            again = true;
        }
        else if (r2 == pbombs[1].x && c2 == pbombs[1].y) {
            r2 = rand() % 4;
            c2 = rand() % 4;
            printf("r2 %d c2 %d", r2, c2);
            again = true;
        }
        else {
            known_location_info[r1][c1] = bomb_location_info[r1][c1];
            known_location_info[r2][c2] = bomb_location_info[r2][c2];
            again = false;
        }
    }














    int compare = strcmp(argv[1], "clues");
    int compare1 = strcmp(argv[1], "noclues");

    if (compare ==0 ) {
        printf("\nCLUES\n");
        start_game(pbombs, bomb_location_info, DIM, known_location_info, of_bombs);
    }
    else if (compare1 == 0) {
        printf("\nNOCLUES\n");
        start_game(pbombs, bomb_location_info, DIM, known_location_info, of_bombs);
    }

    free(pbombs);

    return 0;
}