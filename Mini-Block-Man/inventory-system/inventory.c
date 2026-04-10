#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char nome[50];
        int id;
        int quantidade;
        char textura[50];
} item;

typedef struct{
    item slots[5];
} inventory;


int main(){

    FILE *invtxt = fopen("../inv.txt", "w");
    
    inventory inv = {{
        {"picaxe", 3, 1, "itemtextures/stone_picaxe.jpg"}, 
        {"axe", 2, 1, "itemtextures/stone_axe.jpg"}, 
        {"sword", 1, 1, "itemtextures/stone_sword.jpg"}, 
        {"spruce log", 4, 1, "itemtextures/spruce_log.jpg"}, 
        {"empty", 0, 1}
    }};
    for (int i = 0; i < 5; i++){
        if (inv.slots[i].nome[0] == '\0'){
            printf("não existe\n");
        } else {
            printf("existe\n");
            char item[50];
            sprintf(item, "%s|%d|%d|%s\n", inv.slots[i].nome, inv.slots[i].id, inv.slots[i].quantidade, inv.slots[i].textura);
            fputs(item, invtxt);
        }
    }
    return 0;
}