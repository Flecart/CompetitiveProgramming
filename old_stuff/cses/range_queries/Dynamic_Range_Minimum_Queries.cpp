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
        sum = first.sum + second.sum;
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
void lazy_update(int v) {
    if (nodes[v].x != inf) {
        if (nodes[v].is_set) {
            nodes[v].sum = nodes[v].x * (ranges[v].second - ranges[v].first + 1); 
            nodes[v].mmin = nodes[v].x;
            if (v < g_tree_size / 2) {
                nodes[left(v)] = nodes[v];
                nodes[right(v)] = nodes[v];
                nodes[left(v)].is_set = nodes[right(v)].is_set = true;
            }
            nodes[v].x = inf;
            nodes[v].is_set = false; 
        } else {
            nodes[v].sum += nodes[v].x * (ranges[v].second - ranges[v].first + 1); 
            nodes[v].mmin += nodes[v].x;
            if (v < g_tree_size / 2) {
                if (nodes[left(v)].x == inf) nodes[left(v)].x = 0;
                if (nodes[right(v)].x == inf) nodes[right(v)].x = 0;
                nodes[left(v)].x += nodes[v].x;
                nodes[right(v)].x += nodes[v].x;
                // se figli sono nodi di set, continua a settare a un valore aggiunto
                // altrimenti la flag resta false, quindi sommo
            }
            nodes[v].x = inf;
        }
    }
}

void add(int v, int tl, int tr, ll x) {
    if (tl > r or tr < l) return; 
    if (l <= tl and tr <= r) {
        nodes[v].mmin += x;
        nodes[v].sum += x * (tr - tl + 1);
        if (tl != tr) {
            if (nodes[left(v)].x == inf) nodes[left(v)].x = 0;
            if (nodes[right(v)].x == inf) nodes[right(v)].x = 0;
            nodes[left(v)].x += x;
            nodes[right(v)].x += x;
        }
        return;
    }
    lazy_update(left(v));
    lazy_update(right(v));
    int mid = (tl + tr) / 2;
    add(left(v), tl, mid, x);
    add(right(v), mid + 1, tr, x);
    nodes[v].merge(nodes[left(v)], nodes[right(v)]);
}

void set_range(int v, int tl, int tr, ll x) {
    if (tl > r or tr < l) return; 
    if (l <= tl and tr <= r) {
        nodes[v].mmin = x;
        nodes[v].sum = x * (tr - tl + 1);
        if (tl != tr) {
            nodes[left(v)].x = nodes[right(v)].x = x;
            nodes[left(v)].is_set = nodes[right(v)].is_set = true;
        }
        return;
    }

    lazy_update(left(v));
    lazy_update(right(v));
    set_range(left(v), tl, (tl + tr) / 2, x);
    set_range(right(v), (tl + tr) / 2 + 1, tr, x);
    nodes[v].merge(nodes[left(v)], nodes[right(v)]);
}

ll get_sum(int v, int tl, int tr) {
    if (tr < l or tl > r) return 0ll;
    if (l <= tl and tr <= r) {
        return nodes[v].sum;
    }
    lazy_update(left(v));
    lazy_update(right(v));
    return get_sum(left(v), tl, (tl + tr) / 2) + 
        get_sum(right(v), (tl + tr) / 2 + 1, tr);
}

ll get_min(int v, int tl, int tr) {
    if (tr < l or tl > r) return inf; 
    if (l <= tl and tr <= r) {
        return nodes[v].mmin;
    }
    lazy_update(left(v));
    lazy_update(right(v));
    return min(get_min(left(v), tl, (tl + tr) / 2),
            get_min(right(v), (tl + tr) / 2 + 1, tr));
}


int lower_bound(int v, int lv, int rv, ll x) {
    if(lv > r or rv < l) return -1;
    if(l <= lv and rv <= r) {
        if(nodes[v].mmin > x) return -1;
        while(lv != rv) {
            int mid = (lv + rv)/2;
            lazy_update(left(v));
            if(nodes[left(v)].mmin <= x) {
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

    lazy_update(left(v));
    lazy_update(right(v));
    int mid = (lv + rv)/2;
    int rs = lower_bound(left(v), lv, mid, x);
    if(rs != -1) return rs;
    return lower_bound(right(v), mid+1, rv, x);
}

ll get_sum(int a, int b) {
    l = a; r = b - 1;
    return get_sum(0, 0, g_size - 1);
}
void add(int a, int b, ll x) {
    l = a; r = b - 1;
    add(0, 0, g_size - 1, x);
}
void set_range(int a, int b, ll x) {
    l = a; r = b - 1;
    set_range(0, 0, g_size - 1, x);
}
ll get_min(int a, int b) {
    l = a; r = b - 1;
    return get_min(0, 0, g_size - 1);
}
int lower_bound(int a, int b, ll x) {
    l = a; r = b - 1;
    return lower_bound(0, 0, g_size - 1, x);
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
        cin >> op;
		cin >> l >> r;
        if (op == 2) cout << get_min(l - 1, r) << "\n";
        else set_range(l - 1, l, r);
	}
	
	return 0;
}
