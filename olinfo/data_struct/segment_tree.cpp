#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const ll inf = 1e15;
const int kmax = 4 * 1e6 + 5;
int g_time;

constexpr int left(int n) {
    return (n + 1) * 2 - 1;
}

constexpr int right(int n) {
    return (n + 1) * 2;
}

constexpr int parent(int n) {
    return (n + 1) / 2 - 1;
}

struct mypair {
    ll sum;
    ll mmin;
    mypair() {}
    mypair(ll n): sum{n}, mmin{n} {}
    mypair(ll s, ll m): sum{s}, mmin{m}{}
    mypair operator+(const mypair &other) const {
        return {sum + other.sum, min(mmin, other.mmin)};
    }
};

vector<pair<int, int>> ranges(kmax);
vector<ll> mins(kmax);
vector<ll> sums(kmax); 
vector<ll> original(kmax);
vector<ll> lazy_add(kmax, 0); 
vector<ll> lazy_set(kmax, inf); 
vector<ll> time_set(kmax); 
vector<ll> time_add(kmax); 
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
    sums[v] += lazy_add[v] * (ranges[v].second - ranges[v].first + 1); 
    mins[v] += lazy_add[v];
    int mid = (ranges[v].first + ranges[v].second) / 2;
    if (v < sums.size() / 2) {
        lazy_add[left(v)] += lazy_add[v];
        lazy_add[right(v)] += lazy_add[v];
        time_add[right(v)] = time_add[left(v)] = time_add[v];
    }
    lazy_add[v] = 0;
}

void update_set(int v) {
    sums[v] = lazy_set[v] * (ranges[v].second - ranges[v].first + 1); 
    mins[v] = lazy_set[v];
    int mid = (ranges[v].first + ranges[v].second) / 2;
    if (v < sums.size() / 2) {
        lazy_set[left(v)] = lazy_set[v];
        lazy_set[right(v)] = lazy_set[v];
        time_set[left(v)] = time_set[right(v)] = time_set[v];
    }
    lazy_set[v] = inf;
}

void lazy_update(int v) {
    if (lazy_add[v] == 0 and lazy_set[v] == inf) return;
    if (lazy_set[v] == inf) {
        update_add(v);
        return;
    }
    if (lazy_add[v] == 0) {
        update_set(v);
        return;
    }
    // both active from here on:
    if (time_set[v] > time_add[v]) {
        // just overwrite the add!
        update_set(v);
    } else {
        lazy_set[v] += lazy_add[v];
        update_set(v);
    }
    lazy_add[v] = 0; 
}

void add(int v, int tl, int tr, int l, int r, ll x) {
    lazy_update(v);
    if (tl > r or tr < l) return; 
    if (l <= tl and tr <= r) {
        lazy_add[v] = x;
        time_add[v] = g_time++;
        update_add(v);
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
        lazy_set[v] = x;
        time_set[v] = g_time++;
        update_set(v);
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


int get_first(int v, int lv, int rv, int l, int r, ll x) {
    lazy_update(v);
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(mins[v] > x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            lazy_update(left(v));
            lazy_update(right(v));
            if(mins[left(v)] < x) {
                v = left(v);
                rv = mid;
            } else {
                v = right(v);
                lv = mid+1;
            }

        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(left(v), lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(right(v), mid+1, rv, l, r, x);
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
    return get_first(0, 0, g_size - 1, l, r - 1, x);
}

void init(vector<long long> a) {
    g_size = a.size(); 
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
