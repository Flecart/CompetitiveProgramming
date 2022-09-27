#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define UPPER 7

double table[] = {12.53, 1.42, 4.68, 5.86, 13.58, 0.69, 1.01, 0.7, 6.25, 0.44, 0,
4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.9, 0.02, 0.22, 0.9, 0.52};

double averages[7][26];

string consonant = "bcdfghjklmnpqrstvwxyz";
string vocal = "aeiou";
string word;

double sum[UPPER][26];
int input, howMany[UPPER][26];


void _generate(int n, int startLetter, double currentSum)
{
    if (n == UPPER)
    {
        howMany[6][startLetter] += 1;
        sum[6][startLetter] += currentSum;
        return;
    }
    else
    {
        howMany[n - 1][startLetter] += 1;
        sum[n - 1][startLetter] += currentSum;
    }
    if (n & 1)
    {
        for (auto c : vocal)
        {
            _generate(n + 1, startLetter, currentSum + (n + 1) * table[c - 'a']);
        }
    }
    else
    {
        for (auto c : consonant)
        {
            _generate(n + 1, startLetter, currentSum + (n + 1) * table[c - 'a']);
        }
    }
}

inline void calculateAvg()
{
    for (int i = 0; i < UPPER; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            averages[i][j] = sum[i][j] / (howMany[i][j] * (i + 1));
        }
    }
}

void generate()
{
    for (auto c : consonant)
    {
        _generate(1, c - 'a', table[c - 'a']);
    }
}

inline double SBC()
{
    double  tmp = 0;
    for (int i = 0; i < word.length(); i++)
    {
        tmp += (i + 1) * table[word[i] - 'a'];
    }

    return tmp / word.length();
}

int main()
{
    cin >> input;
    for (int i = 0; i < UPPER; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            sum[i][j] = 0;
            howMany[i][j] = 0;
        }
    }
    
    generate();

    calculateAvg();

    for (int i = 0; i < input; i++)
    {
        cin >> word;

        double avg = SBC();

        if (avg < (averages[word.length() - 1][word[0] - 'a']))
            cout << "below\n";
        else
            cout << "above or equal\n";
    }
    
    return 0;
}