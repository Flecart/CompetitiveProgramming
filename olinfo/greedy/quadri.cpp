#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int* V;
static int B;

// Declaring functions
int quadri(int N, long long M, int* V);

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d %lld", &N, &M);
	V = (int*)malloc(N * sizeof(int));
	for (i0 = 0; i0 < N; i0++) {
	    fscanf(fr, "%d", &V[i0]);
	}

	// Calling functions
	B = quadri(N, M, V);

	// Writing output
	fprintf(fw, "%d\n", B);
	
	fclose(fr);
	fclose(fw);
	return 0;
}

// https://training.olinfo.it/#/task/abc_quadri
int quadri(int N, long long M, int V[]) {
    int start = 0, finish = 0;
    long long sum = 0; 
    // set starting sum 
    // trovo la più piccola finestra tale per cui la somma
    // è minore di quel valore 
    while (finish < N and sum <= M) {
        sum += V[finish++]; 
    }
    if (sum > M) {
        sum -= V[--finish];
    }

    // una volta trovata la finestra, continuo a scorrere
    // finché è buona, altrimenti la riduco.
    // al massimo finish = start con sum = 0; 
    while (finish < N) {
        sum -= V[start++];
        sum += V[finish++];
        if (sum > M) sum -= V[--finish];
    }

    return finish - start;
}
