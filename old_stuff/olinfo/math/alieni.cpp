#include <bits/stdc++.h>
using namespace std; 
bool mappa[20][20];
int log_value;
int gN; // global N
// https://training.olinfo.it/#/task/aliens/attachments
bool examine(int X, int Y);
void solution(int Xc, int Yc);

bool my_examine(int X, int Y) {
    // cerr << "looked at " << X << " " << Y << " : " << mappa[X][Y] << endl;
    if (X <= 0 or X > gN or Y <= 0 or Y > gN) return false; 
    else return examine(X, Y);
}

int get_first_white_x(int X, int Y, bool subtract = false) {
    int second = 0; // second perché resta indietro rispetto a first
    int first = subtract ? -1 : 1; 
    while (my_examine(X + first, Y)) {
        second = first; 
        first *= 2;
    }
    bool condition = subtract ? first < second - 1 : second < first - 1;
    while (condition) {
        int mid = (first + second) / 2; 
        if (my_examine(X + mid, Y)) {
            second = mid; 
        } else {
            first = mid; 
        }
        condition = subtract ? first < second - 1 : second < first - 1;
    }
    if (subtract) return second; 
    else return first; 

}

int get_first_white_y(int X, int Y, bool subtract = false) {
    int second = 0; // second perché resta indietro rispetto a first
    int first = subtract ? -1 : 1; 
    while (my_examine(X, Y + first)) {
        second = first; 
        first *= 2;
    }
    bool condition = subtract ? first < second - 1 : second < first - 1;
    while (condition) {
        int mid = (first + second) / 2; 
        if (my_examine(X, Y + mid)) {
            second = mid; 
        } else {
            first = mid;
        }
        condition = subtract ? first < second - 1 : second < first - 1;
    }
    if (subtract) return second;
    else return first; 
}

bool exam(int X, int Y){
    if(X>gN||X<1||Y>gN||Y<1)return 0;
    return examine(X,Y);
}
void find_centre(int N, int Xi, int Yi) {
    gN = N;
    int high_y = get_first_white_y(Xi, Yi, false);
    int low_y = get_first_white_y(Xi, Yi, true);

    int high_x = get_first_white_x(Xi, Yi, false);
    int low_x = get_first_white_x(Xi, Yi, true);

    // centri del quadrato corrente:
    int M = high_x - low_x;
    high_x--; high_y--;
    int x_center = Xi + (high_x + low_x) / 2;
    int y_center = Yi + (high_y + low_y) / 2;	
    // cerr << x_center << " " << y_center << " " << M << endl;;

    bool b_right = my_examine(x_center + M * 4, y_center);
    bool b_left = my_examine(x_center - M * 4, y_center);
    bool b_up = my_examine(x_center, y_center + M * 4);
    bool b_down = my_examine(x_center, y_center - M * 4);

    if (b_right or b_left or b_down or b_up) {
        if (b_down and b_left) solution(x_center - 2 * M, y_center - 2 * M);
        else if (b_down and b_right) solution(x_center + 2 * M, y_center - 2 * M);
        else if (b_up and b_right) solution(x_center + 2 * M, y_center + 2 * M);
        else if (b_up and b_left) solution(x_center - 2 * M, y_center + 2 * M);
        else if (b_down and !b_left and !b_right) solution(x_center, y_center - 2 * M);
        else if (b_up and !b_left and !b_right) solution(x_center, y_center + 2 * M);
        else if (b_left and !b_down and !b_up) solution(x_center - 2 * M, y_center);
        else if (b_right and !b_down and !b_up) solution(x_center + 2 * M, y_center);
    } else { // 3 x 3 inner square
        bool left = my_examine(x_center - 2 * M, y_center);
        bool right = my_examine(x_center + 2 * M, y_center); 
        bool up = my_examine(x_center, y_center + M * 2);
        bool down = my_examine(x_center, y_center - 2 * M);

        if (left and right and up and down) solution(x_center, y_center);
        else if (left and down) solution(x_center - M, y_center - M);
        else if (left and up) solution(x_center - M, y_center + M);
        else if (right and down) solution(x_center + M, y_center - M);
        else if (right and up) solution(x_center + M, y_center + M);
    }
}


bool examine(int X, int Y){
  return mappa[X][Y];
}

void solution(int Xc, int Yc){
  cout << Xc << " " << Yc << "\n";
}

int main(){
    const int size = 19;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            char c;
            cin >> c;
            mappa[j+1][size-i] = (c == 'x');
            // if(mappa[j+1][size-i])
            //    cout<<j+1<<" "<<size-i<<"\n";
        }
    }
    int a, b; cin >> a >> b;
    find_centre(size, a, b);
}
// bool examine(int X, int Y){return false;}
// void solution(int Xc, int Yc){}
// int main(){}