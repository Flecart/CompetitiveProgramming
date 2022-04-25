#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXROW 22
#define MAXCIRC 360

int table[MAXROW][MAXCIRC];
bool visited[MAXROW][MAXCIRC];

inline void wall_up(int grade, int circ) {
    table[grade][circ] |= (1 << 3);
}
inline void wall_left(int grade, int circ) {
    table[grade][circ] |= (1 << 2);
}

inline void wall_right(int grade, int circ) {
    table[grade][circ] |= (1 << 1);
}

inline void wall_down(int grade, int circ) {
    table[grade][circ] |= 1;
}

inline bool get_wall_up(int grade, int circ) {
    return (table[grade][circ] >> 3) & 1;
}

inline bool get_wall_left(int grade, int circ) {
    return (table[grade][circ] >> 2) & 1;
}

inline bool get_wall_right(int grade, int circ) {
    return (table[grade][circ] >> 1) & 1;
}

inline bool get_wall_down(int grade, int circ) {
    return (table[grade][circ] & 1);
}

inline int wrap(int n) {
    return n >= MAXCIRC ? n - MAXCIRC : (n < 0 ? n + MAXCIRC : n);
}

void dfs(int row, int grad) {
    if (row >= MAXROW or grad < 0 or grad >= MAXCIRC) return;
    visited[row][grad] = true;

    if (row + 1 < MAXROW and !get_wall_down(row, grad) and !visited[row + 1][grad]) {
        dfs(row + 1, grad);
    }

    if (row - 1 >= 0 and !get_wall_up(row, grad) and !visited[row - 1][grad]) {
        dfs(row - 1, grad);
    }

    int newgrad = wrap(grad - 1);
    if (!get_wall_left(row, grad) and !visited[row][newgrad]) {
        dfs(row, newgrad);
    }

    newgrad = wrap(grad + 1);
    if (!get_wall_right(row, grad) and !visited[row][newgrad]) {
        dfs(row, newgrad);
    }
}

void solve() {
    memset(table, 0, sizeof(table));
    memset(visited, 0, sizeof(visited));
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char ch; 
        int r, from, to;
        cin >> ch >> r >> from >> to;

        if (ch == 'C') {
            // raggio, from ,to 
            for (int i = from; i != to; i = (i + 1) % MAXCIRC) {
                wall_down(r - 1, i);
                wall_up(r, i);
            }
        } else {
            // r1, r2, angle;
            swap(from, to); swap(r, from);
            // angle, r1, r2;
            for (int i = from; i < to; i++) {
                wall_left(i, r); // default is left
                if (r == 0) wall_right(i, MAXCIRC - 1);
                else wall_right(i, r - 1);
            }
        }
    }
    dfs(0, 0);
    // out ans;
    if (visited[MAXROW - 1][0]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}