#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int index) {
    while (arr[index] != index) {
        index = arr[index];
    }
    return index;
}

int find_rec(int arr[], int index) {
    if (arr[index] == index) return index; // its the head of the list
    else return arr[index] = find_rec(arr, arr[index]); // amortized constant set 
}

bool isSameSet(int arr[], int a, int b) {
    return find_rec(arr, a) == find_rec(arr, b);
}

void unionSet(int arr[], int a, int b) {
    arr[find_rec(arr, a)] = find_rec(arr, b);
}


int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i;
    while (m--) {
        int a,b;
        cin >> a >> b; a--; b--;
        if (!isSameSet(arr, a, b)) {
            unionSet(arr, a, b);
        }
    }
    set<int> set_heads;
    for (int i = 0; i < n; i++) set_heads.insert(find_rec(arr, i) + 1);

    cout << set_heads.size() - 1 << '\n'; // - 1 because need only n - 1 arcs to link n nodes
    auto first = set_heads.begin();
    auto second = first;
    second++;
    while (second != set_heads.end()) {
        cout << *first << ' ' << *second << '\n';
        first++; second++; 
    }
}