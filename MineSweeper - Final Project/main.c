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

    pbombs[0].x = 0;
    pbombs[0].y  = 0;
    pbombs[0].found = false;

    pbombs[1].x = 2;
    pbombs[1].y  = 3;
    pbombs[1].found = false;

    int size = DIM;
    printf("argv[2] string %s\n", argv[2]);
    int num = atoi(argv[2]);
    printf("Converted argv[2] to int %d\n", num);

    if (argc == 3) {
        printf("Please enter \"clues\" or \"noclues\" :");
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
    printf("\nr1 %d c1 %d\n", r1, c1);
    printf("r2 %d c2 %d\n", r2, c2);


    // check if the two random numbers are the coordinates of a bomb, if so, create two new random numbers and check them again
    bool again = true;
    while (again) {
        if ((r1 == pbombs[0].x && c1 == pbombs[0].y) || (r1 == pbombs[1].x && c1 == pbombs[1].y)) {
            r1 = rand() % 4;
            c1 = rand() % 4;
//            printf("r1 %d c1 %d", r1, c1);
            again = true;
        }
        else if ((r2 == pbombs[1].x && c2 == pbombs[1].y) || (r2 == pbombs[0].x && c2 == pbombs[0].y)) {
            r2 = rand() % 4;
            c2 = rand() % 4;
//            printf("r2 %d c2 %d", r2, c2);
            again = true;
        }
        else {
            known_location_info[r1][c1] = bomb_location_info[r1][c1];
            known_location_info[r2][c2] = bomb_location_info[r2][c2];
            again = false;
        }
    }
    // getting the user's input
    int compare = strcmp(argv[1], "clues");
    int compare1 = strcmp(argv[1], "noclues");

    if (compare ==0 ) {
        printf("CLUES\n");
        printf("r3 %d c3 %d\n", r3, c3);
        printf("r4 %d c4 %d\n", r4, c4);
        printf("r5 %d c5 %d\n", r5, c5);

        bool again = true;
        while (again) {
            if ((r3 == pbombs[0].x && c3 == pbombs[0].y) || (r3 == pbombs[1].x && c3 == pbombs[1].y)) {
                r3 = rand() % 4;
                c3 = rand() % 4;
//                printf("r3 %d c3 %d", r3, c3);
                again = true;
            }
            else if ((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2)) {
                r3 = rand() % 4;
                c3 = rand() % 4;
//                printf("r3 %d c3 %d", r3, c3);
                again = true;
            }
            else if ((r4 == pbombs[0].x && c4 == pbombs[0].y) || (r4 == pbombs[1].x && c4 == pbombs[1].y)) {
                r4 = rand() % 4;
                c4 = rand() % 4;
//                printf("r4 %d c4 %d", r4, c4);
                again = true;
            }
            else if ((r4 == r1 && c4 == c1) || (r4 == r2 && c4 == c2)) {
                r4 = rand() % 4;
                c4 = rand() % 4;
//                printf("r4 %d c4 %d", r4, c4);
                again = true;
            }
            else if ((r5 == pbombs[0].x && c5 == pbombs[0].y) || (r5 == pbombs[1].x && c5 == pbombs[1].y)) {
                r5 = rand() % 4;
                c5 = rand() % 4;
//                printf("r5 %d c5 %d", r5, c5);
                again = true;
            }
            else if ((r5 == r1 && c5 == c1) || (r5 == r2 && c5 == c2)) {
                r5 = rand() % 4;
                c5 = rand() % 4;
//                printf("r5 %d c5 %d", r5, c5);
                again = true;
            }

            else {
                known_location_info[r3][c3] = bomb_location_info[r3][c3];
                known_location_info[r4][c4] = bomb_location_info[r4][c4];
                known_location_info[r5][c5] = bomb_location_info[r5][c5];
                again = false;
            }
        }

        start_game(pbombs, bomb_location_info, DIM, known_location_info, of_bombs);
    }
    else if (compare1 == 0) {
        printf("\nNOCLUES\n");
        start_game(pbombs, bomb_location_info, DIM, known_location_info, of_bombs);
    }

    free(pbombs);

    return 0;
}