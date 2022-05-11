#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

const int kmax = 2 * 1e5 + 2;
int depth;
int merge_sort[20][kmax];

void build(vi &arr, int l, int h, int level = 0) {
    if (l == h) return merge_sort[level][l] = arr[l], void();
    int mid = l + h >> 1;
    build(arr, l, mid, level + 1);
    build(arr, mid + 1, h, level + 1);
    int i = l, idx = l, j = mid + 1; 
    while (i <= mid and j <= h) {
        if (merge_sort[level + 1][i] < merge_sort[level + 1][j]) {
            merge_sort[level][idx++] = merge_sort[level + 1][i++];
        } else merge_sort[level][idx++] = merge_sort[level + 1][j++];
    }

    while (i <= mid) merge_sort[level][idx++] = merge_sort[level + 1][i++];
    while (j <= h) merge_sort[level][idx++] = merge_sort[level + 1][j++];
}

int binary_search(int l, int h, int arr[], int value) {
    while (l < h - 1) {
        int mid = l + h >> 1; 
        if (arr[mid] <= value) l = mid;
        else h = mid; 
    }
    return h;
}

ll query(int l, int h, int ml, int mh, int level, int value) {
    if (mh < l) return 0;
    if (ml > h) return 0;
    if (l <= ml and mh <= h) {
        int idx = binary_search(ml - 1, mh + 1, merge_sort[level], value);
        return idx - ml;
    }

    int mid = ml + mh >> 1; 
    ll ans = 0;
    ans += query(l, h, ml, mid, level + 1, value);
    ans += query(l, h, mid + 1, mh, level + 1, value);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    depth = log2(n - 1) + 1;
    vi arr(n);
    // merge_sort.assign(depth, vi(n));
    for (int &i : arr) cin >> i;
    build(arr, 0, n - 1);

    // for (int i = 0; i <= depth; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cerr << merge_sort[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += query(i + 1, n - 1, 0, n - 1, 0, arr[i]);
        // cerr << i << " " << ans << endl;
    }
    // cerr << endl;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}