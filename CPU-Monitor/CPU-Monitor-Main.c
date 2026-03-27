#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    FILE *arquivo = fopen("/proc/cpuinfo", "r");

    char linha[256];

    if (arquivo == NULL) return 1;

    struct CPU_infos{
        char NomeCPU[256];
        float clock;
        int nucleos;
    };
    
    struct CPU_infos myCPU = {"", 0, 0};
    while (fgets(linha, sizeof(linha), arquivo)){
        if (strstr(linha, "model name") != NULL){
            char *nameadress = strchr(linha, ':') + 2;
            if (nameadress != NULL){
                strcpy(myCPU.NomeCPU, nameadress);
                myCPU.NomeCPU[strcspn(myCPU.NomeCPU, "\n")] = '\0';
            } else {
                strcpy(myCPU.NomeCPU, "Not Indentfied");
            };
        } else if (strstr(linha, "cpu MHz")){
            char *clockaddress = strchr(linha, ':') + 2;
            
            if (clockaddress != NULL){
                float MHz = atof(clockaddress);
                float GHz = MHz / 1000;
                myCPU.clock = GHz;
            } else {
                myCPU.clock = 0;
            }
        } else if (strstr(linha, "cpu cores")){
            char *coresadress = strchr(linha, ':') + 2;
            if (coresadress != NULL) {
                myCPU.nucleos = atoi(coresadress);
            } else {
                myCPU.nucleos = 0;
            }
        }
        
    }
    
    printf("Nome da CPU: %s \n Clock: %0.2f \n Núcleos: %d \n", myCPU.NomeCPU, myCPU.clock, myCPU.nucleos);
    fclose(arquivo);
    printf("CPU Monitor fechado com sucesso! \n");
}
