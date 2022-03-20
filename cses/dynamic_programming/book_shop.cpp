#include <bits/stdc++.h>

using namespace std;

/* BOOK SHOP:
i use an array to store the best solutions of the step before.
This is standard knapsack 1/0.
i update this array as needed (if the solution is better i keep this sol
else i keep the older one).
*/

int main()
{
    int n, x; cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    int memo[2][x];

    for (int i = 0; i < x; i++) memo[0][i] = 0;
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            // fill the table in a dynamic way.
            int last_price = j - price[i]; 
            int &update_cell = memo[(i + 1) % 2][j];
            if (last_price < 0) {
                last_price = 0;
                update_cell = memo[i % 2][j];
            } else {
                update_cell = max(memo[i % 2][j], pages[i] + memo[i % 2][last_price]);
            }
            if (update_cell > max_value) max_value = update_cell;
        }
    }     
    cout << max_value << endl;
    return 0;
}