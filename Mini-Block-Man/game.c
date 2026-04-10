#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <unistd.h>
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

void update_inv(){
    char diretorio_atual[150];
    char diretorio_inv[] = "inventory-system";
    if (diretorio_inv != NULL){
        char comando[200];
        getcwd(diretorio_atual, sizeof(diretorio_atual));
        sprintf(comando, "cd %s && make clean && make && cd %s", diretorio_inv, diretorio_atual);
        system(comando);
    }
};


inventory ler_inv(){
    inventory inventor;
    FILE *inv = fopen("inv.txt", "r");
    if (inv != NULL){
        for (int i = 0; i < 5; i++) strcpy(inventor.slots[i].nome, "empty");
        for (int i = 0; i < 5; i++) inventor.slots[i].id = 0;
        for (int i = 0; i < 5; i++) inventor.slots[i].quantidade = 1;
        int times = 0;
        char linha[50];
        while (fgets(linha, sizeof(linha), inv) && times < 5){
            strtok(linha, "\n");
            char *antesdabarra = strchr(linha, '|');
            if (antesdabarra != NULL){
                *antesdabarra = '\0';
                strcpy(inventor.slots[times].nome, linha);
            }
            char *depoisdabarra = strchr(linha, '|');
            if (depoisdabarra != NULL){
                char resultado[20];
                int resultadoint;
                char resultado2[20];
                int resultado2int;
                char resultado3[20];

                sscanf(depoisdabarra, "%*c%[^|]", resultado);
                resultadoint = atoi(resultado);
                inventor.slots[times].id = resultadoint;
                sscanf(depoisdabarra, "%*c%*[^|]%*c%s", resultado2);
                resultado2int = atoi(resultado2);
                inventor.slots[times].quantidade = resultado2int;
                sscanf(depoisdabarra, "%*c%*[^|]%*c%*[^|]%*c%s", resultado3);
                strcpy(inventor.slots[times].textura, resultado3);
            }

            
            system("clear");
            printf("linha %d copiada para struct inventory: %s\n", times, linha);
            times++;
        }
    }
    return inventor;
};

int main() {
    system("clear");
    update_inv();
    struct slots{
        Rectangle slots[5];
    };
    inventory inventor = ler_inv();
    float speed = 300.0f;
    float gravity = 1500.0f;    // Valor mais suave para o pulo não ser bizarro
    float jumppower = -600.0f;  // Negativo porque no Y da tela, para cima é menos
    float velocityY = 0.0f;
    bool tocandochao = false;

    InitWindow(800, 450, "Mini Block Man - Slots!");
    SetTargetFPS(60);

    Texture2D texturascarregadas[5];
    for (int i = 0; i < 5; i++){
        if (strcmp(inventor.slots[i].nome, "empty") != 0){
            texturascarregadas[i] = LoadTexture(inventor.slots[i].textura);
        }
    }

    
    Rectangle player = { 400, 200, 40, 40 };
    Rectangle floor = { 0, 410, 800, 40 };
    

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_I)){
            update_inv();
        }
        
        struct slots slot = {{{ player.x + 1, floor.y + 1, 38, 38}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
        slot.slots[1] = (Rectangle){ player.x + (slot.slots[0].width + 5), floor.y + 1, 38, 38};
        slot.slots[2] = (Rectangle){ player.x + (slot.slots[1].width * 2) + 10, floor.y + 1, 38, 38};
        slot.slots[3] = (Rectangle){ player.x - slot.slots[1].width - 5, floor.y + 1, 38, 38};
        slot.slots[4] = (Rectangle){ player.x - (slot.slots[3].width * 2) - 10, floor.y + 1, 38, 38};
        float frametime = GetFrameTime();

        // 1. Movimento Horizontal
        if (IsKeyDown(KEY_D)) player.x += speed * frametime;
        if (IsKeyDown(KEY_A)) player.x -= speed * frametime;

        // 2. Lógica de Pulo (Só pula se estiver no chão)
        if (IsKeyPressed(KEY_SPACE) && tocandochao || IsKeyPressed(KEY_W) && tocandochao) {
            velocityY = jumppower;
            tocandochao = false;
        }

        // 3. Aplicação da Gravidade (Aceleração)
        if (!tocandochao) {
            velocityY += gravity * frametime; // A velocidade aumenta conforme ele cai
        } else {
            if (velocityY > 0) velocityY = 0; // Para de cair se bater no chão
        }

        // Aplica a velocidade na posição
        player.y += velocityY * frametime;

        // 4. Detecção de Colisão Real
        if (CheckCollisionRecs(player, floor)) {
            player.y = floor.y - player.height; // Ajuste de "pé no chão"
            tocandochao = true;
        } else {
            tocandochao = false;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleRec(floor, GREEN);
            DrawRectangleRec(player, RED);
            DrawRectangleRec(slot.slots[0], GRAY);
            DrawRectangleRec(slot.slots[1], GRAY);
            DrawRectangleRec(slot.slots[2], GRAY);
            DrawRectangleRec(slot.slots[3], GRAY);
            DrawRectangleRec(slot.slots[4], GRAY);

            

            for (int i = 0; i < 5; i++){
                if (strcmp(inventor.slots[i].nome, "empty") != 0){
                    char texto[20];
                    sprintf(texto, "\n\n%d", inventor.slots[i].quantidade);
                    DrawTexture(texturascarregadas[i], slot.slots[i].x + 1, slot.slots[i].y, WHITE);
                    DrawText(texto, slot.slots[i].x + 1, slot.slots[i].y, 12, WHITE);
                }
                
            }
            DrawText("SLOTS!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    system("clear");
    printf("Obrigado por Jogar!!!\n\n\n");
    sleep(2);
    system("clear");
    return 0;
}