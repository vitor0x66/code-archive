#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int number = (rand() % 100) + 1;
    int choice;
    int attempts = 1;

    printf("*********************\n\n");
    printf("Number guessing game!\n");
    printf("Guess a number between 1 - 100\n");
    printf("Guess the number: ");
    scanf("%d", &choice);

    while (1){
        if(choice == number) break;
        else{
            choice > number ? printf("Too high!\n") : printf("Too low!\n");
            printf("Guess the number: ");
            scanf("%d", &choice);
        }
        attempts++;
    }

    printf("Congratulations!\nThe number was %d!\nIt took you %d attempts!\n", number, attempts);
    return 0;
}
