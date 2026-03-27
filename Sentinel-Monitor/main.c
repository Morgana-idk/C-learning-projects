#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    
    int contagem = 0;

    while (1){
        printf("\033[H\033[J");
        printf("\n\n==========SENTINEL MONITOR==========\n");
        printf("%d\n", contagem);
        printf("====================================\n\n");
        contagem++;
        sleep(1);
    }
    

    return 0;
}
