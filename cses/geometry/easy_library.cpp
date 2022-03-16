// this is the library for computational geometry
// i began after watching some lectures about it, it should
// be simpler to use than the other one
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

bool operator !=(const pt &a, const pt &b) {
    return a.x != b.x and a.y != b.y;
}

ostream& operator <<(ostream &out, const pt point) {
    return out << "[" << point.x << ", " << point.y << "]";
}

/*
// ordinamento per l'angolo
bool pt::operator <(const pt &other) const {
    if (this->y * other.y < 0) { // uno sopra l'altro sotto
        return (this->y > 0) || (this->y == 0 and this->x > 0);
    } else { // stessa parte
        return (*this ^ other) > 0; // vedere se other sta a sinistra di this
    }
}
*/

// ordinamento per prima coordinata
bool pt::operator <(const pt &other) const {
    if (this->x != other.x) return this->x < other.x;
    else return this->y < other.y;
}

ll get_sign(ll n) {
    if (n > 0) return 1;
    else if (n == 0) return 0;
    else return -1;
}

ll cross_product(const pt &first, const pt &middle, const pt &last) {
    return ((first - middle) ^ (last - middle));
}

// returns true if segments a-b, c-d are intersecting (doesn't count for edge cases)
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

ll double_area(vector<pt> &polygon) {
    ll result = 0;
    for (uint i = 0; i < polygon.size() - 1; i++) {
        result += polygon[i] ^ polygon[i + 1];
    }
    return abs(result + (polygon[polygon.size() - 1] ^ polygon[0]));
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