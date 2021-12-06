#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
#define CICLE 7
#define DAYS 256


// FIRST STAR REGION
void pass_day(vector<int> *fishes) {
    int to_push = 0;
    for (auto &fish : (*fishes)) {
        fish -= 1;
        if (fish == -1) {
            fish = CICLE - 1;
            to_push += 1;
        }
    }
    for (int i = 0; i < to_push; i++) {
        (*fishes).push_back(CICLE + 1);
    }
}

vector<int> get_input() {
    vector<int> fishes(0);
    int inp;
    cin >> inp;
    while (inp != -1) {
        fishes.push_back(inp);
        char virgola;
        cin >> virgola;
        cin >> inp;
    }
    return fishes;
}


void first_star() {
    vector<int> fishes = get_input();
    for (int i = 0; i < DAYS; i++) {
        pass_day(&fishes);
    }
    cout << fishes.size() << endl;
}

// SECOND STAR
void cicle(ll fishes[]) {
    ll new_born = fishes[0];
    for (int i = 0; i < CICLE + 1; i++) {
        fishes[i] = fishes[i + 1];
    }
    fishes[CICLE + 1] = new_born;
    fishes[CICLE - 1] += new_born;
}

void get_input(ll fishes[]) {
    int inp;
    cin >> inp;
    while (inp != -1) {
        fishes[inp] += 1;
        char virgola;
        cin >> virgola;
        cin >> inp;
    }
}

void second_star() {
    ll fishes[CICLE + 2] = {0};
    get_input(fishes);
    for (int i = 0; i < DAYS; i++) {
        cicle(fishes);
    }
    ll sum = 0; 
    for (int i = 0; i < CICLE + 2; i++) {
        sum += fishes[i];
    }
    cout << sum << endl;
}

int main() {
    second_star();
}