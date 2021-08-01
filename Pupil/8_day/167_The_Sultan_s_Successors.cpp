#include <bits/stdc++.h>

using namespace std;
#define ll long long

int board[8][8];
int ans;

int rowInBoard[8];

bool place(int row, int col)
{
    for (int prev = 0; prev < col; prev++)
    {
        if (rowInBoard[prev] == row || (abs(rowInBoard[prev] - row) == abs(prev - col)))
            return false;
    }

    return true;
}

void search(int column, int sum)
{
    if (column == 8)
    {
        if (ans < sum)
            ans = sum;
        return;
    }

    for (int row = 0; row < 8; row++)
    {
        if (place(row, column))
        {
            rowInBoard[column] = row;
            sum += board[row][column];
            search(column + 1, sum);
            sum -= board[row][column];
        }
    }
    
    return;
}

int main()
{
    int chess;
    cin >> chess;

    while (chess--)
    {
        ans = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> board[i][j];
            }
        }
        
        search(0, 0); // search 8!

        cout << setw(5) << ans << '\n';
    }
       

    return 0;
}



// SOMETHING IS BUGGED IN THE VERSION DOWNTHERE
// I DON KNOW WHAT

// void search(vector<int> v, int sum)
// {
//     if (v.size() == 8)
//     {
//         if (ans < sum)
//             ans = sum;
//         return;
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         if (find(v.begin(), v.end(), i) == v.end()) // not in vector
//         {
//             bool isDiagonal = false;

//             for (int j = 0; j < v.size(); j++)
//             {
//                 if (abs((int) v.size() - j) == abs(v[j] - i))
//                 {
//                     isDiagonal = true;
//                     break;
//                 }
//             }
            
            
//             if (!isDiagonal)
//             {
//                 sum += board[i][v.size() - 1];

//                 v.push_back(i);
//                 search(v, sum);
//                 sum -= board[i][v.size() - 1];
//                 v.pop_back();
//             }
//         }
//     }
    
//     return;
// }

// int main()
// {
//     int chess;
//     cin >> chess;

//     while (chess--)
//     {
//         ans = 0;
//         for (int i = 0; i < 8; i++)
//         {
//             for (int j = 0; j < 8; j++)
//             {
//                 cin >> board[i][j];
//             }
//         }
        
//         search(vector<int>(), 0); // search 8!

//         cout << setw(5) << ans << '\n';
//     }
       

//     return 0;
// }