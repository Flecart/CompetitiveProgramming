// Just a collection of stuff useful for geometrical computation

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
        cerr << "[" << p.x << ", " << p.y << "]\n";
    }

    bool is_upper_quadrant() const {
        return p.y > -EPS;
    }
};
