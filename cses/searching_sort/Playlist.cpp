#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX ((int) 1e9 + 3)

bitset<MAX> present; 

deque<int> playlist;
// PLAYLIST
// i use the deque to retain information about the order
// and the present bitset to check quickly if its in the deque
// instead of searching linearly
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n; 
    int max_size = 0;
    while (n--) {
        int d; cin >> d; // d per disco
        if (present[d]) {
            int curr;
            while ((curr = playlist.front()) != d) {
                present[curr] = false;
                playlist.pop_front();
            }
            playlist.pop_front(); // elimina anche d corrente
        } else {
            present[d] = true; 
        }
        playlist.push_back(d);

        if (playlist.size() > max_size) max_size = playlist.size();
    }
    cout << max_size;
}