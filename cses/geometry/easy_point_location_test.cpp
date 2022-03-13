#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pt {
    ll x;
    ll y;
    pt() : x(0), y(0) {}
    pt(ll x, ll y) : x(x), y(y) {}
};

ll operator ^(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
} 

ll operator *(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
} 

pt operator +(pt a, pt b) {
    return pt(a.x + b.x, a.y + b.y);
}

pt operator -(pt a, pt b) {
    return pt(a.x - b.x, a.y - b.y);
}

/* NOTES ON THIS SOLUTION
There is a similiar file in the directory.
In that file i use rotations to know if the point lies on this or the other side
There is a easier (and faster) method that uses cross product, showed here.
*/

void solve(pt a, pt b, pt c) {
    ll cross = (a - c) ^ (b - c);
    if (cross == 0) cout << "TOUCH\n";
    else if (cross > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
}

int main() {
    int n; cin >> n;
    while (n--) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        solve(pt(a, b), pt(c, d), pt(e ,f));
    }

}