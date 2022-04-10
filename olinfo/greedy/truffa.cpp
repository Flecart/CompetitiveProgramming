#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
// https://training.olinfo.it/#/task/ois_truffa/

int sfangate(int N, int V[]) {
    sort(V, V + N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += V[i];
    }
    int ans = 0; 
    while (sum <= 0) {
        sum += -V[ans++] * 2;
    }
    return ans;
}


int V[MAXN];

int main() {
    // FILE *fr, *fw;
    // fr = fopen("input.txt", "r");
    // fw = fopen("output.txt", "w");
    FILE *fr = stdin;
    FILE *fw = stdout;
    int N, i;

    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}