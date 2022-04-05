#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

stack<char> solution;
char table[1001][1001];
int times[1001][1001];
bool visited[1001][1001];
pair<int, int> player;
int n, m;

bool has_win(pair<int, int> &pos) {
    if (pos.first == 0 or pos.first == n - 1) return true;
    else if (pos.second == 0 or pos.second == m - 1) return true;
    else return false; 
}

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    return {a.first + b.first, a.second + b.second};
}

void set_time(queue<pair<int, pair<int, int>>> &q) { // time, pos x pos y
    // se visitato questa posizione, allora ho time minore!
    while (!q.empty()) {
        int time = q.front().first;
        pair<int, int> pos = q.front().second;
        q.pop();
        if (visited[pos.first][pos.second]) continue;
        if (time > times[pos.first][pos.second]) continue;
        visited[pos.first][pos.second] = true;
        times[pos.first][pos.second] = time; 

        // 4 direzioni 
        // sinistra
        pair<int, int> new_pos;
        new_pos = {pos.first - 1, pos.second};
        if (!visited[new_pos.first][new_pos.second] and new_pos.first >= 0 and table[new_pos.first][new_pos.second] == '.' and 
            times[new_pos.first][new_pos.second] > time + 1) {
                q.push({time + 1, new_pos});
        }

        new_pos = {pos.first + 1, pos.second};
        if (!visited[new_pos.first][new_pos.second] and new_pos.first < n and table[new_pos.first][new_pos.second]  == '.' and 
            times[new_pos.first][new_pos.second] > time + 1) {
                q.push({time + 1, new_pos});
        }

        new_pos = {pos.first, pos.second - 1};
        if (!visited[new_pos.first][new_pos.second] and new_pos.second >= 0 and table[new_pos.first][new_pos.second]  == '.' and 
            times[new_pos.first][new_pos.second] > time + 1) {
                q.push({time + 1, new_pos});
        }

        new_pos = {pos.first, pos.second + 1};
        if (!visited[new_pos.first][new_pos.second] and new_pos.second < m and table[new_pos.first][new_pos.second]  == '.' and 
            times[new_pos.first][new_pos.second] > time + 1) {
                q.push({time + 1, new_pos});
        }

    }
}

bool get_solution(pair<int, int> pos, char c_dir, int time) {
    if (has_win(pos)) {
        solution.push(c_dir);
        return true;
    }
    times[pos.first][pos.second] = time; // prevenire loop infinito
    pair<int, int> directions[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto dir : directions) {
        pair<int ,int> curr = pos + dir;
        if (times[curr.first][curr.second] <= time + 1) continue;// check for monster
        else if (curr.first < 0 or curr.first >= n or curr.second < 0 or curr.second >= m) continue; 
        else if (table[curr.first][curr.second] == '#') continue; // check for wall

        bool has_solved = false;
        if (dir == make_pair(1, 0)) {
            has_solved |= get_solution(curr, 'D', time + 1);
        } else if (dir == make_pair(-1, 0)) {
            has_solved |= get_solution(curr, 'U', time + 1);
        } else if (dir == make_pair(0, 1)) {
            has_solved |= get_solution(curr, 'R', time + 1);
        } else {
            has_solved |= get_solution(curr, 'L', time + 1);
        }

        if (has_solved) {
            solution.push(c_dir);
            return true;
        }
    }
    return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int, pair<int, int>>> monsters; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            times[i][j] = INT_MAX;
            visited[i][j] = false;
        }
    }

    for (int i = 0; i< n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch; 
            if (ch == '#' or ch == '.') table[i][j] = ch; 
            else if (ch == 'M') {
                monsters.push({0, {i, j}});
                table[i][j] = '.';
            } else if (ch == 'A'){
                player = {i, j};
                table[i][j] = '.';
            }
        }
    }
    set_time(monsters);
    
    if (get_solution(player, '-', 0)) {
        cout << "YES\n";
        solution.pop(); // pop the first 
        cout << solution.size() << endl; 
        while (!solution.empty()) {
            cout << solution.top();
            solution.pop();
        }
        cout << endl;
    } else cout << "NO\n";
}