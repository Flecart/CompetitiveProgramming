#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pt {
    ll x;
    ll y;
    pt() : x(0), y(0) {}
    pt(ll x, ll y) : x(x), y(y) {}
};

ll dist_sq(const pt &a, const pt &b) {
    return (abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y));
}

ll operator ^(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
} 

ll operator *(const pt &a, const pt &b) {
    return a.x * b.x + a.y * b.y;
} 

pt operator +(const pt &a, const pt &b) {
    return pt(a.x + b.x, a.y + b.y);
}

pt operator -(const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
}

int main() {
    int n; cin >> n;
    ll a, b; n--;
    cin >> a >> b;
    pt first(a, b);
    pt last = first;

    ll result = 0;
    while (n--) {
        cin >> a >> b;
        pt curr(a, b);
        result += last ^ curr;
        last = curr;
    }
    result += last ^ first;
    cout << abs(result) << endl;
}