#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *invtxt = fopen("/home/modulescript/projetos/C-learning-projects/Mini-Block-Man/inv.txt", "w");
    struct inventory{
        char slots[5][50];
    };
    struct inventory inv = {{"Picareta", "Machado", "Espada", "Bloco de Grama", "null"}};
    for (int i = 0; i < 5; i++){
        if (strcmp(inv.slots[i], "null") != 0 && inv.slots[i][0] != '\0'){
            printf("existe\n");
            char item[50];
            sprintf(item, "%s\n", inv.slots[i]);
            fputs(item, invtxt);
        } else {
            printf("n existe\n");
            
        }
    }
    return 0;
}