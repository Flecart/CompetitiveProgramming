#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Fenwick {
private:
    vector<ll> vi;
    vector<ll> orig;
    int lsb(int n) {return ((-n) & n);}
    ll rsb(int n) {
        ll sum = 0;
        while(n > 0) {
            sum += vi[n]; 
            n -= lsb(n);
        }
        return sum;
    } 
public:
    Fenwick(vector<ll> vi) {
        this->orig = vi;
        this->vi = vector<ll>(vi.size() + 1, 0);
        for (int i = 1; i <= (int) vi.size(); i++) {
            update(i, vi[i - 1]);
        }
    }

    void update(int k, int n) {
        while (k <= (int) vi.size()) {
            vi[k] += n;
            k += lsb(k); 
        }
    }

    void set_update(int k, int n) {
        int diff = n - orig[k - 1];
        orig[k - 1] = n;
        update(k, diff);
    }

    ll query(int l, int r) {
        return rsb(r) - rsb(l - 1); 
    }

    void print() {
        for (auto x : vi) {
            printf("%lld ", x);
        }
        printf("\n");
    }
};

int main()
{
    int n , q;
    cin >> n >> q;
    vector<ll> vi = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
    }
    Fenwick dear = Fenwick(vi);

    while(q--) {
        ll choice, l, r; 
        cin >> choice >> l >> r;
        if (choice & 1) dear.set_update(l, r);
        else cout << dear.query(l, r) << '\n';
    }

    return 0;
}