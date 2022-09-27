

#include <bits/stdc++.h>
using namespace std; 
vector<int> memo; 

int memoize(int n, int a[], int b[]) {
    if (memo[n] != -1) return memo[n];
    if (n == 0) return memo[n] = (max(a[0], b[0]));
    else if (n == 1) return memo[n] = max(memoize(0, a, b) + a[1], b[1]); 
    else return memo[n] = max(memoize(n - 1, a, b) + a[n], memoize(n - 2, a, b) + b[n]);
}

int tempo_massimo(int N, int a[], int b[])
{
    memo.assign(N, -1); 
    memoize(N - 1, a, b); 
    return memo[N - 1];
}
