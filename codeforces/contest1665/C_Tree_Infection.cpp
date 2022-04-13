#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXN (2 * (int) 1e5 + 3)
int n_childs[MAXN];

// return index of first not zero
int get_index(int a) {
    int ans = -1; // DO NOT TOUCH THIS DEF VALUE
    int upper = ceil(log2(a));
    for (int i = upper - 1; i >= 0; --i) {
        int index = ans + (1 << i);
        if (index > a or index < 0) continue;
        if (n_childs[index] != 0) {
            ans = index;
        } 
    }
    return ans + 1;  
}

void solve() {
    int a; cin >> a; 
    n_childs[0] = 1; // root node
    for (int i = 2; i <= a; i++) {
        int tmp; cin >> tmp;
        n_childs[tmp] += 1;
    }

    sort(n_childs, n_childs + (a + 1), greater<int>());
    int ans = get_index(a + 1);
    // update n_childs
    for (int i = 0; i < ans; ++i) {
        n_childs[i] = max(0, n_childs[i] - (ans - i));
    }
    sort(n_childs, n_childs + ans, greater<int>());
    int n_not_zero = get_index(ans); 

    while (true) {
        if (n_not_zero <= 0) break;
        ans += 1;
        int last = 0;
        for (int i = 0; i < n_not_zero; i++) {
            if (n_childs[i] == n_childs[0]) last = i;
            else break;
        }
        n_childs[last] -= 1; 

        for (int i = 0; i < n_not_zero; ++i) n_childs[i] -= 1;
        while (n_not_zero > 0 and n_childs[n_not_zero - 1] <= 0) n_not_zero--;
    }
    cout << ans << '\n';

    memset(n_childs, 0, (a + 1) * sizeof(int));
}
// parto da nodo con più figli, questo ci mette n_figli step a finirsi.
// contatore poi per 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while (n--) {
        solve();
    }
}