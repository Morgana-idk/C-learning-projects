#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct inventory{
        char slots[5][50];
    };
    struct inventory inv = {{"Picareta", "Machado", "Espada", "Bloco de Grama", "null"}};
    for (int i = 0; i < 5; i++){
        if (strcmp(inv.slots[i], "null") != 0 && inv.slots[i][0] != '\0'){
            printf("existe\n");
        } else {
            printf("n existe\n");
            return 1;
        }
    }
    return 0;
}