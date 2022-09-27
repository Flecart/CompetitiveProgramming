
#include <bits/stdc++.h>
 
using namespace std;
 
char room[1000][1000];
int n, m; 
 
struct pos {
    int x;
    int y;
};
pos start;
pos finish;
 
struct node {
    char dir;
    int steps;
    pos curr;
};
 

node states[1000][1000];
/* LABYRINTY:
 * This is one of my first programs that i made
 * almost entirely on the vim editor :D. Such difficult, 
 * but sometimes i like this... sometimes....
 *
 * Anyways, lets talk about the problem, i just made a bfs
 * so i'm sure the thing i got is the shortest one.
 * I just messed a little bit about the naming of the node pos
 * and curr variable, anyways this works. (at the end i use a stack
 * to invert the order of the prints
 */

void update(int steps, pos next, const char ch, queue<node> &q) {
   if (room[next.x][next.y] == '#') return;
   int s = states[next.x][next.y].steps;
   if (s > 0 and steps >=  s) return;
   q.push({ch, steps, next});
   states[next.x][next.y] = {ch, steps, next};
}

bool solve() {
    queue<node> to_check;
    to_check.push(states[start.x][start.y]);
    bool found = false;

    while (!to_check.empty()) {
        node curr = to_check.front(); 
        if (room[curr.curr.x][curr.curr.y] == 'B') {
            found = true;
            break;
        }
        to_check.pop();
        if (curr.curr.x > 0) update(curr.steps + 1, {curr.curr.x - 1, curr.curr.y}, 'U', to_check);
        if (curr.curr.x < n - 1) update(curr.steps + 1, {curr.curr.x + 1, curr.curr.y}, 'D', to_check);
        if (curr.curr.y > 0) update(curr.steps + 1, {curr.curr.x, curr.curr.y - 1}, 'L', to_check);
        if (curr.curr.y < m - 1) update(curr.steps + 1, {curr.curr.x, curr.curr.y + 1}, 'R', to_check);
    }
    return found;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
            if (room[i][j] == 'A') start = {i, j};
            if (room[i][j] == 'B') finish = {i, j};
        }
    }
    states[start.x][start.y] = { ' ', 0, start };
    if (solve()) {
        cout << "YES\n";
        cout << states[finish.x][finish.y].steps << '\n';
        node curr = states[finish.x][finish.y];
        stack<char> s; // only using this to inver the print order
        while (curr.curr.x != start.x or curr.curr.y != start.y) {
            s.push(curr.dir);
            if (curr.dir == 'D') curr = states[curr.curr.x - 1][curr.curr.y];
            else if (curr.dir == 'U') curr = states[curr.curr.x + 1][curr.curr.y];
            else if (curr.dir == 'L') curr = states[curr.curr.x][curr.curr.y + 1];
            else if (curr.dir == 'R') curr = states[curr.curr.x][curr.curr.y - 1];
            else cerr << "WHATTAFUCK" << '\n'; 
        } 
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
}
