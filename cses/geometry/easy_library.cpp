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