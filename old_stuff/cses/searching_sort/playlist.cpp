#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pii> vii;

#define vc vector
#define pb push_back
#define F first
#define S second
#define nl cout<<'\n'
#define E cerr<<'\n'
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false)
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define cspace << ' ' <<
#ifndef FILE
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define prepare(x) int x; cin >>x;
#else 
#define seea(a,x,y) for(int i=x;i<y;i++){fin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; fin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; fin>>x; s.insert(x);}
#define prepare(x) int x; fin >> x;
#endif
//----------CONSTANTS----------
const int inf = INT_MAX;
const ll linf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

//TODO: prova a risolverlo in questo modo: (da trovare una struttura di dati che permetta di fare quelle operazioni);
/*
INPUT:
8
1 2 1 3 2 7 4 2

SPECIFICA DELLA STRUTTURA DI DATI:
inizializzo la struttura di dati che possiede
- Inserimento di un elemento in log n
- Ricerca dell'elemento in log n
- Eliminazione di un blocco di elementi in log n (quindi tipo elimina il nodo in testa)
chiamo sta struttura Baco.

PSEUDOCODICE:
Inizializzo un Baco, e ans
ciclo sull'array dei numeri in input.
per ogni elemento guardo se è presente in baco.
Se non è presente lo aggiungo e aggiorno l'ans con size se è maggiore
Se è presente elimino tutti gli elementi precedenti a questo elemento trovato
e aggiungo l'elemento corrente.

Alla fine del ciclo la risposta è presente in ans, lo ritorno.


*/
int main()
{
    IOS;
    prepare(n);
    pii arr[n];
    rep(i, 0, n) {
        prepare(x);
        arr[i] = {i, x};
    }

    int g_max = 1;
    set<pii> s;
    s.insert(arr[0]);

    rep(i, 1, n) {
        auto it = s.find(arr[i]); // This MUST BE before the insert of this round!
        auto ins_pos = s.insert(arr[i]).F; // garanteed i have a new element in the set bc index is unique.
        if (it == s.end()) {
            if (s.sz > g_max) g_max = s.sz;
        } else {
            // This should be constant with another data structure
            // with STL set should be linear.
            s.erase(s.begin(), ins_pos);
        }
    }

    cout << g_max; nl;

    return 0;
}