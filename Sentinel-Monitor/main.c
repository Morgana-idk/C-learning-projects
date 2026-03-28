#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int main() {
    

    char opcao[30];
    char opcao1[2];
    char opcao2[2];
    int print0 = 0;
    int print1 = 1;
    int print3 = 3;
    int print4 = 4;
    int print5 = 5;
    int tecla;
    struct CPUINFO{
        char nomecpu[256];
        float clock;
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
                myCPU.clock = atof(clockaddress);
            } else {
                myCPU.clock = 0.0;
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
        mvprintw(print0, 0, "========SENTINEL MONITOR========");
        mvprintw(print1, 0, "CPU INFO      ---      MEM INFO");
        mvprintw(print3, 0, "%scpu info            %smem info", opcao1, opcao2);
        mvprintw(print4, 0, "Aperte Q para Sair.");
        mvprintw(print5, 0, "================================");

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
        } else if (tecla == KEY_ENTER) {
            if (opcao == "CPUINFO") {
                for (int i = 0; i < 3; i++){
                    print0++;
                    print1++;
                    print3++;
                    print4++;
                    print5++;
                    
                }
            }
        }

        refresh();
        usleep(10000);
    }
    
    endwin();
    return 0;
}
