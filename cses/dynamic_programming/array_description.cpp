#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = (int)1e9 + 7;
/*
ARRAY DESCRIPTION:
I use dinamic programming method to compute all arrays that terminate
with a specific number at some index (this is calculated only from the
numbers of the array before).
If i got a 0, i just add last[i - 1] + last[i] + last[i + 1] because these
are the only ways i can get an array terminating with i.
if i got a l != 0, i just add last[l - 1] + last[l] + last[l + 1] and set everything to 0
because at this index i can just have l as terminating number, and i can get there in that 3 ways
*/
int main() {
    int n, m; cin >> n >> m;
    ll memo[2][m + 1];

    memset(memo, 0, sizeof(memo));
    // first number is special, decides the beginning of the dp
    // every row containst the arrays that end to that index
    int first; cin >> first;
    if (first == 0) {
        for (int i = 1; i <= m; i++) memo[0][i] = 1;
    } else {
        memo[0][first] = 1;
    }

    for (int i = 1; i < n; i++) {
        ll *curr_row = memo[i % 2];
        ll *last_row = memo[(i - 1) % 2];
        ll tmp; cin >> tmp;
        if (tmp == 0) {
            // do update
            for (int i = 1; i <= m; i++) {
                curr_row[i] = last_row[i];
                if (i - 1 >= 1) curr_row[i] += last_row[i - 1];
                if (i + 1 <= m) curr_row[i] += last_row[i + 1];
                curr_row[i] %= mod;
            }
        } else {
            for (int i = 1; i <= m; i++) {
                if (i == tmp) {
                    curr_row[tmp] = last_row[tmp];
                    if (tmp - 1 >= 1) curr_row[tmp] += last_row[tmp - 1];
                    if (tmp + 1 <= m) curr_row[tmp] += last_row[tmp + 1];
                    curr_row[tmp] %= mod;
                } else {
                    curr_row[i] = 0;
                }
            }
        }
    }

    ll ans = 0;
    ll *final_row = memo[(n - 1) % 2];
    for (int i = 1; i <= m; i++) {
       ans += final_row[i];
       ans %= mod; 
    }
    cout << ans << endl;
}