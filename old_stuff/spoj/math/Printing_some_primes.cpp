#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX (int) 1e8 + 1

vector<bool> isPrime(MAX, true);
void heratostenes() {
    for (int i = 2; i * i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j >= 2 and j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    isPrime[0] = isPrime[1] = false;
    heratostenes();

    int counter = 0;
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            counter += 1;
            if (counter == 1) cout << i << endl;
        }

        if (counter >= 100) counter -= 100;
    }
}