#include <iostream>
#include <cstring> 
using namespace std;
#define MAX 1000

struct input {
    int x1;
    int y1;
    int x2;
    int y2;
};

void update(int arr[][MAX], input inp, bool first_star=false) {
    if (inp.x1 == inp.x2) {
        int min_y = min(inp.y1, inp.y2);
        int max_y = max(inp.y1, inp.y2); 
        for (int i = min_y; i <= max_y; i++) {
            arr[inp.x1][i] += 1;
        }
    } else if (inp.y1 == inp.y2) {
        int min_x = min(inp.x1, inp.x2);
        int max_x = max(inp.x1, inp.x2); 
        for (int i = min_x; i <= max_x; i++) {
            arr[i][inp.y1] += 1;
        }
    }
    // DONT EXECUTE THIS IF FIRST STAR!
    if (first_star) return;
    
    bool is_first_diag = (inp.x1 - inp.x2 == inp.y1 - inp.y2);
    bool is_second_diag = (inp.x1 - inp.x2 == inp.y2 - inp.y1);
    
    if (inp.x1 > inp.x2) {
        swap(inp.x2, inp.x1);
        swap(inp.y2, inp.y1);
    }

    if (is_first_diag) {
        for (int i = 0; i <= inp.x2 - inp.x1; i++) {
            arr[inp.x1 + i][inp.y1 + i] += 1;
        }
    }
    
    if (is_second_diag) {
        for (int i = 0; i <= inp.x2 - inp.x1; i++) {
            arr[inp.x1 + i][inp.y1 - i] += 1;
        }
    }
}

int get_ans(int arr[][MAX]) {
    int ans = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr[i][j] > 1) ans += 1;
        }
    }
    return ans;
}

int main() {
    int arr[MAX][MAX];
    memset(arr, 0, sizeof(arr));
    while (true) {
        input inp; 
        scanf("%d,%d -> %d,%d", &inp.x1, &inp.y1, &inp.x2, &inp.y2);
        if (inp.x1 == -1) break;
        update(arr, inp);
    }
    cout << get_ans(arr);
}