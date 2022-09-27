#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> sols; 
    vector<int> to_insert;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        to_insert.clear();
        to_insert.push_back(tmp);
        for (auto i : sols) {
            to_insert.push_back(i + tmp);
        }
        for (auto i : to_insert) sols.insert(i);
    }
    cout << sols.size() << '\n';
    for (auto i : sols) cout << i << ' ';
}