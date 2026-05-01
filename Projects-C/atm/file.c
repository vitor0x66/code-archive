#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "profile.h"
#include "file.h"

#define FILEPATH "balance.bin"
#define BLOCK 10

Client clients[BLOCK];
size_t length;

void update_balance(char *name, double value){
    FILE* file = fopen(FILEPATH, "rb+");
    if(file == NULL){
        file = fopen(FILEPATH, "wb+");
    }
    
    int found = 0;
    while((length = fread(clients, sizeof(Client), BLOCK, file)) > 0){
        for(size_t i = 0; i < length; i++){
            if(strcasecmp(clients[i].name, name) == 0){
                fseek(file, -sizeof(Client) * (length - i), SEEK_CUR);
                clients[i].balance += value;
                int j = fwrite(&clients[i], sizeof(Client), 1, file);
                j == 1 ? printf("Operation ok\n") : printf("Operation FAILED\n") ;
                found = 1;
                break;
            }
        }
    }
    if(!found){
        fseek(file, 0, SEEK_END);
        Client client;
        strcpy(client.name, name);
        client.balance = value;

        int j = fwrite(&client, sizeof(Client), 1, file);
        j == 1 ? printf("Operation ok\n") : printf("Operation FAILED\n") ;
    }
    fclose(file);
}
double retrieve_balance(char *name){
    FILE* file = fopen(FILEPATH, "rb+");
    if(file == NULL){
        printf("No database\n");
        return -1;
    }

    double value;

    while((length = fread(clients, sizeof(Client), BLOCK, file)) > 0){
        for(size_t i = 0; i < length; i++){
            if(strcasecmp(clients[i].name, name) == 0){
                value = clients[i].balance;
                fclose(file);
                return value;
            }
        }
    }
    fclose(file);
    printf("Name not found\n");
    return -1;
}
