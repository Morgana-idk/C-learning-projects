#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int main() {
    

    char opcao[30];
    char opcao1[2];
    char opcao2[2];
    int tecla;
    struct CPUINFO{
        char nomecpu[256];
        char clock[50];
        int nucleos;
    };
    
    struct CPUINFO myCPU = {"", 0.0, 0};

    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    char linha[256];

    while(fgets(linha, sizeof(linha), cpuinfo)){
        if (strstr(linha, "model name") != NULL){
            char *nameaddress = strchr(linha, ':') + 2;
            if (nameaddress != NULL){
                strcpy(myCPU.nomecpu, nameaddress);
            } else {
                strcpy(myCPU.nomecpu, "Not Indentfied");
            }
        } else if (strstr(linha, "cpu MHz") != NULL){
            char *clockaddress = strchr(linha, ':') + 2;
            if (clockaddress != NULL){
                float MHz = atof(clockaddress);
                float GHz = MHz / 1000;
                char ftoagambiarra[50];
                snprintf(ftoagambiarra, sizeof(ftoagambiarra), "%0.2f", GHz);
                strcpy(myCPU.clock, ftoagambiarra);
            } else {
                strcpy(myCPU.clock, "Not Indentfied");
            }
        } else if (strstr(linha, "cpu cores") != NULL){
            char *coresaddress = strchr(linha, ':') + 2;
            if (coresaddress != NULL){
                myCPU.nucleos = atoi(coresaddress);
            } else {
                myCPU.nucleos = 0;
            }
        }
    }

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);

    while (1){
        erase();
        mvprintw(0, 0, "========SENTINEL MONITOR========");
        mvprintw(1, 0, "CPU INFO      ---      MEM INFO");
        mvprintw(3, 0, "%scpu info            %smem info", opcao1, opcao2);
        mvprintw(4, 0, "Aperte Q para Sair.");
        mvprintw(5, 0, "================================");

        tecla = getch();

        if (tecla == KEY_RIGHT){
            strcpy(opcao2, "+ ");
            strcpy(opcao, "CPUINFO");
            strcpy(opcao1, "");
        } else if (tecla == KEY_LEFT) {
            strcpy(opcao1, "+ ");
            strcpy(opcao, "MEM");
            strcpy(opcao2, "");
        } else if (tecla == 'q' || tecla == 'Q') {
            break;
        } else if (tecla == KEY_ENTER || tecla == '\n' || tecla == 10) {
            if (strcmp(opcao, "CPUINFO") == 0) {
                
            }
        }

        refresh();
        usleep(10000);
    }
    
    endwin();
    return 0;
}
