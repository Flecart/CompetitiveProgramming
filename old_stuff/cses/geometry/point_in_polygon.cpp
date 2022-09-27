#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pt {
    ll x;
    ll y;
    pt() : x(0), y(0) {}
    pt(ll x, ll y) : x(x), y(y) {}
    bool operator <(const pt &other) const;
};

ll dist_sq(const pt &a, const pt &b) {
    return (abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y));
}

// products
ll operator ^(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
} 

ll operator *(const pt &a, const pt &b) {
    return a.x * b.x + a.y * b.y;
} 

// vector operations
pt operator +(const pt &a, const pt &b) {
    return pt(a.x + b.x, a.y + b.y);
}

pt operator -(const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
} 

pt operator *(const pt &a, ll n) {
    return pt(a.x * n, a.y * n);
}

pt operator /(const pt &a, ll n) {
    return pt(a.x / n, a.y / n);
}

ostream& operator <<(ostream &out, const pt point) {
    return out << "[" << point.x << ", " << point.y << "]";
}

// ordinamento per l'angolo
bool pt::operator <(const pt &other) const {
    if (this->y * other.y < 0) { // uno sopra l'altro sotto
        return (this->y > 0) || (this->y == 0 and this->x > 0);
    } else { // stessa parte
        return (*this ^ other) > 0; // vedere se other sta a sinistra di this
    }
}

ll get_sign(ll n) {
    if (n > 0) return 1;
    else if (n == 0) return 0;
    else return -1;
}

bool is_intersecting(const pt &a, const pt &b, const pt &c, const pt &d) {
    if (get_sign((a - c) ^ (b - c)) * get_sign((a - d) ^ (b - d)) < 0 
            and 
        get_sign((c - a) ^ (d - a)) * get_sign((c - b) ^ (d - b)) < 0)
    {
        return true;
    }
    else return false;
}

// Checks if 3rd parameter is inside segment 1st and 2nd parameter
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

/* POLIGON AREA:
The main idea is to count the intersections with a point at infinite.
Clearly if i intersect the polygon even times, then i'm entering, exiting, so the point is
outside, else, the point is inside because i'm still not out after i entered the poly 1 time.

It is fundamental that the point at infinite is actually outside the polygon (otherwise, 
it's not at infinite xD).
Then i check if its on one of its boundaries, if it is, i exit immediately after result
*/

const pt outside((ll) 1e9 + 7, (ll) 1e9 + 9);

void solve(vector<pt> &polygon) {
    int a, b;
    cin >> a >> b;
    pt point(a, b);
    int count = 0;
    for (uint i = 1; i <= polygon.size(); i++) {
        if (is_internal_collinear(polygon[i - 1], polygon[i % polygon.size()], point)) {
            cout << "BOUNDARY\n";
            return;
        } else if (is_intersecting(polygon[i - 1], polygon[i % polygon.size()], point, outside)) {
            count++;
        }
    }

    if (count & 1) cout << "INSIDE\n";
    else cout << "OUTSIDE\n";
}

int main() {
    int n,m; cin >> n >> m;
    vector<pt> vpt(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vpt[i] = pt(a, b);
    }

    while (m--) {
        solve(vpt);
    }
}