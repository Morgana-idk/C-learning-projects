#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char nome[50];
        int id;
        int quantidade;
} item;

typedef struct{
    item slots[5];
} inventory;


int main(){

    FILE *invtxt = fopen("/home/modulescript/projetos/C-learning-projects/Mini-Block-Man/inv.txt", "w");
    
    inventory inv = {{
        {"picaxe", 3, 1}, 
        {"axe", 2, 1}, 
        {"sword", 1, 1}, 
        {"grass block", 4, 1}, 
        {"empty", 0, 1}
    }};
    for (int i = 0; i < 5; i++){
        if (inv.slots[i].nome[0] == '\0'){
            printf("não existe\n");
        } else {
            printf("existe\n");
            char item[50];
            sprintf(item, "%s|%d|%d\n", inv.slots[i].nome, inv.slots[i].id, inv.slots[i].quantidade);
            fputs(item, invtxt);
        }
    }
    return 0;
}