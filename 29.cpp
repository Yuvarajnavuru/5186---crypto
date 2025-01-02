#include <stdio.h>

void update_state(int lanes[5][5], int round) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            lanes[i][j] ^= round;
        }
    }
}

int main() {
    int lanes[5][5] = {0}, rounds = 0;
    while (lanes[0][0] == 0) {
        update_state(lanes, ++rounds);
    }
    printf("%d\n", rounds);
    return 0;
}
