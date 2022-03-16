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

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (true) {
        a = a % b; swap(a, b);
        if (b == 0) return a;
    }
}

// calculates number of lattice points between two points
ll line_lattice(pt a, pt b) {
    // https://math.stackexchange.com/questions/301890/how-many-points-between-two-points
    if (a.x == b.x) return abs(b.y - a.y) - 1;
    if (a.y == b.y) return abs(b.x - a.x) - 1;
    b = b - a; // translation
    return gcd(abs(b.x), abs(b.y)) - 1;
}

ll double_area(vector<pt> &polygon) {
    ll result = 0;
    for (uint i = 0; i < polygon.size() - 1; i++) {
        result += polygon[i] ^ polygon[i + 1];
    }
    return abs(result + (polygon[polygon.size() - 1] ^ polygon[0]));
}

/* POLYGON LATTICE POINTS
The main thing to note here is PICKS theorem that relates the area with points on boundaries
and inside it.

So after you know this teorem, i just found a way to calculate lattice points of a line
and then combine it with shoelace formula for the area, in this way i got the points inside
*/

int main() {
    int n; cin >> n;
    vector<pt> vpt(n);
    ll boundary_points = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vpt[i] = pt(a, b);
        if (i > 0) {
            boundary_points += line_lattice(vpt[i - 1], vpt[i]);
        }
    }
    boundary_points += line_lattice(vpt[n - 1], vpt[0]) + n;

    ll polygon_area = double_area(vpt);
    ll points_inside = polygon_area / 2 - boundary_points / 2 + 1;
    cout << points_inside << ' ' << boundary_points << endl;
}



