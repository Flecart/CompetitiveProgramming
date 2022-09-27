// Problem https://codeforces.com/problemset/problem/1540/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Questo algoritmo gira O(nlogn)
// Il sorting è la parte che prende più tempo
int main()
{
    int cases;
    cin >> cases;
    while(cases--) 
    {
        int n;
        cin >> n;
        int sums[n];
        for (int i = 0; i < n; i++)
        {
            cin >> sums[i];
        }

        // Il sorting è fondamentale per avere una struttura ordinata in seguito
        sort(sums, sums + n);

        ll negative = 0;
        // Cerchiamo di definire il significato di ( (n - i) * i - 1). Vogliamo contare
        // Quante volte è utilizzato un piccolissimo passo sums[i] - sums[i - 1] (positivo per sort)
        // Allora questo passo è utilizzato dagli n - i numeri più grandi per arrivare a sums[i - 1]
        // Ma dobbiamo contare questo intervallo non solo per i numeri più grandi che errivano a sums[i - i]
        // Ma anche per raggiungere tutti gli vertici di ordine minore di i!
        // Per questo motivo dobbiamo moltiplicare.
        //
        // Cerchiamo di capire il motivo del -1:
        // Ricorda che in n - i, sto contanto anche i in questo caso (perché  i inizia a contare da 0)
        // Quindi nella moltiplicazione sto anche contando l'intervallo singolo sums[i] - sums[i - 1]
        // Che non dovrebbe essere contato perché si elide con un altra freccia positiva, per questo evito di contare questa parte
        // e la soluzinoe termina così
        for (int i = 1; i < n; i++)
        {
            negative -= ( (ll) (n - i) * i - 1) * (sums[i] - sums[i - 1]);
        }
        printf("%lld\n", negative);
    }

    return 0;
}