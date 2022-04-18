#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 2 * (int) 1e5 + 3
int ans[MAX];
int elem[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    elem[0] = 0;
    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> elem[i];
        if (elem[i - 1] < elem[i]) ans[i] = i - 1;
        else {
            // caso peggiore è N, ma non può mai succedere per N volte
            // quindi non so come contare ste cose D:
            int index = ans[i - 1];
            while (elem[index] >= elem[i]) {
                // cerr << index << " ";
                index = ans[index]; // minimo 0
            } 
            // cerr << "end\n";
            ans[i] = index;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}