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
    return a.x != b.x or a.y != b.y;
}

ostream& operator <<(ostream &out, const pt point) {
    return out << point.x << " " << point.y;
}

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

ll cross_product(const pt &first, const pt &middle, const pt &last) {
    return ((first - middle) ^ (last - middle));
}

/* CONVEX HULL
nota: ho invertito l'upper con il lower, ma funziona ugualmente lo stesso
Uses a technique similiar to graham scan (this is line sweep) for calculating convex hull of a set of points
in O(logn n). But builds upper and lower convex hull, and then joins them in the printing process.
For upper i make sure that the cross product has that sign, if not popping from the stack,
same thing that lower thing.

*/

void  solve(vector<pt> &points) {
    stack<pt> lower;
    stack<pt> upper;
    lower.push(points[0]); upper.push(points[0]);
    pt lower_keep = points[1], upper_keep = points[1];
    for (uint i = 2; i < points.size(); i++) {
        pt curr = points[i];

        // check if higher and lower are still convex:
        if (!lower.empty() and cross_product(lower.top(), lower_keep, curr) >= 0) { // at left
            lower.push(lower_keep);
            lower_keep = curr;
            // cerr << "Pushing point to lower: " << lower.top() << " curr keep: " << lower_keep << endl;
        } else {
            while (!lower.empty() and cross_product(lower.top(), lower_keep, curr) < 0) {
                lower_keep = lower.top();
                lower.pop();
            }
            lower.push(lower_keep);
            lower_keep = curr;
            // cerr << "Pushing point to lower: " << lower.top() << " curr keep: " << lower_keep << endl;
        }

        // same thing, but reversed
        if (!upper.empty() and cross_product(upper.top(), upper_keep, curr) <= 0) { // at right
            upper.push(upper_keep);
            upper_keep = curr;
            // cerr << "Pushing point to upper: " << upper.top() << " curr keep: " << upper_keep << endl;
        } else {
            while (!upper.empty() and cross_product(upper.top(), upper_keep, curr) > 0) {
                upper_keep = upper.top();
                upper.pop();
            }
            upper.push(upper_keep);
            upper_keep = curr;

            // cerr << "Pushing point to upper: " << upper.top() << " curr keep: " << upper_keep << endl;
        }
    }
    upper.push(points[points.size() - 1]);
    cout << upper.size() + lower.size() - 1 << '\n'; // -1 because first is counted twice
    while (!upper.empty()) {
        cout << upper.top() << '\n';
        upper.pop();
    }

    while (!lower.empty() and lower.top() != points[0]) {
        cout << lower.top() << '\n'; lower.pop();
    }
}

int main() {
    int n; cin >> n;
    vector<pt> points(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        points[i] = pt(a, b);
    }

    sort(points.begin(), points.end());

    solve(points);
}