#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <unistd.h>

void update_inv(){
    char diretorio_atual[150];
    char diretorio_inv[] = "inventory-system";
    char comando[200];
    sprintf(comando, "cd %s && make && cd %s", diretorio_inv, diretorio_atual);
    getcwd(diretorio_atual, sizeof(diretorio_atual));
    system(comando);
};

int main() {
    update_inv();
    float speed = 300.0f;
    float gravity = 1500.0f;    // Valor mais suave para o pulo não ser bizarro
    float jumppower = -600.0f;  // Negativo porque no Y da tela, para cima é menos
    float velocityY = 0.0f;
    bool tocandochao = false;

    InitWindow(800, 450, "Mini Block Man - Corrigido!");
    SetTargetFPS(60);

    
    Rectangle player = { 400, 200, 40, 40 };
    Rectangle floor = { 0, 410, 800, 40 };
    

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_I)){
            update_inv();
        }
        Rectangle slot1 = { player.x + 1, floor.y + 1, 38, 38};
        Rectangle slot2 = { player.x + (slot1.width + 5), floor.y + 1, 38, 38};
        Rectangle slot3 = { player.x + (slot2.width * 2) + 10, floor.y + 1, 38, 38};
        Rectangle slot4 = { player.x - slot2.width - 5, floor.y + 1, 38, 38};
        Rectangle slot5 = { player.x - (slot4.width * 2) - 10, floor.y + 1, 38, 38};
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
            DrawRectangleRec(slot1, GRAY);
            DrawRectangleRec(slot2, GRAY);
            DrawRectangleRec(slot3, GRAY);
            DrawRectangleRec(slot4, GRAY);
            DrawRectangleRec(slot5, GRAY);
            DrawText("ESPAÇO para pular!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    system("clear");
    printf("Obrigado por Jogar!!!\n\n\n");
    sleep(2);
    system("clear");
    return 0;
}