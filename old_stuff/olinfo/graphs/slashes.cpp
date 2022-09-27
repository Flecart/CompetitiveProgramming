#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 4000001
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

// SLAHES
// https://training.olinfo.it/#/task/ois_slashes/
// La parte difficile di questo problema è la traduzione dell'input
// in un grafo. Dopo aver tradotto questo input in grafo, basta fare
// dfs per connected components e si trova la soluzione.

// input data
int N, M;

// Assumi che pos % 4 = 0 (ossia inizio di un quadrato);
// questo per tutti
inline int up(int pos) {
    // ritorno alla riga precedente, se sono andato troppo indietro
    return pos - M * 4 >= 0 ? pos - M * 4 + DOWN : -1;
}


inline int down(int pos) {
    return pos / 4 + M < N * M ? pos + M * 4 + UP: -1;
}

inline int left(int pos) {
    return (pos / 4) % M != 0 ? (pos - 4) + RIGHT : -1;
}

inline int right(int pos) {
    return (pos / 4) % M != M - 1 ? (pos + 4) + LEFT : -1;
}

struct block {

    // vedere se ci sono i collegamenti
    int links[3]; // 0 left , 1 outer, 2 right (da UP)

    bool visited; 

    // ogni cella divisa in 4blocchi 
    // 0 up, 1 right, 2 down, 3 left
    // pos è sempre l'inizio del blocco da 4
    block(){}
    block(int type, char ch, int pos) {
        visited = false;
        if (ch == '/') {
            switch (type) {
                case UP:
                    links[0] = pos + LEFT; 
                    links[1] = up(pos);
                    links[2] = -1; // RIGHT irragiungibile
                    break; 
                case RIGHT:
                    links[0] = -1; 
                    links[1] = right(pos);
                    links[2] = pos + DOWN;
                    break; 

                case DOWN:
                    links[0] = pos + RIGHT; 
                    links[1] = down(pos);
                    links[2] = -1;
                    break; 

                case LEFT:
                    links[0] = -1;
                    links[1] = left(pos);
                    links[2] = pos + UP;
                    break; 
            }
        } else { // la sbarra è '\'
            switch (type) {
                case UP:
                    links[0] = -1; 
                    links[1] = up(pos);
                    links[2] = pos + RIGHT;
                    break; 
                case RIGHT:
                    links[0] = pos + UP; 
                    links[1] = right(pos);
                    links[2] = -1;
                    break; 

                case DOWN:
                    links[0] = -1; 
                    links[1] = down(pos);
                    links[2] = pos + LEFT;
                    break; 

                case LEFT:
                    links[0] = pos + DOWN;
                    links[1] = left(pos);
                    links[2] = -1;
                    break; 
            }
        }
    }
};

ostream &operator<<(ostream &out, const block &b) {
    out << b.links[0] << " " << b.links[1] << ' ' <<  b.links[2];
    return out;
}

block table[MAX];
bool dfs(int v) {
    table[v].visited = true;

    for (int to : table[v].links) {
        if (table[to].visited or to == -1) continue;
        dfs(to);
    }
    return true;
}

int main() {
    cin >> N >> M;
    char ch; 
    for (int i = 0; i < N * M; i++) {
        cin >> ch; 
        for (int j = 0; j < 4; j++) {
            table[i * 4 + j] = block(j, ch, i * 4);
        }
    }

    // for (int i = 0; i < N * M * 4; i++) {
    //     cerr << i << ": " << table[i] << endl;
    // }
    ll ans = 0;
    for (int i = 0; i < N * M * 4; i++) {
        if (!table[i].visited and dfs(i)) ans++;
    }
    cout << ans << endl; // print the result
    return 0;
}
