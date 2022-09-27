#include <iostream>
#include <vector>
#include <algorithm>
#include <stack> 
#include <string>
#include <cassert>
using namespace std;

// the solution uses a stack to track the opening and closing of the parentesis
long long complete(stack<char> s) {
    long long score = 0;
    while (!s.empty()) {
        int value = 0;
        if (s.top() == '(') value = 1;
        if (s.top() == '[') value = 2;
        if (s.top() == '{') value = 3;
        if (s.top() == '<') value = 4;
        if (value == 0) {
            cout << s.top() << "HERE" << endl;
        }
        assert(value != 0);
        score = score * 5 + value;
        s.pop();
    }
    return score;
}

void second_star() {
    vector<long long> scores;
    while (true) {
        stack<char> s;
        string hello;
        bool incomplete = true;
        cin >> hello; 
        if (hello.compare("-") == 0) break;
        for (int i = 0; i < hello.size(); i++) {
            if (hello[i] == '[' || hello[i] == '{' || hello[i] == '<' || hello[i] == '(') {
                s.push(hello[i]);
            } else if (s.empty() && (hello[i] == ']' || hello[i] == ')' || hello[i] == '>' || hello[i] == '}')) { 
                incomplete = false;
                break;
            } else if (hello[i] == ']' && s.top() == '[') {
                s.pop();
            } else if (hello[i] == ')' && s.top() == '(') {
                s.pop();
            } else if (hello[i] == '>' && s.top() == '<') {
                s.pop();
            } else if (hello[i] == '}' && s.top() == '{') {
                s.pop();
            } else {
                incomplete = false;
                break;
            }
        }
        if (incomplete) scores.push_back(complete(s));
    }
    sort(scores.begin(), scores.end());
    int middle = scores.size() / 2;
    printf("Size %ld\n", scores.size());
    cout << scores[middle] << endl;
    cout << scores[middle + 1] << endl;
}
void first_star() {
    stack<char> s;
    int ans = 0;
    while (true) {
        string hello;
        cin >> hello; 
        for (int i = 0; i < hello.size(); i++) {
            if (hello[i] == '[' || hello[i] == '{' || hello[i] == '<' || hello[i] == '(') {
                s.push(hello[i]);
            } else if (s.empty() && (hello[i] == ']' || hello[i] == ')' || hello[i] == '>' || hello[i] == '}')) { 
                if (hello[i] == '}') ans += 1197;
                else if (hello[i] == '>') ans += 25137;
                else if (hello[i] == ')') ans += 3;
                else if (hello[i] == ']') ans += 57;
                printf("Illegal %c  before found\n", hello[i]);
                break;
            } else if (hello[i] == ']' && s.top() == '[') {
                s.pop();
            } else if (hello[i] == ')' && s.top() == '(') {
                s.pop();
            } else if (hello[i] == '>' && s.top() == '<') {
                s.pop();
            } else if (hello[i] == '}' && s.top() == '{') {
                s.pop();
            } else {
                if (hello[i] == '}') ans += 1197;
                else if (hello[i] == '>') ans += 25137;
                else if (hello[i] == ')') ans += 3;
                else if (hello[i] == ']') ans += 57;
                printf("Illegal %c found\n", hello[i]);
                break;

            }
        }
        if (hello.compare("-") == 0) break;
    }
    cout << ans;
}

int main() {
    second_star();
}
