#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXN 10001 

vector<int> panini; 
vector<int> memo;

// LONGEST DECRESING SUBSEQUENCE
// O(n2) solution with dp

int fill_memo(int n) {
    if (memo[n] != -1) return memo[n];
    if (n == 0) {
        return memo[n] = 1;
    }
    int curr_max = 1;
    // trova in riferimento ai precedenti il massimo 
    for (int i = 0; i < n; i++) {
        if (panini[i] <= panini[n]) continue; 
        curr_max = max(curr_max, fill_memo(i) + 1);
    }
    return memo[n] = curr_max; 
}

// soluzione in O(n2); 
void solve(ifstream &fin, ofstream &fout) {
    int n; fin >> n; 
    for (int i = 0; i < n; ++i) {
        int a; fin >> a; 
        panini.push_back(a);
    }

    memo.assign(n, -1);
    int curr_max = 0; 
    for (int i = 0; i < n; i++) {
        int v = fill_memo(i);
        if (v > curr_max) curr_max = v;
    }
    fout << curr_max << endl; 
}

int main() {
    ifstream fin;
    ofstream fout; 
    ios::sync_with_stdio(false);
    fin.tie(0);
    fin.open("input.txt"); 
    fout.open("output.txt"); 
    solve(fin, fout);
    fin.close();
    fout.close();
}