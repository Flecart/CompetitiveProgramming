#include <iostream>
#include <vector>
using namespace std;

// Euristics maximum
#define MAX 1000

int sum_till(int x) {
    return (x*(x+1)/ 2);
}

void first_star() {
    int maximum_y = 0;
    int y_count = 0;
    for (int i = 1; i < MAX; i++) {
        // random + 2 just bc i like it, no other reason
        // it just needs to be above the first one.
        for (int j = i + 1; j < MAX + 2; j++) {
            int op = sum_till(i) - sum_till(j);
            if (op >= -10 && op <= -5) {
                maximum_y = sum_till(i);
                printf("%d, %d, %d\n", maximum_y, i, j);
                y_count += 1;
            }
        }
    }
}

struct point
{
    int x;
    int y;
};


bool simulate(point v_start, int x_min, int x_max, int y_min, int y_max) {
    bool reached = false;
    point current = {0, 0};
    while (current.x <= x_max && current.y >= y_min && !reached) {
        current.x += v_start.x;
        current.y += v_start.y;
        if (current.x <= x_max && current.x >= x_min &&  current.y >= y_min && current.y <= y_max) reached = true;
        v_start.x = max(0, v_start.x - 1);
        v_start.y = v_start.y - 1;
    }
    return reached;
}

void second_star() {
    int y_min = -108;
    int y_max = -68;
    int x_min = 169;
    int x_max = 206;
    int final_ans = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = -200; j < MAX; j++) {
            point velocity = {i, j};
            if (simulate(velocity, x_min, x_max, y_min, y_max)) {
                final_ans += 1;
            }
        }
    }
    cout << final_ans << endl;
}

int main() {
    second_star();
}