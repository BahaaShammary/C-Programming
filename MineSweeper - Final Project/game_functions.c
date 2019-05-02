#include <stdio.h>
#include <stdlib.h>
#include "game_functions.h"
//
// Created by Bahaulddin
//
void display(int known_location_info[][DIM], int size) {
    int i = 0;
    printf("   A B C D \n");
    for (i;i<size;i++) {
        if (i == 0) {
            printf("A: ");
        }
        else if (i == 1) {
            printf("B: ");
        }
        else if (i == 2) {
            printf("C: ");
        }
        else if (i == 3) {
            printf("D: ");
        }
        int j = 0;
        for (j;j<size;j++) {
            if (known_location_info[i][j] < 0 && known_location_info[i][j] > -2) {
                printf("* ");
            }
            else if (known_location_info[i][j] == -2) {
                printf("B ");
            }
            else {
                printf("%d ", known_location_info[i][j]);

            }
        }
        printf("\n");
    }
}

void check_found(int row, int col, struct locations bombs[], int size, bool* found){
    int* x0 = &bombs[0].x;
    int* y0 = &bombs[0].y;

    int* x1 = &bombs[1].x;
    int* y1 = &bombs[1].y;

    if (*x0 == row && *y0 == col) {
        *found = true;
    }
    else if (*x1 == row && *y1 == col) {
        bombs[1].found = true;
        *found = true;
    }

}

void update_known_info(int row, int col, int bomb_info[][DIM], int known[][DIM]) {
    known[row][col] = bomb_info[row][col];

}

char get_user_char() {
    char letter;
    scanf("%c", &letter);
    getchar();

    return letter;
}


void start_game(struct locations* bombs, int bomb_location_info[][DIM], int size_of_grid, int players_info[][DIM], int no_of_bombs)
{
    int bombs_found = 0;
    int counter = 1;
    int moves = 1;
    enum game_status  {STILL_ALIVE, GAME_OVER};
    enum game_status status = STILL_ALIVE;
    bool found;

    while (status == STILL_ALIVE) {
        display(players_info, size_of_grid);
        printf("\nMove #%d\n", moves);
        int col;
        int row;
        char colLetter;
        char rowLetter;

        printf("Enter the column letter?\n");
        colLetter = get_user_char();

        printf("Enter the row letter?\n");
        rowLetter = get_user_char();

        col = colLetter - 'A';
        row = rowLetter - 'A';

        found = false;
        check_found(row, col, bombs, size_of_grid, &found);

        if (found == true) {
            status = GAME_OVER;
            display(players_info, size_of_grid);
            printf("\n**********\nBOOM GAME OVER!\n**********\n");
        }
        update_known_info(row, col, bomb_location_info, players_info);
        if (counter == 5) {
            break;
        }
        //printf("\nThe counter is now %d\n", counter);
        counter++;
        moves++;
    }
    int loop_counter = 1;
    while (status == STILL_ALIVE) {
        int col;
        int row;
        char colLetter;
        char rowLetter;

        printf("\nPlease identify the location of Bomb number %d now\n", loop_counter);
        printf("Enter the column letter?\n");
        colLetter = get_user_char();

        printf("Enter the row letter?\n");
        rowLetter = get_user_char();

        col = colLetter - 'A';
        row = rowLetter - 'A';
        found = false;
        check_found(row, col, bombs, size_of_grid, &found);

        if (found == true) {
            bombs[loop_counter].found = true;
            if (row == 1 && col == 1) {
                players_info[row][col] = BOMB;
            }
            else if (row == 2 && col == 3) {
                players_info[row][col] = BOMB;
            }
            display(players_info, size_of_grid);
            bombs_found++;
        }
        else if (found == false){
            printf("\nNo Bomb Here - You Lost\n"
                   "------   Game Over     ------ \n");
            status = GAME_OVER;
            //break;
        }
        loop_counter++;
        if (bombs_found == 2) {
            printf("\n**********\nCongratulations! you found the two bombs!\n**********\n");
            status = GAME_OVER;
        }
        else if (loop_counter > 2) {
            printf("You we were not able to find the two bombs");
            status = GAME_OVER;
        }

    }

}


