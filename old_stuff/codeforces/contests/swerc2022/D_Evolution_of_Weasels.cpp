#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void eliminate_indexes(string &s, vector<int> &to_elim, int n) { 
}

void handle_last_b(string &s) {
    int last_b = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            last_b = i; break; 
        }
    }

    if (last_b != -1) {
        s.erase(last_b, 1);
        s.push_back('B');
    }
}

// eliminate the bs
void handle_bs(string &s) {
    int idx = 0;
    int count = 0;
    vector<int> to_elim; 
    for (int i = 0; i < s.size(); i++) {
        if (count == 0 and s[i] == 'B') {
            idx = i;
            count++;
        } else if (count == 1 and s[i] == 'B') {
            to_elim.push_back(idx);
            to_elim.push_back(i);
            count = 0;
        }
    }
    // eliminate indexes
    for (int i = to_elim.size() - 1; i >= 0; i--) {
        s.erase(to_elim[i], 1);
    }
}

// eliminate repeated As and Cs
void handle_ac(string &s) {
    int j = 0; 
    while (j < (int) s.size() - 1) {
        if (s[j] == 'A' and s[j + 1] == 'A') {
            s.erase(j, 2);
            j--; 
        } else if (s[j] == 'C' and s[j + 1] == 'C') {
            s.erase(j, 2);
            j--;
        } else {
            j++;
        }
    } 

}

// IDEA IS TO "TRIM" BOTH STRING in a standard format. 
// if at the end the strings are equal, i found that there is a way to
// make it
void shrink(string &s) {
    handle_bs(s);
    handle_last_b(s);
    handle_ac(s);
}

void solve() {
    string a, b; 
    cin >> a >> b; 
    shrink(a);
    shrink(b);
    if (a.compare(b) == 0) cout << "YES\n";
    else cout << "NO\n";
    fflush(stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}