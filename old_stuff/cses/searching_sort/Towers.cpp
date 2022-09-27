#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<int, int> s; // set mapping number of times saw
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while (n--) {
        int block; cin >> block; 

        // get the best element to insert
        auto best = s.upper_bound(block);
        if (best == s.end()) {
            // access to non existent key defaults to int() (that is 0)
            // i'm adding 1 to this 0
            s[block] += 1;
        } else {
            best->second -= 1;
            if (best->second == 0) s.erase(best);
            s[block] += 1;
        }
    }

    int count = 0;
    for (auto it : s) {
        count += it.second;
    }
    cout << count;
}