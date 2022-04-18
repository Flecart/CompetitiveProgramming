#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// SUM OF FOUR VALUES:
// just an almost trivial extension of sum of 3 values

#define MAX 1003
pair<int ,int> arr[MAX]; 
int n, k, tmp;

bool can_sum_of_two(int start, int target) {
    int l = start, h = n - 1;
    while (l < h) {
        int sum = arr[l].first + arr[h].first;
        if (sum < target) l++;
        else if (sum > target) h--;
        else {
            cout << arr[l].second << " " << arr[h].second;
            return true;
        }
    }
    return false;
}

bool can_sum_of_three(int start, int target) {
    for (int i = start; i < n - 1; i++) {
        if (can_sum_of_two(i + 1, target - arr[i].first)) {
            cout << " " << arr[i].second;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        arr[i] = {tmp, i + 1};
    }; 
    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++) {
        if (can_sum_of_three(i + 1, k - arr[i].first)) {
            cout << " " << arr[i].second;
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
}