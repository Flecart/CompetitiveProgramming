#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int freq[26] = {0};

void print(char ch, int times) {
    for (int i = 0; i < times; i++) {
        cout << ch;
    }
}

void print_sol(int curr, int end_index = -1) {
    if (curr < 0) return;
    if (curr >= 26 && end_index != -1) print((char) (end_index + 'A'), freq[end_index]);
    if (freq[curr] & 1) print_sol(curr + 1, curr); // skip, bc it's the last character
    if (curr >= 26 || freq[curr] & 1) return;

    print((char) (curr + 'A'), freq[curr] / 2);
    print_sol(curr + 1, end_index);
    print((char) (curr + 'A'), freq[curr] / 2);
}

int main()
{
    string start;
    cin >> start;
    for (int i = 0; i < start.size(); i++) {
        freq[start[i] - 'A'] += 1;
    }
    int disp_count = 0;
    // check if its possible first;
    for (int i = 0; i < 26; i++) {
        if (freq[i] & 1) {
            disp_count += 1;
        } 
    }
    if ((disp_count > 0 && !(start.size() & 1)) || (disp_count != 1 && (start.size() & 1))) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    print_sol(0);

    return 0;
}