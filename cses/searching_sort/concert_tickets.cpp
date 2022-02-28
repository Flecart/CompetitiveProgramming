#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;

    for (int i = 0; i < n; i++)  {
        int tmp; cin >> tmp;
        s.insert({-tmp, i}); // saving -x because i want to use lower bound (first that is the same) i bacause i want it unique
    }

    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        auto found = s.lower_bound({-tmp, -1});
        if (found == s.end()) cout << -1 << " ";
        else {
            cout << -1 * found->first << " ";
            s.erase(found);
        };
    }

    return 0;
}