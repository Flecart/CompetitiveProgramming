#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, k;
int block_len;
struct block {
    ll sum;
    ll prefix_sum;
};

ostream &operator<<(ostream &out, const block &b) {
    out << b.sum << " " << b.prefix_sum << endl; 
    return out;
}

vector<block> b; 

void fill_blocks(int arr[]) {
    int b_index = -1; // -1 così conti tornano col primo
    ll sum = 0, prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % block_len == 0) {
            if (b_index >= 0) {
                // aggiorna le info del blocco corrispondente
                b[b_index].sum = sum;
                b[b_index].prefix_sum = prefix_sum;
            }
            b_index += 1;
            sum = prefix_sum = 0ll;
        }

        sum += arr[i];
        if (sum > prefix_sum) prefix_sum = sum;
    }
    if (b_index >= 0 and b_index < (n + block_len - 1) / block_len) {
        b[b_index].sum = sum;
        b[b_index].prefix_sum = prefix_sum;
    }
}

// update the value at position k to u
void update(int k, int u, int arr[]) {
    int b_index = k / block_len;
    arr[k] = u;
    // ricalcolo il blocco
    int start = b_index * block_len, finish = b_index * (block_len) + block_len;
    ll sum = 0, prefix_sum = 0;
    for (int i = start; i < n and i < finish; i++) {
        sum += arr[i];
        if (sum > prefix_sum) prefix_sum = sum;
    }
    b[b_index].sum = sum;
    b[b_index].prefix_sum = prefix_sum;
}

// what is the maximum prefix sum in range [a,b]?
ll answer(int l, int r, int arr[]) {
    ll sum = 0, prefix_sum = 0;
    int i = l;
    while (i <= r) {
        // check if in block
        if (i % block_len == 0 and (i + block_len) <= r) {
            int b_index = i / block_len;
            prefix_sum = max(prefix_sum, max(sum + b[b_index].sum, sum + b[b_index].prefix_sum));
            sum += b[b_index].sum; 
            i += block_len;
        } else {
            sum += arr[i];
            if (prefix_sum < sum) prefix_sum = sum;
            i += 1;
        }
    }
    return prefix_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    block_len = ceil(sqrt(n));
    b.resize((n + block_len - 1) / block_len); // ceiled division
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    fill_blocks(arr);
    for (int i = 0; i < k; i++) {
        int type, a, b; 
        cin >> type >> a >> b; 

        if (type == 1) {
            update(--a, b, arr);
        } else {
            cout << answer(--a, --b, arr) << '\n';
        }
    }
}