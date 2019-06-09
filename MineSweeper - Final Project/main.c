#include <stdio.h>
#include <stdlib.h>
#include "game_functions.h"
#include <string.h>
#include <time.h>

//
// Created by Bahaulddin
//
int main(int argc, char* argv[]) {
    time_t t;
    srand((unsigned) time(&t));

    int bomb_location_info[4][4] =     { 0,0,0,0,
                                         0,0,0,0,
                                         0,0,0,0,
                                         0,0,0,0};

    int known_location_info[4][4] =  {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN,
                                      UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN,
                                      UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN,
                                      UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN};

//    printf("argv[2] string %s\n", argv[2]);
    int num = atoi(argv[2]);
//    printf("Converted argv[2] to int %d\n", num);
    int of_bombs = num;
//    printf("Number of bombs %d", of_bombs);
    struct locations* pbombs = (struct locations * ) malloc(sizeof(struct locations)  * 2) ;

    // Creating the random coordinates of x and y for the bombs
    int i = 0;
    int x,y;
    for (i = 0; i<of_bombs;i++) {
        x = rand() % 4; // create the random number then assign it to a row
        y = rand() % 4; // create the random number then assign it to a row
        printf("\nx %d y %d", x, y);

        pbombs[i].x = x;
        pbombs[i].y  = y;
        pbombs[i].found = false;

    }
//    pbombs[0].x = 3;
//    pbombs[0].y  = 0;
//    pbombs[0].found = false;
//    pbombs[1].x = 2;
//    pbombs[1].y  = 1;
//    pbombs[1].found = false;

    printf("\nFirst bomb %d %d ",pbombs[0].x, pbombs[0].y);
    printf("\nSecond bomb %d %d ",pbombs[1].x, pbombs[1].y);


    // matrix creation for bombs by adding one around the bomb in 8 cells
    int z = 0;
    for (z; z< of_bombs;z++) {
        if ((pbombs[z].x) - 1 < 0) { // top of the bombs is less than zero
            // do nothing
        }
        else {
            if ((pbombs[z].y) - 1 < 0) {
                // do nothing
            }
            else {
                bomb_location_info[(pbombs[z].x) - 1][(pbombs[z].y) - 1]++; // top left
            }
            bomb_location_info[(pbombs[z].x) - 1][(pbombs[z].y)]++; // top
            if ((pbombs[z].y) + 1 > 3) {
                // do nothing
            }
            else {
                bomb_location_info[(pbombs[z].x) - 1][(pbombs[z].y) + 1]++; // top right
            }
        }
        if ((pbombs[z].y) - 1 < 0) { // if the left of the bomb column is less than zero
            // do nothing
        }
        else {
            bomb_location_info[(pbombs[z].x)][(pbombs[z].y) - 1]++; // left
        }
        if ((pbombs[z].y) + 1 > 3) {
            // do nothing
        }
        else {
            bomb_location_info[(pbombs[z].x)][(pbombs[z].y) + 1]++; // right
        }
        if ((pbombs[z].x) + 1 > 3) {
           // do nothing
        }
        else {
            if ((pbombs[z].y) - 1 < 0) {
                // do nothing
            }
            else {
                bomb_location_info[(pbombs[z].x) + 1][(pbombs[z].y) - 1]++; // bottom left
            }
            bomb_location_info[(pbombs[z].x) + 1][(pbombs[z].y)]++; // bottom
            if ((pbombs[z].y) + 1 > 3) {
                // do nothing
            }
            else {
                bomb_location_info[(pbombs[z].x) + 1][(pbombs[z].y) + 1]++; // bottom right
            }
        }


    }


    // display  - can delete later:
    int n = 0;
    printf("\n");
    printf("   A B C D \n");
    for (n;n<DIM;n++) {
        if (n == 0) {
            printf("A: ");
        }
        else if (n == 1) {
            printf("B: ");
        }
        else if (n == 2) {
            printf("C: ");
        }
        else if (n == 3) {
            printf("D: ");
        }
        int j = 0;
        for (j;j<DIM;j++) {
            printf("%d ", bomb_location_info[n][j]);
        }
        printf("\n");
    }


    int size = DIM;

    if (argc == 3) {
        printf("Please enter \"clues\" or \"noclues\" :");
    }

    int r0,r1, r2,r3,r4,r5;
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
    // check if the two random numbers are the coordinates of a bomb, if so, create two new random numbers and check them again
    bool again = true;
    while (again) {
        if ((r1 == pbombs[0].x && c1 == pbombs[0].y) || (r1 == pbombs[1].x && c1 == pbombs[1].y)) {
            r1 = rand() % 4;
            c1 = rand() % 4;
            again = true;
        }
        else if ((r2 == pbombs[1].x && c2 == pbombs[1].y) || (r2 == pbombs[0].x && c2 == pbombs[0].y)) {
            r2 = rand() % 4;
            c2 = rand() % 4;
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
                again = true;
            }
            else if ((r4 == pbombs[0].x && c4 == pbombs[0].y) || (r4 == pbombs[1].x && c4 == pbombs[1].y)) {
                r4 = rand() % 4;
                c4 = rand() % 4;
                again = true;
            }
            else if ((r4 == r1 && c4 == c1) || (r4 == r2 && c4 == c2)) {
                r4 = rand() % 4;
                c4 = rand() % 4;
                again = true;
            }
            else if ((r5 == pbombs[0].x && c5 == pbombs[0].y) || (r5 == pbombs[1].x && c5 == pbombs[1].y)) {
                r5 = rand() % 4;
                c5 = rand() % 4;
                again = true;
            }
            else if ((r5 == r1 && c5 == c1) || (r5 == r2 && c5 == c2)) {
                r5 = rand() % 4;
                c5 = rand() % 4;
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