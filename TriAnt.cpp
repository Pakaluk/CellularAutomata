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

/*
var grid_size = 25;
var speed = 250;
var back = color(100);
var rules = [0, 1, 2], colors = [back], grid = [];

for (var i = 1; i < rules.length; i++){
    colors.push(color(random(255), random(255), random(255)));
}

function drawGrid (grid, w, h, colors) {
    var m = grid.length, n = grid[0].length;
    var triw = 2 * w / m, trih = height / n;
    for(var i = 0; i < m + 1; i++){
        for(var j = 0; j < n + 1; j++){
            var ori = 1 - ((i & 1) ^ (j & 1)) * 2;
            var x = 0.5 * triw * i, y = trih * j;
            fill(colors[grid[i % m][j % n]]);
            triangle(x, y - ori * 0.5 * trih,
                     x + 0.5 * triw, y + ori * 0.5 * trih,
                     x - 0.5 * triw, y + ori * 0.5 * trih);
        }
    }
}

function fillGrid (txt, w, h) {
    var c = 0;
    var temp = Array(w);
    for(var i = 0; i < w; i++){
        temp[i] = Array(h);
        for(var j = 0; j < h; j++){
            temp[i][j] = Number(txt[c++]) | 0;
            //c++;
        }
    }
}

function update (number) {

}

for(var i = 0; i < 16; i++){
    grid.push([]);
    for(var j = 0; j < 9; j++){
        grid[i].push(~~random(3));
    }
}

frameRate(20);
function draw(){
    background(255);
    noStroke();
    fill(196, 57, 57);
    drawGrid(grid, width, height, colors);
    fill(0, 255, 0);
    //ellipse(0, 0, 2, 2);
}

random();
*/
