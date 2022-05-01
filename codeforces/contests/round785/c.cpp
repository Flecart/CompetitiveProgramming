#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 4 * (int)1e4 + 2
const int mod = (int) 1e9 + 7;
ll dp[MAX];
set<int> is_palindrome; 

// https://stackoverflow.com/questions/15355080/the-most-efficient-way-to-reverse-a-number
int rev(int in) {
    int out = 0;
    while(in)
    {
        out *= 10;
        out += in % 10;
        in /= 10;
    }
    return out;
}

void fill_palindrome() {
    for (int i = 1; i < MAX; i++) {
        if (i == rev(i)) is_palindrome.insert(i);
    }
}

ll bin_exp(ll b, ll p){
if(p == 0) return 1;
if(p == 1) return b;
ll ans = 1;
if(p % 2 == 1){
ans = (ans * b) % mod;
p--;
}
ll x = bin_exp(b, p/2);
return ans * x * x % mod;
}

void fill_dp() {
    dp[0] = 1;
    for (auto pal : is_palindrome) {
        for (int i = 1; i < MAX; i++) {
            if (i - pal >= 0) {
                dp[i] += dp[i - pal];
                dp[i] %= mod; 
            }; 
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;

    fill_palindrome();
    fill_dp();
    // for (auto i : is_palindrome) {
    //     cerr << dp[i] << " " << i << endl; 
    //     if (i > 100) break; 
    // }
    while(n--) solve();
}