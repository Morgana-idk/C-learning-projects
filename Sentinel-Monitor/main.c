#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int main() {
    

    int opcao = 1;
    char opcao1[3] = "+";
    char opcao2[3] = " ";
    enum telas{MENU, CPU, MEM};
    enum telas tela_atual = MENU;
    int tecla;
    struct MEMINFO{
        int total;
        int free;
        int cache;
    };
    struct CPUINFO{
        char nomecpu[256];
        char clock[30];
        int nucleos;
    };
    
    struct CPUINFO myCPU = {"", 0, 0, 0};
    struct MEMINFO myMEM = {0, 0, 0};

    char linha[256];

    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);

    while (1){
        erase();
        if (tela_atual == 0){
            attron(COLOR_PAIR(4));
            mvprintw(0, 0, "========SENTINEL MONITOR========");
            attroff(COLOR_PAIR(4));
            mvprintw(1, 0, "CPU INFO      ---      MEM INFO");
            mvprintw(3, 0, "%scpu info            %smem info", opcao1, opcao2);
            mvprintw(4, 0, "Aperte Q para Sair.");
            mvprintw(5, 0, "================================");
        } else if (tela_atual == 1){
            FILE *uptime = fopen("/proc/uptime", "r");
            FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
            
            double uptime_segundos;
            if (uptime){
                fscanf(uptime, "%lf", &uptime_segundos);
                fclose(uptime);
            }
            int h = uptime_segundos / 3600;
            int m = ((int)uptime_segundos % 3600) / 60;
            int s = (int)uptime_segundos % 60;


            

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
            attron(COLOR_PAIR(4));
            mvprintw(0, 0, "========SENTINEL MONITOR========");
            attroff(COLOR_PAIR(4));
            mvprintw(1, 0, "------------CPU INFO------------");
            mvprintw(3, 0, "Nome da CPU: %s", myCPU.nomecpu);
            mvprintw(4, 0, "Clock da CPU: %s", myCPU.clock);
            mvprintw(5, 0, "Nucleos da CPU: %d", myCPU.nucleos);
            mvprintw(6, 0, "Uptime: %d:%d:%d", h, m, s);
            mvprintw(8, 0, "Aperte M para Voltar.");
            mvprintw(9, 0, "================================");
        } else if (tela_atual == 2){
            FILE *meminfo = fopen("/proc/meminfo", "r");
            while(fgets(linha, sizeof(linha), meminfo)){
        if (strstr(linha, "MemTotal") != NULL){
            char *totaladdress = strchr(linha, ':') + 2;
            if (totaladdress != NULL){
                myMEM.total = atoi(totaladdress) / 1024;
            } else {
                myMEM.total = 0;
            }
        } else if (strstr(linha, "MemFree") != NULL){
            char *freeaddress = strchr(linha, ':') + 2;
            if (freeaddress != NULL){
                myMEM.free = atoi(freeaddress) / 1024;
            } else {
                myMEM.free = 0;
            }
        } else if (strstr(linha, "Cached") != NULL && strstr(linha, "SwapCached") == NULL){
            char *cacheaddress = strchr(linha, ':') + 2;
            if (cacheaddress != NULL){
                myMEM.cache = atoi(cacheaddress) / 1024;
            } else {
                myMEM.cache = 0;
            }
        }
    }
            attron(COLOR_PAIR(4));
            mvprintw(0, 0, "========SENTINEL MONITOR========");
            attroff(COLOR_PAIR(4));
            mvprintw(1, 0, "------------MEM INFO------------");
            mvprintw(3, 0, "Memoria total: %d MB", myMEM.total);
            if (myMEM.free < 500){
            attron(COLOR_PAIR(3));
            mvprintw(4, 0, "Memoria livre: %d MB", myMEM.free);
            attroff(COLOR_PAIR(3));
            } else if (myMEM.free == 500){
            attron(COLOR_PAIR(2));
            mvprintw(4, 0, "Memoria livre: %d MB", myMEM.free);
            attroff(COLOR_PAIR(2));
            } else {
            attron(COLOR_PAIR(1));
            mvprintw(4, 0, "Memoria livre: %d MB", myMEM.free);
            attroff(COLOR_PAIR(1));
            }
            mvprintw(5, 0, "Cache: %d MB", myMEM.cache);
            mvprintw(7, 0, "Aperte M para Voltar.");
            mvprintw(8, 0, "================================");
        }
        
        
        tecla = getch();

        if (tecla == KEY_RIGHT && tela_atual == 0){
            opcao++;
            if (opcao % 2 == 0){
                strcpy(opcao2, "+");
                strcpy(opcao1, " ");
            } else {
                strcpy(opcao1, "+");
                strcpy(opcao2, " ");
            }
        } else if (tecla == KEY_LEFT && tela_atual == 0){
            opcao--;
            if (opcao % 2 == 0){
                strcpy(opcao2, "+");
                strcpy(opcao1, " ");
            } else {
                strcpy(opcao1, "+");
                strcpy(opcao2, " ");
            }
        } else if (tecla == 10 && tela_atual == 0 || tecla == '\n' && tela_atual == 0){
            if (opcao % 2 == 0){
                tela_atual = 2;
            } else {
                tela_atual = 1;
            }
        } else if (tecla == 'm' || tecla == 'M'){
            tela_atual = 0;
        } else if (tecla == 'Q' || tecla == 'q'){
            break;
        }
        
        
        

        refresh();
        usleep(10000);
    }
    
    endwin();
    return 0;
}
