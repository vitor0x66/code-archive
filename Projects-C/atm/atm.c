#include <stdio.h>
#include <stdlib.h>
#include "file.h"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

void menu();

int main(){
    system(CLEAR);
    int option;
    do{
        menu();
        scanf("%d", &option);
        getchar();
        system(CLEAR);

        switch (option){
            case 1:{
                char name[64];
                double value;
                printf("Type your name: ");
                fgets(name, 63, stdin);
                printf("Type how much you want to deposit: ");
                scanf("%lf", &value);
                getchar();
                update_balance(name, value);
                break;
            }
            case 2:{
                char name[64];
                double value;
                printf("Type your name: ");
                fgets(name, 63, stdin);
                printf("Type how much you want to withdraw: ");
                scanf("%lf", &value);
                getchar();
                update_balance(name, -abs(value));
                break;
            }
            case 3:
                char name[64];
                printf("Type your name: ");
                fgets(name, 63, stdin);
                double value = retrieve_balance(name);
                printf("Current balance: %.2lf\n", value);
                break;
            case 4:
                break;
            default:
                printf("Invalid option. Try again\n");
                break;
        }
    }while (option != 4);

}

void menu(){
    printf("Choose an option: \n");
    printf("\t1) Deposit\n");
    printf("\t2) Withdraw\n");
    printf("\t3) See current balance\n");
    printf("\t4) Exit\n");
}
