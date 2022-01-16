#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int start;
    cin >> start;
    int div = 5;
    int ans = 0;
    while (div <= start) {
        ans += start / div;
        div *= 5;
    }
    cout << ans;

    return 0;
}