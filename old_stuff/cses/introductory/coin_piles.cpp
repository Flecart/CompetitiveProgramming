#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int start;
    cin >> start;
    while (start--) {
        int a, b;
        cin >> a >> b;

        bool possible = false;
        int second_row = (a - 2*b);
        if (second_row % 3 == 0) {
            // solving 2 eq 2 unknown system.
            int f_move, s_move;
            s_move = second_row / (-3);
            f_move = b - 2 * s_move;
            if (s_move >= 0 && f_move >= 0) possible = true;
        }

        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}