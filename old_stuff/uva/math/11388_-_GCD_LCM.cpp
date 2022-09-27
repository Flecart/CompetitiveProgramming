#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;

    while (n--) {
        int g, l; cin >> g >> l;
        if (l % g != 0) {
            cout << -1 << endl;
            continue;
        } 
        // the observation is that if one divides the other
        // which must happen if LCM is LCM, else it is absurd
        // then the input sol is enough!
        cout << g << ' ' << l << endl; 
    }
}
