#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int NUM_PAWNS = 5;
const int NUM_COLORS = 8;
const int NUM_ATTEMPTS = 10;

enum color_t { RED, GREEN, BLUE, YELLOW, BLACK, WHITE, GRAY, PURPLE };

void read_proposed_combination(enum color_t board[]);
void evaluate_proposed_combination(enum color_t hidden_combination[],enum color_t proposed_combination[],
    int* num_well_placed_pawns,int* num_misplaced_pawns);
void game();
void generate_hidden_combination(enum color_t hidden_combination[]);

int main() {
    game();
    return 0;
}
void read_proposed_combination(enum color_t board[]) {
    char propo[10];
    for (int i = 0; i < NUM_PAWNS; i++) {
        scanf("%s", propo);
        if (strcmp(propo, "RED") == 0) {
            board[i] = 0;
            // printf("red\n");
        }
        else if (strcmp(propo, "GREEN") == 0) {
            board[i] = 1;
            // printf("green\n");
        }
        else if (strcmp(propo, "BLUE") == 0) {
            board[i] = 2;
            // printf("blue\n");
        }
        else if (strcmp(propo, "YELLOW") == 0) {
            board[i] = 3;
            // printf("yellow\n");
        }
        else if (strcmp(propo, "BLACK") == 0) {
            board[i] = 4;
            // printf("black\n");
        }
        else if (strcmp(propo, "WHITE") == 0) {
            board[i] = 5;
            //printf("WHITE\n");
        }
        else if (strcmp(propo, "GRAY") == 0) {
            board[i] = 6;
            //printf("GRAY\n");
        }
        else if (strcmp(propo, "PURPLE") == 0) {
            board[i] = 7;
            //printf("PURPLE\n");
        //}else{
         //   printf("wrong color, repeat please");
        }
    }
}
void evaluate_proposed_combination(enum color_t hidden_combination[], enum color_t proposed_combination[], int* num_well_placed_pawns, int* num_misplaced_pawns) {
    *num_well_placed_pawns = 0;
    *num_misplaced_pawns = 0;
    for (int i = 0; i < NUM_PAWNS; i++) {
        if (hidden_combination[i] == proposed_combination[i]) {
            (*num_well_placed_pawns)++;
        }
        else {
            for (int j = 0; j < NUM_PAWNS; j++) {
                if (i != j && hidden_combination[i] == proposed_combination[j]) {
                    (*num_misplaced_pawns)++;
                    break;
                }
            }
        }
    }
}
void game() {
    enum color_t hidden_combination[NUM_PAWNS];
    enum color_t proposed_combination[NUM_PAWNS];
    int num_well_placed_pawns, num_misplaced_pawns;
    int attempts = 0;
    generate_hidden_combination(hidden_combination);
    printf("chose your 5 combination (RED ,GREEN ,BLUE ,YELLOW ,BLACK ,WHITE ,GRAY ,PURPLE):\n ");
    while (attempts < NUM_ATTEMPTS) {
        read_proposed_combination(proposed_combination);
        evaluate_proposed_combination(hidden_combination, proposed_combination, &num_well_placed_pawns, &num_misplaced_pawns);
        printf("Well-placed pawns: %d\n", num_well_placed_pawns);
        printf("Misplaced pawns: %d\n", num_misplaced_pawns);
        if (num_well_placed_pawns == NUM_PAWNS) {
            printf("Congratulations! You guessed the hidden combination.\n");
            break;
        }
        attempts++;
    }
    if (attempts == NUM_ATTEMPTS) {
        printf("Sorry, you've reached the maximum number of attempts. The hidden combination was:\n");
        for (int i = 0; i < NUM_PAWNS; i++) {
            enum color_t  myVar = hidden_combination[i];
                switch (myVar) {
                    case 0:
                        printf("RED\t");
                    break;
                    case 1:
                        printf("GREEN\t");
                    break;
                    case 2:
                        printf("BLUE\t");
                    break;
                    case 3:
                        printf("YELLOW\t");
                    break;
                    case 4:
                        printf("BLACK\t");
                    break;
                    case 5:
                        printf("WHITE\t");
                    break;
                    case 6:
                        printf("GRAY\t");
                    break;
                    case 7:
                        printf("PURPLE\t");
                    break;
                }
        printf("\n");
    }
}
}
void generate_hidden_combination(enum color_t hidden_combination[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_PAWNS; i++) {
        hidden_combination[i] = rand() % NUM_COLORS;
        enum color_t  myVar = hidden_combination[i];

        switch (myVar) {
        case 0:
             //printf("RED\t");
            break;
        case 1:
             //rintf("GREEN\t");
            break;
        case 2:
             //printf("BLUE\t");
            break;
        case 3:
             //printf("YELLOW\t");
            break;
        case 4:
             //printf("BLACK\t");
            break;
        case 5:
             //printf("WHITE\t");
            break;
        case 6:
             //printf("GRAY\t");
            break;
        case 7:
             //printf("PURPLE\t");
            break;
        }
    }
    printf("\n");
}
