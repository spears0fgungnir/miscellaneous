#include <bits/stdc++.h>
#include "raylib.h"

using namespace std;

// LEFT, RIGHT, UP, DOWN
// vector<pair<int, int>> offsets = {{-15, 0}, {15, 0}, {0, -15}, {0, 15}};
vector<pair<int, int>> offsets = {{-5, 0}, {5, 0}, {0, -5}, {0, 5}};

const int width = 600, height = 800;
constexpr int CELL_SIZE = 15;


struct Cell {
    int x;
    int y;
    int dir;
    int w = 15;
    int h = 15;

    Cell(int x, int y, int dir): x(x), y(y), dir(dir) {}

    void Draw(Color color = GREEN) {
        DrawRectangle(x, y, w, h, color);
    }
};

int main(void) {
    std::random_device rd;
    std::mt19937 gen(rd());
    uniform_int_distribution<> food_genx(0, width / CELL_SIZE - 1);
    uniform_int_distribution<> food_geny(0, height / CELL_SIZE - 1);
    int food_x = food_genx(gen) * CELL_SIZE;       
    int food_y = food_geny(gen) * CELL_SIZE;

    int pressed_dir = 2, move_idx = 0;
    bool game_over = false;
    vector<unique_ptr<Cell>> Snake;
    Snake.push_back(make_unique<Cell>(width/2, height/2 - 15, pressed_dir));
    Snake.push_back(make_unique<Cell>(width/2, height/2, pressed_dir));

    InitWindow(width, height, "Snake, I guess");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (!game_over) {

            if (pressed_dir != 3 && IsKeyPressed(KEY_W)) {pressed_dir = 2; move_idx = 0;}
            if (pressed_dir != 1 && IsKeyPressed(KEY_A)) {pressed_dir = 0; move_idx = 0;}
            if (pressed_dir != 2 && IsKeyPressed(KEY_S)) {pressed_dir = 3; move_idx = 0;}
            if (pressed_dir != 0 && IsKeyPressed(KEY_D)) {pressed_dir = 1; move_idx = 0;}

            auto& last_cell = Snake[Snake.size()-1];
            int nx = offsets[pressed_dir].first;
            int ny = offsets[pressed_dir].second;

            if ((Snake[0]->x + nx < 0) || (Snake[0]->x + nx > width))
                game_over = true;
            if ((Snake[0]->y + ny < 0) || (Snake[0]->y + ny > height))
                game_over = true;

            Snake.insert(Snake.begin(), make_unique<Cell>(Snake[0]->x + nx, Snake[0]->y + ny, pressed_dir));

            int x_coord = Snake[0]->x;
            int y_coord = Snake[0]->y;

            if (((x_coord <= food_x) && (x_coord + CELL_SIZE >= food_x)) && ((y_coord <= food_y) && (y_coord + CELL_SIZE >= food_y))) {
                food_x = food_genx(gen) * CELL_SIZE;       
                food_y = food_geny(gen) * CELL_SIZE;
            }
            else {
                Snake.pop_back();

            }
                            

        } else { break; }

        BeginDrawing();

            ClearBackground(BLACK);
            DrawCircle(food_x + CELL_SIZE / 2, food_y + CELL_SIZE / 2, 7.5f, BLUE);
            for (auto& snake_cell: Snake) {
                snake_cell->Draw();
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
