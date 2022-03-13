#include <bits/stdc++.h> 

using namespace std;

#define EPS 1e-9

struct point {
    double x;
    double y;
};

struct vec {
    point p;

    vec(point a, point b) {
        p.x = b.x - a.x;
        p.y = b.y - a.y;
    }

    vec(point p): p(p) {}

    void translate(point a) {
        p.x += a.x;
        p.y += a.y;
    }

    point get_translated_point(point a) {
        return {a.x + p.x, a.y + p.y};
    }

    double dot(const vec &other) const {
        return p.x * other.p.x + p.y * other.p.y;
    }

    double norm_sq() const {
        return p.x * p.x + p.y * p.y;
    }

    void scale(double factor) {
        p.x *= factor;
        p.y *= factor;
    }

    double angle_between(vec &other) const {
        // ab = |a||b|cos theta
        double angle = acos(this->dot(other) / sqrt(this->norm_sq() * other.norm_sq()));
        return this->is_upper_quadrant() ? angle : -angle;
    }

    void rotate(double radian) {
        double x = cos(radian) * p.x - sin(radian) * p.y;
        double y = sin(radian) * p.x + cos(radian) * p.y;
        p.x = x;
        p.y = y;
    }

    void print() const {
        cout << "[" << p.x << ", " << p.y << "]\n";
    }

    bool is_upper_quadrant() const {
        return p.y > -EPS;
    }
};


/* POINT LOCATION TEST:
the main idea is to rotate the test point and see if its higher or lower than orizontal axis
*/
void solve(point a, point b, point c) {
    vec ab(a, b);
    vec ac(a, c);
    vec unit_v({1, 0});
    double offset = -ab.angle_between(unit_v);
    ac.rotate(offset);
    if (fabs(ac.p.y) < EPS) cout << "TOUCH\n";
    else if (ac.p.y > 0) cout << "LEFT" << '\n';
    else cout << "RIGHT\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while (n--) {
        double a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        solve({a, b}, {c, d}, {e, f});
    }
}