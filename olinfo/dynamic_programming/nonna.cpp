#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h> 
#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000
using namespace std; 

// caso peggiore O(n * k) ossia sto guardando le k somme n  volte
unordered_set<int> possible_sums; 
int mangia(int N, int K, int P[]) {
    possible_sums.insert(0); 
    int solution = INT_MAX; 
    for (int i = 0; i < N; i++) {
        for (int el : possible_sums) {
            int curr = el + P[i]; 
            if (curr >= K and solution > curr) solution = curr; 
            else if (curr < K) possible_sums.insert(curr); 
        }
    }
    return solution;
}


int P[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));

    fprintf(fw, "%d\n", mangia(N, K, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
