#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
const ll inf = 1e17;
int left(int n) {
    return (n + 1) * 2 - 1;
}

int right(int n) {
    return (n + 1) * 2;
}

int parent(int n) {
    return (n + 1) / 2 - 1;
}

struct mypair {
    ll sum;
    ll mmin;
    int idx; // index for the lower bound
    mypair() {}
    mypair(ll n, int i): sum{n}, mmin{n}, idx{i} {}
    mypair(ll s, ll m): sum{s}, mmin{m}{}
    mypair operator+(const mypair &other) const {
        return {sum + other.sum, min(mmin, other.mmin)};
    }
};

struct ST {
    vector<mypair> t; // tree (sum, min)
    vector<ll> original;
    vector<ll> lazy_add; 
    vector<ll> lazy_min; 
    vector<ll> lazy_set;
    vector<ll> lazy_value;
    int default_set;
    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = mypair(original[l], l);
            return;
        }

        int mid = (l + r) / 2;
        build(left(v), l, mid);
        build(right(v), mid + 1, r);
        t[v] = t[left(v)] + t[right(v)]; 
    }

    ST(vector<ll> &arr) {
        default_set = 1e9;
        int size = arr.size() * 4 + 1; 
        t.assign(size, mypair(0, inf));
        original = arr;
        build(0, 0, original.size() - 1);

        lazy_set.assign(size, default_set); // offset of range set
        lazy_value.assign(size, default_set); // offset of single set
        lazy_add.assign(size, 0); // offset of range
        lazy_min.assign(size, 0); // offset of single
    }

    void update_to_root(int v) {
        while (v > 0) {
            t[v] = t[left(v)] + t[right(v)];
            v = parent(v);
        }
    }

    ll get_sum(int v, int l, int r, int tl, int tr) {
        if (tr < l or tl > r) return 0ll;
        lazy_update(v);
        if (l <= tl and tr <= r) {
            return t[v].sum;
        }
        int mid = (tl + tr) / 2;
        ll sum = 0;
        sum += get_sum(left(v), l, r, tl, mid);
        sum += get_sum(right(v), l, r, mid + 1, tr);
        return sum;
    }
    ll get_sum(int l, int r) {
        return get_sum(0, l, r - 1, 0, original.size() - 1);
    }

    void flazy_add(int v) {
        if (lazy_add[v] == 0) return;
        t[v].sum += lazy_add[v];
        t[v].mmin += lazy_min[v];

        if (v < t.size() / 2) {
            lazy_update(left(v));
            lazy_update(right(v));

            lazy_add[left(v)] += lazy_add[v] / 2;
            lazy_add[right(v)] += lazy_add[v] / 2;
            lazy_min[left(v)] += lazy_min[v];
            lazy_min[right(v)] += lazy_min[v];
        }
        lazy_add[v] = 0;
        lazy_min[v] = 0;
    }

    void flazy_set(int v) {
        if (lazy_set[v] == default_set) return;
        t[v].sum = lazy_set[v];
        t[v].mmin = lazy_value[v];

        if (v < t.size() / 2) {
            lazy_update(left(v));
            lazy_update(right(v));

            lazy_set[left(v)] = lazy_set[v] / 2;
            lazy_set[right(v)] = lazy_set[v] / 2;
            lazy_value[left(v)] = lazy_value[v];
            lazy_value[right(v)] = lazy_value[v];
        }

        lazy_set[v] = default_set;
        lazy_value[v] = default_set;
    }

    void lazy_update(int v) {
        flazy_add(v);
        flazy_set(v);
    }

    void add(int v, int tl, int tr, int l, int r, ll x) {
        if (tl > r or tr < l) return; 
        lazy_update(v);
        if (l <= tl and tr <= r) {
            lazy_add[v] = x * (tr - tl + 1);
            lazy_min[v] = x;
            lazy_update(v);
            return;
        }

        int mid = (tl + tr) / 2;
        add(left(v), tl, mid, l, r, x);
        add(right(v), mid + 1, tr, l ,r, x);
        t[v] = t[left(v)] + t[right(v)];
    }
    
    void add(int l, int r, ll x) {
        add(0, 0, original.size() - 1, l, r - 1, x);
    }

    void set_range(int v, int tl, int tr, int l, int r, ll x) {
        if (tl > r or tr < l) return; 
        lazy_update(v);
        if (l <= tl and tr <= r) {
            lazy_set[v] = x * (tr - tl + 1);
            lazy_value[v] = x;
            lazy_update(v);
            return;
        }

        int mid = (tl + tr) / 2;
        set_range(left(v), tl, mid, l, r, x);
        set_range(right(v), mid + 1, tr, l ,r, x);
        t[v] = t[left(v)] + t[right(v)];
    }

    void set_range(int l, int r, ll x) {
        set_range(1, 0, original.size() - 1, l, r - 1, x);
    }

    ll get_min(int v, int l, int r, int tl, int tr) {
        if (tr < l or tl > r) return inf; 
        lazy_update(v);
        if (l <= tl and tr <= r) {
            return t[v].mmin;
        }
        int mid = (tl + tr) / 2;
        ll mmin = inf;
        mmin = min(mmin, get_min(left(v), l, r, tl, mid));
        mmin = min(mmin, get_min(right(v), l, r, mid + 1, tr));
        return mmin;
    }

    ll get_min(int l, int r) {
        return get_min(0, l, r - 1, 0, original.size() - 1);
    }

    int get_first(int v, int lv, int rv, int l, int r, ll x) {
        if(lv > r || rv < l) return -1;
        lazy_update(v);
        if(l <= lv && rv <= r) {
            if(t[v].mmin >= x) return -1;
            while(lv != rv) {
                int mid = lv + (rv-lv)/2;
                if(t[left(v)].mmin < x) {
                    v = left(v);
                    rv = mid;
                }else {
                    v = right(v);
                    lv = mid+1;
                }
            }
            return lv;
        }

        int mid = lv + (rv-lv)/2;
        int rs = get_first(left(v), lv, mid, l, r, x);
        if(rs != -1) return rs;
        return get_first(right(v), mid+1, rv, l ,r, x);
    }

    int get_first(int l, int r, ll x) {
        return get_first(0, 0, original.size() - 1, l, r - 1, x);
    }
};

ST *tree;

void init(vector<long long> a) {
	tree = new ST(a);
}

long long get_sum(int l, int r) {
	return tree->get_sum(l, r);
}

void add(int l, int r, long long x) {
    tree->add(l, r, x);
}

void set_range(int l, int r, long long x) {
	tree->set_range(l, r, x);
}

long long get_min(int l, int r) {
	return tree->get_min(l, r);
}

int lower_bound(int l, int r, long long x) {
	return tree->get_first(l, r, x);
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
