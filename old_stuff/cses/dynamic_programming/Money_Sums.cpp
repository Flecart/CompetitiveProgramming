#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 1000005
bitset<MAX> row[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    row[0].reset(); 
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr[i] > j) {
                row[i][j] = row[i - 1][j];
            } else {
                if (row[i - 1][j]) row[i][j] = true; 
                else if (row[i - 1][j - arr[i]]) row[i][j] = true;
            }
        }
        row[i][arr[i]] = true;
    }
    set<int> sols; 
    for (int i = 0; i < MAX; i++) {
        if (row[n][i]) sols.insert(i);
    }
    cout << sols.size() << '\n';
    for (auto i : sols) cout << i << ' ';
}