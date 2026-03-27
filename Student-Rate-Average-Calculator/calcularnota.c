#include <stdio.h>

int main() {
    
    FILE *historico = fopen("historico.txt", "a");

    float nota;
    float nota2;
    printf("Coloque sua nota: ");
    scanf("%f", &nota);
    prinf("Coloque sua segunda nota: ");
    scanf("%f", &nota2);

    float media = (nota + nota2) / 2;

    fprint("sua media é: %.2f", media);
    append(historico, "Nota 1: %.2f\n", nota);
    append(historico, "Nota 2: %.2f\n", nota2);
    append(historico, "Media: %.2f\n", media);

    fprintf(historico, "Seu historico é: \n");


    return 0;
}