#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 10
struct point {
    int i;
    int j;
};

void get_input(int arr[][MAX]) {
    string line;
    cin >> line;
    int i = 0;
    while (line.compare("-") != 0) {
        for (int j = 0; j < MAX; j++) {
            arr[i][j] = line[j] - '0';
        }
        i += 1;
        cin >> line;
    }
}

void _prop(int arr[][MAX], bool prop[][MAX], point p, queue<point> *coda) {
    if (prop[p.i][p.j]) return;
    prop[p.i][p.j] = true;
    // printf("Propagating point: %d, %d\n", p.i, p.j);
    int upper = max(0, p.i - 1);
    int lower = min(MAX - 1, p.i + 1);
    int left = max(0, p.j - 1);
    int right = min(MAX - 1, p.j + 1);

    for (int i = upper; i <= lower; i++) {
        for (int j = left; j <= right; j++) {
            arr[i][j] += 1;
        }
    }

    for (int i = upper; i <= lower; i++) {
        for (int j = left; j <= right; j++) { 
            if (!prop[i][j] && arr[i][j] > 9) {
                point curr_point = {i, j};
                coda->push(curr_point);
            }
        }
    }
    return;
}

int propagate(int arr[][MAX], bool has_propagated[][MAX]) { 
    int count = 0;
    queue<point> coda;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++){
            if (arr[i][j] > 9) {
                point p = {i, j};
                coda.push(p);
            }
        }
    }

    while (!coda.empty()) {
        point p = coda.front();
        coda.pop();
        if (!has_propagated[p.i][p.j]) count += 1;
        _prop(arr, has_propagated, p, &coda);
    }

    // Octopuses lost all their energy when they flashed!
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++){
            if (arr[i][j] > 9) {
                arr[i][j] = 0;
            }
        }
    }
    return count;
}

int step(int arr[][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++){
            arr[i][j] += 1;
        }
    }
    bool has_propagated[MAX][MAX];
    memset(has_propagated, 0, sizeof(has_propagated));
    return propagate(arr, has_propagated);
}

bool is_simultaneous(int arr[][MAX]) {
    int first = arr[0][0];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr[i][j] != first) return false;
        }
    }
    return true;
}

void first_star() {
    int data[MAX][MAX];
    get_input(data);
    long long ans = 0;
    for (int i = 0; i < 100; i++) {
        ans += step(data);
    }
    cout << ans << endl;
}

void second_star() {
    int data[MAX][MAX];
    get_input(data);
    long long ans = 0;
    while (!is_simultaneous(data)) {
        step(data);
        ans += 1;
    }
    cout << ans << endl;
}

int main() {
    second_star();
}