#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char requesttxt[50];
    char printwhat[50];
    FILE *request = fopen("request.txt", "r");
    FILE *response = fopen("response.txt", "w");
    char linha[50];
    while (fgets(linha, sizeof(linha), request)){
        strtok(linha, "\n");
        char *depoisdabarranome = strchr(linha, '|');
        if (depoisdabarranome){
            *depoisdabarranome == '\0';
            strcpy(requesttxt, linha);
        }
        char *depoisdabarra = strchr(linha, '|');
        if (depoisdabarra){
            sscanf(depoisdabarra, "%*c%s", printwhat);
        }
        if (strcmp(requesttxt, "print") == 0 && strcmp(printwhat, "null") != 0){
            fprintf(response, "%s", printwhat);
        }
    }
    

}