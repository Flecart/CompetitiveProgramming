#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100

bool searched[1000][1000];

void set_zero() {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            searched[i][j] = false;
        }
    }
}

vector<vector<int>> get_input() {
    char ch;
    int counter = 0;
    vector<vector<int>> table(0);
    vector<int> line(0);
    while (true) {
        cin >> ch;
        if (ch == '-') break;
        counter += 1;
        line.push_back((int)ch - '0');
        if (counter == MAX) {
            table.push_back(line);
            line = vector<int>(0); 
            counter = 0;
        }
    }
    return table;
}

int dfs(vector<vector<int>> table, int i, int j) {
    if (searched[i][j]) return 0;
    if (table[i][j] == 9) return 0;
    // printf("Searching %d, %d\n", i, j);
    searched[i][j] = true;
    int sum = 1;
    sum += dfs(table, i, max(j - 1, 0));
    sum += dfs(table, i, min(j + 1, MAX - 1));
    sum += dfs(table, max(i - 1, 0), j);
    sum += dfs(table, min((int) table.size() - 1, i + 1), j);
    return sum;
} 

int second_star(vector<vector<int>> table) {
    vector<int> ans;
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < MAX; j++) {
            int curr_value = table[i][j];
            int left = j > 0 ? table[i][j - 1] : 10;
            int right = j < MAX - 1 ? table[i][j + 1] : 10;
            int upper = i > 0 ? table[i - 1][j] : 10;
            int lower = i < table.size() - 1 ? table[i + 1][j] : 10;
            if (curr_value < left && curr_value < right && curr_value < upper && curr_value < lower) {
                int value = dfs(table, i, j);
                ans.push_back(value);
                // printf("%d: %d, %d: %d\n", curr_value, i , j, value);
            }
            set_zero();
        }
    }
    sort(ans.begin(), ans.end());
    int return_value = 1;
    for (int i = ans.size() - 1; i > ans.size() - 1 - 3; i--) {
        return_value *= ans[i];
    }
    return return_value;
}

int first_star(vector<vector<int>> table) {
    int ans = 0;
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < MAX; j++) {
            int curr_value = table[i][j];
            int left = j > 0 ? table[i][j - 1] : 10;
            int right = j < MAX - 1 ? table[i][j + 1] : 10;
            int upper = i > 0 ? table[i - 1][j] : 10;
            int lower = i < table.size() - 1 ? table[i + 1][j] : 10;
            if (curr_value < left && curr_value < right && curr_value < upper && curr_value < lower) {
                ans += curr_value + 1;
            }
        }
    }
    return ans;
}

int main() {
    set_zero();
    vector<vector<int>> table = get_input();
    cout << second_star(table) << endl;
}