#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 1e9;

// gets minimum number of attacks to null two tiles nearby
// I don't know what i'm doing here, but i hope it works
/*
.____                       
|    |    _______  __ ____  
|    |   /  _ \  \/ // __ \ 
|    |__(  <_> )   /\  ___/ 
|_______ \____/ \_/  \___  >
        \/               \/ 
       PS: dont flame me for bad code here, i'm so confused */
int onager(int a, int b) {
    if (a > b) swap(a, b);
    int ans = min(b - a, (b + 1) / 2); 
    b -= ans * 2; 
    a -= ans;
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (a > b) swap(a, b);
    int elim_a = a / 3 * 2;
    ans += elim_a; 
    b -= elim_a / 2 * 3;
    a -= elim_a / 2 * 3;
    ans += (b / 2);
    a -= b / 2;
    if (a < 0) a = 0;
    b &= 1; 
    if (b > 0 and a == 0) ans += 1; 
    else ans += (a + 1) / 2;
    return ans; 
    
    int origa = a, origb = b; 
    int ans1, ans2;  
    // if (a > b / 2) {
        ans1 = a / 3 * 2; 
        b -= ans1 / 2 * 3;
        a -= ans1 / 2 * 3;
        ans1 += (b / 2);
        a -= b / 2;
        if (a < 0) a = 0;
        b &= 1; 
        if (b > 0 and a == 0) ans1 += 1; 
        else ans1 += (a + 1) / 2;
    // } else {
        a = origa;
        b = origb;
        ans2 = b / 2;
        b &= 1;
        a -= ans2; 
        if (a < 0) a = 0;
        if (b > 0 and a == 0) ans2 += 1; 
        else ans2 += (a + 1) / 2;
    // }
    return min(ans1, ans2);
}

int hacked_bruh(int a, int b) {
    if (a == b) return a;
    else return min(a,b) + (max(a, b) - min(a,b) + 1) / 2;
}

void solve() {
    // o li rompo da soli
    // oppure li rompo insieme
    // ho due modi per romepre assieme ()
    int n; cin >> n;
    vector<int> v(n), c(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i]; c[i] = v[i];
    }
    sort(c.begin(), c.end());
    int uniques = ((c[0] + 1) / 2 + (c[1] + 1) / 2);
    int divisus = inf; 
    int onag = inf; 
    for (int i = 0; i < n - 2; i++) {
        divisus = min(divisus, hacked_bruh(v[i], v[i + 2]));
        onag = min(onag, onager(v[i], v[i + 1]));
    }
    onag = min(onag, onager(v[n - 2], v[n - 1]));

    cout << min(min(onag, divisus), uniques) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}