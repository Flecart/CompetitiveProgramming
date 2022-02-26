#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int p[n];
    int c[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    sort(p, p + n);
    sort(c, c + m);

    int ans = 0;
    int person = 0, house = 0;
    while (person < n && house < m) {
        int dff = p[person] - c[house];

        if (abs(dff) <= k) {
            ans += 1;
            person += 1;
            house += 1;
        } else if (abs(dff) > k && dff < 0) person ++;
        else if (abs(dff) > k && dff > 0) house ++;
    }

    cout << ans << endl; 
    return 0;
}