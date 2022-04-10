#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h> 
#define MAXN 1000
using namespace std; 
int R, C, i, j;
int M[MAXN][MAXN]; 
bool visited[MAXN][MAXN];

struct point {
    int x;
    int y;
    point operator+(const point &other) const {
        return {x + other.x, y + other.y}; 
    }
}; 

vector<point> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool is_border(point p) {
    return p.x <= 0 or p.x >= R - 1 or p.y <= 0 or p.y >= C - 1; 
}

bool is_island(point p) {
    if (visited[p.x][p.y] or M[p.x][p.y] == 0) return false; 
    visited[p.x][p.y] = true; 

    bool ans = is_border(p) ? false : true; 
    for (point dir : dirs) {
        point curr = dir + p;
        if (visited[curr.x][curr.y]) continue;  
        if (is_border(curr) and M[curr.x][curr.y]) {
            is_island(curr); // continua a marcare tutte le raggiungibili come visitate;
            ans = false; 
        } else if (M[curr.x][curr.y]) {
            ans &= is_island(curr);
        }
    }
    return ans; 
}

int main() {

    assert(2 == scanf("%d %d", &R, &C));
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    int island_count = 0; 
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (M[i][j] and !visited[i][j] and is_island({i, j})) island_count += 1;
        }
    }

    printf("%d\n", island_count); // print the result
    return 0;
}
