#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = 0; 

    int l = 0;
    int h = n - 1;
    // Cerco di accopiare bambino piccolo col pesante.
    // se il più pesante attualmente non presente non ci sta 
    // con il bimbo più piccolo, allora sono sicuro che deve stare da solo
    // quindi gli do una gondola da solo
    while (l <= h) {
        if (arr[l] + arr[h] <= x && l != h) {
            l++;
        }
        h--;
        ans++;
    }
    cout << ans << endl;
    return 0;
}