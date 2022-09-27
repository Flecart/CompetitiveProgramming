#pragma GCC optimize("Ofast,unroll-loops")
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
const ll inf = 1e15;
const int kmax = (1 << 21);

constexpr int left(int n) {
    return n * 2 + 1;
}

constexpr int right(int n) {
    return n * 2 + 2;
}

struct node {
    ll mmin;
    ll sum;
    ll x; // the value 
    bool is_set; // either set, or add
    node() {}
    node (ll mmin, ll sum) {
        this->mmin = mmin;
        this->sum = sum;
        x = inf;
        is_set = false; 
    }

    node (ll coso): node(coso, coso) {}

    void operator +=(const node &other) {
        mmin = min(mmin, other.mmin);
        sum += other.sum;
    }
    void merge(const node &first, const node &second) {
        mmin = min(first.mmin, second.mmin);
        sum = first.sum ^ second.sum;
    }
};


pair<int, int> ranges[kmax];
node nodes[kmax];
int g_tree_size;
int g_size;
int l, r; // gli l e r della chiamata!

void build(int v, int l, int r, const vector<ll> &original) {
    ranges[v] = {l, r};
    if (l == r) {
        nodes[v] = node(original[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(left(v), l, mid, original);
    build(right(v), mid + 1, r, original);
    nodes[v].merge(nodes[left(v)], nodes[right(v)]);
}

ll range_xor(int v, int tl, int tr) {
    if (tr < l or tl > r) return 0ll;
    if (l <= tl and tr <= r) {
        return nodes[v].sum;
    }
    return range_xor(left(v), tl, (tl + tr) / 2) ^
        range_xor(right(v), (tl + tr) / 2 + 1, tr);
}

ll range_xor(int a, int b) {
    l = a;
    r = b - 1;
    return range_xor(0, 0, g_size - 1);
}

void init(vector<long long> &a) {
    g_size = a.size(); 
    g_tree_size = min(kmax, (int)(a.size() * 4));
    build(0, 0, g_size - 1, a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	init(a);
	
	for (int i = 0; i < q; i++) {
		int op, l, r;
		cin >> l >> r;
        cout << range_xor(l - 1, r) << "\n";
	}
	
	return 0;
}
