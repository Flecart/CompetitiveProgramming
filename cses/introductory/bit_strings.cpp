#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int start;
    cin >> start;

    int mod = (int) 1e9 + 7;

    int begin = 1;
    while (start--) {
        begin = begin + begin;
        if (begin > mod) begin -= mod;
    }   
    cout << begin << endl;

    return 0;
}