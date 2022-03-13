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

ll get_sign(ll n) {
    if (n > 0) return 1;
    else if (n == 0) return 0;
    else return -1;
}

/*
NOTES ON THIS SOLUTION:
In the last solution present in this directory, i directly compute the intersection point
and went to see if this point lies between the segments or not, but with the drawback that
the floating point calculations are quite imprecise.

With this solution, given two line segments a-b and c-d, i come with the observation that
c d should lie in distinct semiplanes for a-b, the same should apply for a, b.
If i have this property, i'm sure the segments intersect (i don't need to consider the line
that passes throught cd or ab, so it's easier)
*/

bool is_internal_collinear(const pt &seg_start, const pt &seg_finish, const pt &to_check) {
    ll seg_length  = dist_sq(seg_start, seg_finish);
    if (((seg_start - to_check) ^ ( seg_finish - to_check)) == 0 // collinearity
            and
        dist_sq(seg_start, to_check) <= seg_length
            and 
        dist_sq(seg_finish, to_check) <= seg_length)
        {
            return true;
        }
    else return false;
}

void solve(const pt &a, const pt &b, const pt &c, const pt &d) {
    // c d lie in disting semiplanes for a-b
    // same for inverse
    if (
        get_sign((a - c) ^ (b - c)) * get_sign((a - d) ^ (b - d)) < 0 
            and 
        get_sign((c - a) ^ (d - a)) * get_sign((c - b) ^ (d - b)) < 0
        ) {
            cout << "YES\n";
        }
    else {
        // solve for collinearity
        if (is_internal_collinear(a, b, c)) cout << "YES\n";
        else if (is_internal_collinear(a, b, d)) cout << "YES\n";
        else if (is_internal_collinear(c, d, a)) cout << "YES\n";
        else if (is_internal_collinear(c, d, b)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    int n; cin >> n;
    while (n--) {
        int a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        solve(pt(a, b), pt(c, d), pt(e, f), pt (g, h));
    }
}