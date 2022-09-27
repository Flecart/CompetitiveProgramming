#include <iostream>
#include <vector>
using namespace std;

// In this solution i just bruteforce the right position
// Later i noticed that i could just sort the array
// and the use the median of the array to compute it
// (at least in the first case) 
// But the bruteforce was easy to implement! so nice!
vector<int> get_input() {
    vector<int> ans(0);
    int inp;
    cin >> inp;
    char virgola;
    while (inp != -1) {
        ans.push_back(inp);
        cin >> virgola;
        cin >> inp;
    }
    return ans;
}

// first_star
int get_fuel(vector<int> inp, int n) {
    int sum = 0; 
    for (int i = 0; i < inp.size(); i++) {
        sum += abs(inp[i] - n);
    }
    return sum;
}

// second_star
long long get_fuel_hard(vector<int> inp, int n) {
    long long sum = 0;
    for (int i = 0; i < inp.size(); i++) {
        int tmp = abs(inp[i] - n);
        sum += tmp * (tmp + 1) / 2;
    }
    return sum;
}

int main() {
    vector<int> inp = get_input(); 
    long long ans = 1e15;
    for (int i = 0; i < 2000; i++) {
        ans = min(get_fuel_hard(inp, i), ans);
    }
    cout << ans << endl;
}
