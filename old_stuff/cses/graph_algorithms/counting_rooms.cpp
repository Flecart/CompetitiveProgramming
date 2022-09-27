#include <bits/stdc++.h>

using namespace std;

char room[1000][1000];
int state[1000][1000]; // room number checker

int n, m; 
int n_rooms = 0;

bool found_room(int i, int j) {
    if (room[i][j] == '#') return false; // wall
    if (state[i][j] > 0) return false; // already visited
    state[i][j] = n_rooms + 1;
    if (i > 0) found_room(i - 1, j);
    if (i < n - 1) found_room(i + 1, j);
    if (j > 0) found_room(i, j - 1);
    if (j < m - 1) found_room(i, j + 1);
    return true;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (found_room(i, j)) n_rooms++;
        }
    }
    cout << n_rooms << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    solve();
}