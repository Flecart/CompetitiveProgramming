#include <bits/stdc++.h>
using namespace std;
// https://training.olinfo.it/#/task/ois_tournament/statement
// sol: https://www.geeksforgeeks.org/maximum-manhattan-distance-between-a-distinct-pair-from-n-coordinates/
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    int N, tmp, min_diff, max_diff, min_sum, max_sum;
    cin >> N;
    cin >> tmp; 
    
    min_diff = min_sum = max_diff = max_sum = tmp;
	for(int i = 1; i < N; i++) {
        cin >> tmp; 
        if (tmp - i < min_diff) min_diff = tmp - i;
        else if (tmp - i > max_diff) max_diff = tmp - i; 
        if (tmp + i < min_sum) min_sum = tmp + i;
        else if (tmp + i > max_sum) max_sum = tmp + i;
	}
    if (max_diff - min_diff > max_sum - min_sum) cout << max_diff - min_diff << '\n';
    else cout << max_sum - min_sum; 

	return 0;
}
