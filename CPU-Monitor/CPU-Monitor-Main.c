#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    FILE *arquivo = fopen("/proc/cpuinfo", "r");

    char linha[256];

    if (arquivo == NULL) return 1;

    int clonemodelname = 0;
    int clonecpumhz = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {

        if (strstr(linha, "model name") != NULL && clonemodelname == 0){
            char *valorcputexto = strchr(linha, ':') + 2;
            printf("nome da cpu: %s \n", valorcputexto);
            clonemodelname++;
        }

        if (strstr(linha, "cpu MHz") != NULL && clonecpumhz == 0) {

            char *valortexto = strchr(linha, ':');

            if (valortexto != NULL){

                float mhz = atof(valortexto + 2);
                float ghz = mhz / 1000;
            
                printf("Ghz original: %.2fGHz \n", ghz);
                clonecpumhz++;
            }
        }
    }

    fclose(arquivo);
    printf("CPU Monitor fechado com sucesso!");
}
