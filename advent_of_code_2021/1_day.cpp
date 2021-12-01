#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// for this problem i just need to keep track of the last element
// and continue to read until the problem has ended. (with the value 2682)
int first_star();

// keep the sum of the sliding window and update when reading
int second_star();

int second_star() {
    queue<int> q;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        q.push(tmp);
    }
    int ans = 0;
    while (q.back() != 2682) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
        int curr_sum = sum - q.front() + q.back();
        q.pop();
        if (curr_sum > sum) ans += 1;
        sum = curr_sum;
    }
    cout << ans << endl;
}

int first_star() {
    int n;
    int last_el;
    cin >> n;
    last_el = n;
    int ans = 0;
    while(n != 2682) {
        cin >> n;
        if (n > last_el) ans += 1;
        last_el = n;
    };
    cout << ans;
    return 0;
}
