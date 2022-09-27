#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    // devo avere un certo ordine su a
    // perché l'ultimo elemento di a deve essere la minore possibile
    // se poi b è dispari (altrimenti la quasi minore) 
    // (forse posso dire che posso spostare solo certi numeri???) 
    // si riesco a dimostrare che posso fare solo swap 2 a 2 ?
    int n; 
    cin >> n; 
    int arr[n]; 
    for (auto &i : arr) cin >> i; 
    int mmax;
    int start;
    if (n & 1) {
        mmax = arr[0];
        start = 1; 
    } else {
        start = 2;
        mmax = max(arr[0], arr[1]);
    }
    while (start < n - 1) {
        if (arr[start] > arr[start + 1]) swap(arr[start], arr[start + 1]);
        if (mmax > arr[start]) {
            cout << "NO\n";
            return; 
        } else mmax = arr[start + 1]; 
        // swappa e ordina bene 
        start += 2; 
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}