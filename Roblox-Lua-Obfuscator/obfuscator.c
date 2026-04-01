#include <stdio.h>
#include <string.h>

int main() {
    FILE *entrada = fopen("/Roblox-Lua-Obfuscator/myscript.lua", "r");
    FILE *saida = fopen("/Roblox-Lua-Obfuscator/newscript.lua", "w");
    char linha[256];

    if (entrada == NULL){
        printf("Você precisa criar um arquivo chamado 'myscript.lua' \n ou move-lo para a pasta do app e renomea-lo para 'myscript.lua' \n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), entrada)){
        char *comentario = strstr(linha, "--");
        
        if (comentario != NULL){
            *comentario = '\n';
            *(comentario + 1) = '\0';
            printf("Script limpo com sucesso!");
            fputs(linha, saida);
        }
    }
    
    fclose(saida);
    fclose(entrada);

    printf("Programa terminou.");
    return 0;
}
