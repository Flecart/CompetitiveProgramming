#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    int n_minus = 0;
    for (auto &i : arr) {
        cin >> i;
        if (i < 0) n_minus++;
        i = abs(i);
    }
    for (int i = 0; i < n_minus; i++) {
        arr[i] = -arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    /*
    int h = n - 1; 
    int l = 0;
    while (l < h) {
        while (arr[h] > arr[h - 1] and l < h) h--;
        while (arr[l] < arr[l + 1] and l < h) l++;
        
        if (arr[l] > 0 and arr[h] < 0) {
            arr[l] = -arr[l];
            arr[h] = -arr[h];
        } else {
            // vuol dire che è successo questo ma molto prima
            if (l < h){
                cout << "NO\n";
                return;
            }
        } 
    }
    cout << "YES\n";
    */
    /*
    int first_pos, invertible;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            first_pos = i; 
            break; 
        }
        if (i < n - 1) {
            if (arr[i] > arr[i + 1]) {
                cout << "NO\n";
                return;
            }
        }
    } */
    /*
    while (first_pos < last_neg) {
        arr[first_pos] = -arr[first_pos];
        arr[last_neg] = -arr[last_neg];

        if ()
    }

    while (idx >= 0) {
        if (arr[idx] > arr[idx + 1]) {
            if (last_neg == -1 or arr[idx] < 0) {
                cout << "NO\n";
                return;
            }
            arr[idx] = -arr[idx];
            arr[last_neg] = -arr[last_neg];
            if (last_neg < n - 1 and arr[last_neg] > arr[last_neg + 1]) {
                cout << "NO\n";
                return;
            }
            while (last_neg >= 0) {
                if (arr[last_neg] < 0) break; 
                last_neg--;
            }
        }
        idx--;
    }
    cout << "YES\n";
    */
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}