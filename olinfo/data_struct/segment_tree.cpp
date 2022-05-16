#pragma GCC optimize("Ofast,unroll-loops")
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
const ll inf = 1e15;
const int kmax = 4 * 1e6 + 1;
int g_time;

constexpr int left(int n) {
    return n * 2 + 1;
}

constexpr int right(int n) {
    return n * 2 + 2;
}

pair<int, int> ranges[kmax];
ll mins[kmax];
ll sums[kmax]; 
ll lazy[kmax]; 
vector<bool> is_set(kmax); 
int g_tree_size;
int g_size;

void build(int v, int l, int r, const vector<ll> &original) {
    ranges[v] = {l, r};
    if (l == r) {
        mins[v] = original[l];
        sums[v] = original[l];
        return;
    }

    int mid = (l + r) / 2;
    build(left(v), l, mid, original);
    build(right(v), mid + 1, r, original);
    mins[v] = min(mins[left(v)], mins[right(v)]);
    sums[v] = sums[left(v)] + sums[right(v)];
}

void update_add(int v) {
    sums[v] += lazy[v] * (ranges[v].second - ranges[v].first + 1); 
    mins[v] += lazy[v];
    int mid = (ranges[v].first + ranges[v].second) / 2;
    if (v < g_tree_size / 2) {
        if (lazy[left(v)] == inf) lazy[left(v)] = 0;
        if (lazy[right(v)] == inf) lazy[right(v)] = 0;
        lazy[left(v)] += lazy[v];
        lazy[right(v)] += lazy[v];
        // se figli sono nodi di set, continua a settare a un valore aggiunto
        // altrimenti la flag resta false, quindi sommo
    }
    lazy[v] = inf;
}

void update_set(int v) {
    sums[v] = lazy[v] * (ranges[v].second - ranges[v].first + 1); 
    mins[v] = lazy[v];
    int mid = (ranges[v].first + ranges[v].second) / 2;
    if (v < g_tree_size / 2) {
        lazy[left(v)] = lazy[v];
        lazy[right(v)] = lazy[v];
        is_set[left(v)] = is_set[right(v)] = true; 
    }
    is_set[v] = false; 
    lazy[v] = inf;
}

void lazy_update(int v) {
    if (lazy[v] != inf) {
        if (is_set[v]) update_set(v);
        else update_add(v); 
    }
}

void add(int v, int tl, int tr, int l, int r, ll x) {
    lazy_update(v); // update in ogni caso correttezza di cose sopra
    if (tl > r or tr < l) return; 
    if (l <= tl and tr <= r) {
        mins[v] += x;
        sums[v] += x * (tr - tl + 1);
        if (tl != tr) {
            if (lazy[left(v)] == inf) lazy[left(v)] = 0;
            if (lazy[right(v)] == inf) lazy[right(v)] = 0;
            lazy[left(v)] += x;
            lazy[right(v)] += x;
        }
        return;
    }
    int mid = (tl + tr) / 2;
    add(left(v), tl, mid, l, r, x);
    add(right(v), mid + 1, tr, l ,r, x);
    mins[v] = min(mins[left(v)], mins[right(v)]);
    sums[v] = sums[left(v)] + sums[right(v)];
}

void set_range(int v, int tl, int tr, int l, int r, ll x) {
    lazy_update(v);
    if (tl > r or tr < l) return; 
    if (l <= tl and tr <= r) {
        sums[v] = x * (tr - tl + 1); 
        mins[v] = x; 
        if (tl != tr) {
            lazy[left(v)] = lazy[right(v)] = x;
            is_set[left(v)] = is_set[right(v)] = true;
        }
        return;
    }

    int mid = (tl + tr) / 2;
    set_range(left(v), tl, mid, l, r, x);
    set_range(right(v), mid + 1, tr, l ,r, x);
    mins[v] = min(mins[left(v)], mins[right(v)]);
    sums[v] = sums[left(v)] + sums[right(v)];
}

ll get_sum(int v, int l, int r, int tl, int tr) {
    lazy_update(v);
    if (tr < l or tl > r) return 0ll;
    if (l <= tl and tr <= r) {
        return sums[v];
    }
    int mid = (tl + tr) / 2;
    return get_sum(left(v), l, r, tl, mid) + 
        get_sum(right(v), l, r, mid + 1, tr);
}

ll get_min(int v, int l, int r, int tl, int tr) {
    lazy_update(v);
    if (tr < l or tl > r) return inf; 
    if (l <= tl and tr <= r) {
        return mins[v];
    }
    int mid = (tl + tr) / 2;
    return min(get_min(left(v), l, r, tl, mid),
            get_min(right(v), l, r, mid + 1, tr));
}


int lower_bound(int v, int lv, int rv, int l, int r, ll x) {
    lazy_update(v);
    if(lv > r or rv < l) return -1;
    if(l <= lv and rv <= r) {
        if(mins[v] > x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            lazy_update(left(v));
            if(mins[left(v)] < x) {
                v = left(v);
                rv = mid;
            } else {
                v = right(v);
                lv = mid+1;
            }
            lazy_update(v);
        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = lower_bound(left(v), lv, mid, l, r, x);
    if(rs != -1) return rs;
    return lower_bound(right(v), mid+1, rv, l, r, x);
}

ll get_sum(int l, int r) {
    return get_sum(0, l, r - 1, 0, g_size - 1);
}
void add(int l, int r, ll x) {
    add(0, 0, g_size - 1, l, r - 1, x);
}
void set_range(int l, int r, ll x) {
    set_range(0, 0, g_size - 1, l, r - 1, x);
}
ll get_min(int l, int r) {
    return get_min(0, l, r - 1, 0, g_size - 1);
}
int lower_bound(int l, int r, ll x) {
    return lower_bound(0, 0, g_size - 1, l, r - 1, x);
}

void init(vector<long long> a) {
    for (ll &i : lazy) i = inf;

    g_size = a.size(); 
    g_tree_size = (a.size() * 4);
    build(0, 0, g_size - 1, a);
    g_time = 0;
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
		long long x;
		cin >> op;
		cin >> l >> r;
		if (op == 2 or op == 3 or op == 5)
			cin >> x;
		if (op == 1) cout << get_sum(l, r) << "\n";
		if (op == 2) add(l, r, x);
		if (op == 3) set_range(l, r, x);
		if (op == 4) cout << get_min(l, r) << "\n";
		if (op == 5) cout << lower_bound(l, r, x) << "\n";
	}
	
	return 0;
}
