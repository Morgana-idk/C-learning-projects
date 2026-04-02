#include <stdio.h>
#include "raylib.h"

int main() {
    int windowX = 800;
    int windowY = 450;
    InitWindow(windowX, windowY, "Mini Block Man!");
    Vector2 playerPos = {windowX/2, windowY/2};

    while (!WindowShouldClose()){
        if (IsKeyDown(KEY_RIGHT)) playerPos.x += 0.3;
        if (IsKeyDown(KEY_LEFT)) playerPos.x -= 0.3;
        if (IsKeyDown(KEY_UP)) playerPos.y -= 0.3;
        if (IsKeyDown(KEY_DOWN)) playerPos.y += 0.3;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Mini Block Man!", 400, 400, 50, BLACK);
            DrawRectangleV((Vector2){playerPos.x, playerPos.y}, (Vector2){40, 40}, RED);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
