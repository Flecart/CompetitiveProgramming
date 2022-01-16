#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// this functions just prints in the wanted format
void print_set(set<int> s) {
    printf("%d\n", s.size());
    for (auto i:s) {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int start;
    cin >> start;
    ll allsum = ((ll) start * ( start + 1) / 2);

    // first check of possibility, i want it to be divisible by 4
    if (allsum & 1) {
        printf("NO\n");
        return 0;
    }

    ll target = allsum / 2;
    set<int> first;
    set<int> second;
    // don't know if this is the best algorithm, but i am assuming that there exists
    // a combination of this numbers so that i get a wanted sum.
    // so i just subtract if its bigger and adding to the set i am subtracting
    // else i insert it to another set
    for (int i = start; i >= 1; i--) {
        if (i <= target) {
            first.insert(i);
            target -= i;
        } else {
            second.insert(i);
        }
    }
    printf("YES\n");
    print_set(first);
    print_set(second);

    return 0;
}