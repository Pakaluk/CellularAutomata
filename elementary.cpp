#include <iostream>

int main () {

    int size = 200, rule = 99;
    short list[2][size];
    int c = 0;

    for (int i = 0; i < size; i++) {
        list[0][i] = list[1][i] = 0;
    }
    list[0][size / 2] = 1;


    for (int i = 0; i < 100000; i++) {
        for (int i = 0; i < size; i++) {
            int t = 0;
            t |= (list[c][(i - 1 + size) % size] << 2) | (list[c][i] << 1) | (list[c][(i + 1) % size]);
            list[c ^ 1][i] = (rule >> t) & 1;
            std::cout << (list[c ^ 1][i] ? "□" : "■");
        }
        std::cout << std::endl;
        c ^= 1;
    }

    return 0;
}
