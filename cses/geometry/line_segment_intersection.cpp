#include <bits/stdc++.h> 

using namespace std;

#define EPS 1e-9

struct point {
    double x;
    double y;

    point(double x, double y): x(x), y(y) {}
    point(): x(0.0), y(0.0) {}

    void print() const {
        cerr << "[" << x << ", " << y << "]\n";
    }

    bool operator <(const point &other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        else return y < other.y;
    }

    bool operator <=(const point &other) const {
        return *this == other || *this < other;
    }

    bool operator >=(const point &other) const {
        return *this == other || *this > other;
    }

    bool operator >(const point &other) const {
        if (fabs(x - other.x) > EPS) return x > other.x;
        else return y > other.y;
    }

    bool operator ==(const point &other) const {
        return (fabs(x - other.x) < EPS and fabs(y - other.y) < EPS);
    }
};

struct line {
    // format ax + by + c = 0
    double a;
    double b;
    double c;

    line(point p1, point p2) {
        if (fabs(p1.x - p2.x) < EPS) {
            a = 1;
            b = 0;
            c = -p1.x;
        } else {
            a = -(p2.y - p1.y) / (p2.x - p1.x);
            b = 1; // questo dà una sorta di normalizzazione
            c = -(a * p1.x) - p1.y;
        }
    }

    line(double a, double b, double c): a(a), b(b), c(c) {}

    bool is_parallel_to(line &other) const {
        // this is normalized to b = 1, so don't need to scale
        return (fabs(a - other.a) < EPS) and (fabs(b - other.b) < EPS);
    }

    bool is_same_to(line &other) const {
        return this->is_parallel_to(other) and (fabs(c - other.c) < EPS);
    }

    void print() const {
        cerr << a << "x + " << b << "y + "  << c <<  " = 0\n";
    }

    point intersect_to(line other) const {
        if (this->is_parallel_to(other)) return point(0,0); // default ret
        // risolvere il sistema:
        // ax + yx + c = 0;
        // a2x + y2x + c2 = 0; fatto con gauss, O(1) formula stretta.

        line this_copy(a, b, c);
        if (fabs(this_copy.a) < EPS) swap(this_copy, other); // assume at least one is not null, else, they are parallel
        double y = (-other.c + (this_copy.c * other.a) / this_copy.a) / (other.b - (this_copy.b * other.a) / this_copy.a);
        double x = (-this_copy.c - this_copy.b * y) / this_copy.a;

        return point(x, y);
    }

    bool has_point(point p) const {
        // cerr << "value : " << fabs(a * p.x + b * p.y + c) << "\n";
        return fabs(a * p.x + b * p.y + c) < EPS * 1.5e7; // alto valore di imprecisione
    }

    bool has_point_on_segment(point p, point lower, point higher) const {
        // cerr << "has_point: " << this->has_point(p) << " p >= lower: " << (p >= lower) << " higher >= p " << (higher >= p) << '\n';
        if (this->has_point(p) and p >= lower and higher >= p) return true;
        else return false;
    }
};
/* LINE SEGMENT INTERSECTION
    // first i make sure they are not parallel and not same
    // so i'm sure there is a solution for the intersection.
    // 1. if they are parallel and not same, i'm sure no solution
    // 2. if they are the same line, i have to make sure there is a intersection
    // 3. i intersect and see if this point lies between both segments
*/

void solve(point a, point b, point c, point d) {
    line first(a, b);
    line second(c, d);

    if (first.is_parallel_to(second) and !(first.is_same_to(second))) cout << "NO\n";
    else {
        if (first.is_same_to(second)) {
            if (first.has_point_on_segment(c, min(a, b), max(a, b)) 
                || 
                first.has_point_on_segment(d, min(a, b), max(a, b)) ) {
                    cout << "YES\n";
            }
            else if (second.has_point_on_segment(a, min(c, d), max(c, d)) 
                    || 
                    second.has_point_on_segment(b, min(c, d), max(c, d)) ) {
                    cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            point intersection = first.intersect_to(second);
            /*
            intersection.print();
            first.print();
            second.print();
            cerr << first.has_point_on_segment(intersection, min(a, b), max(a, b)) << endl;
            cerr << second.has_point_on_segment(intersection, min(c, d), max(c, d)) << endl;
            */
            if (first.has_point_on_segment(intersection, min(a, b), max(a, b))
                and 
                second.has_point_on_segment(intersection, min(c, d), max(c, d)))
                cout << "YES\n";
            else 
                cout << "NO\n";
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while (n--) {
        double a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        solve(point(a,b), point(c, d), point(e, f), point(g, h));
    }
}
