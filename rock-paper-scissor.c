#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *upper(char array[10]) {
    int j = 'a'-'A';
    for(int i = 0; i < 10; i++) {
        if(array[i]<='z' && array[i]>='a') {
            array[i] = array[i] - j;
        }
    }
    return array;
}

char *pc_turn(char pc_choice[8]) {
    srand(time(0));
    int number1 = rand() % 3;
    if(number1 == 0) {
        strcpy(pc_choice, "ROCK");
    }
    else if(number1 == 1) {
        strcpy(pc_choice, "PAPER");
    }
    else {
        strcpy(pc_choice, "SCISSOR");
    }
    return pc_choice;
}

void main() {
    // INTRODUCTION
    printf("\n");
    printf("You are playing The [\"ROCK\", \"PAPER\", \"SCISSOR\"] game designed by *SMAZY0210*");
    printf("\n");
    printf("\n");

    // DECLARING VARIABLES
    char pc_choice[8],human_choice[8];
    int pc_score = 0,human_score = 0,rounds = 0, draw = 0;


    while(1) {
        printf("What do you choose? [\"ROCK\", \"PAPER\", \"SCISSOR\", \"EXIT\"]");
        printf("\n");
        printf("\n");

        pc_turn(pc_choice);
        strcpy(pc_choice, "PAPER");


        gets(human_choice);
        upper(human_choice);

        if(!strcmp(pc_choice,human_choice)) {
            printf("\nYou chose %s and I chose %s, its a draw.\n",human_choice,pc_choice);
            draw += 1;
            printf("\n");
        }
        else if((!strcmp(pc_choice,"SCISSOR") && !strcmp(human_choice, "ROCK")) ||
                (!strcmp(pc_choice,"ROCK") && !strcmp(human_choice, "PAPER")) ||
                (!strcmp(pc_choice,"PAPER") && !strcmp(human_choice, "SCISSOR")))
            {
                printf("\nYou chose %s and I chose %s, you win.\n",human_choice,pc_choice);
                human_score += 1;
                printf("\n");
            }
        else if ((!strcmp(pc_choice,"ROCK") && !strcmp(human_choice, "SCISSOR")) ||
                (!strcmp(pc_choice,"PAPER") && !strcmp(human_choice, "ROCK")) ||
                (!strcmp(pc_choice,"SCISSOR") && !strcmp(human_choice, "PAPER")))
            {
                printf("\nYou chose %s and I chose %s, I win.\n",human_choice,pc_choice);
                pc_score += 1;
                printf("\n");
            }
        else if(!strcmp(human_choice,"EXIT")) {
            break;
        }
        else {
            printf("\nPlease Give a valid input.....\n");
            continue;
        }
    }
    rounds = pc_score + human_score + draw;

    printf("\nWe played for %d rounds I won %d times while you won %d times, %d were draws.\n",rounds,pc_score,human_score,draw);

    // ENDING
    printf("\n");
    printf("Thanks for playing this game designed by *SMAZY0210*\n");
    printf("\n");
}
