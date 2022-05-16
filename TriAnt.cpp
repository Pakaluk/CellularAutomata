#include <iostream>

int main () {
    int w = 70, h = 40;
    int grid[w][h];

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            grid[i][j] = 0;
        }
    }

    int x = w / 2, y = h / 2 + 1;
    int dir = 1, orient = 1 - ((x ^ y) & 1) * 2;
    int rules[3] = {0, 1, 2};

    for (long i = 0; i < 9000000000; i++) {

        // change direction
        dir = (6 + orient * (dir + rules[grid[x][y]]) + !((x ^ y) & 1) * ((dir + 1) % 3)) % 3;

        // flip color of cell
        grid[x][y] = (grid[x][y] + 1) % 3;

        // move in new direction
        x = (1 + x + w - dir) % w;
        y = (y + orient * (~(dir - 1) & 1) + h) % h;

        // invert orientation
        orient = -orient;

        if(!(i % 10000000))
            std::cout << "Iteration: " << i << std::endl;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if((x == j) && (y == i))
                std::cout << "X";
            else
                std::cout << grid[j][i];
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
                std::cout << grid[i][j];
        }
    }
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
    std::cout << "D: " << dir << std::endl;

}
