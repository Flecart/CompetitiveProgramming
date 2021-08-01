#include <bits/stdc++.h>

using namespace std;
#define ll long long

int space, M, lastValue, dominos[2][14];

int memo[7][1 << 14];


bool dp(int toCompare, int used)
{
    if (bitset<15>(used).count() == space)
        return toCompare == lastValue;
    if (memo[toCompare][used] != -1)
        return memo[toCompare][used];

    bool found = false;

    for (int i = 0; !found && i < M; i++)
    {
        if ((used & 1 << i) == 0)
        {
            if (toCompare == dominos[0][i])
                found |= dp(dominos[1][i], used | 1 << i);
            if (toCompare == dominos[1][i])
                found |= dp(dominos[0][i], used | 1 << i);
        }
    }

    return memo[toCompare][used] = found;
    
}

int main()
{
    while (true)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 1 << 14; j++)
            {
                memo[i][j] = -1;
            }
            
        }
        
        cin >> space;
        if (space == 0)
            break;

        cin >> M;

        int firstValue, garbage;
        cin >> garbage >> firstValue;
        cin >> lastValue >> garbage;
        for (int i = 0; i < M; i++)
        {
            cin >> dominos[0][i];
            cin >> dominos[1][i];
        }

        dp(firstValue, 0) ? cout << "YES\n" : cout << "NO\n";
        
    }

    return 0;
}



// I DON KNOW WHY THIS DOESNT WOOOOORK
// pair<int, int> first, last;

// int start;
// pair<int, int> pairs[15];
// map<vector<int>, bool> memory;

// bool found = false;

// bool canSearch(vector<int> past, int curr)
// {
//     if (find(past.begin(), past.end(), curr) == past.end())
//     {
//         auto it = past.begin();

//         int toMatch = pairs[*it].first;
//         while (it != past.end())
//         {
//             if (toMatch == pairs[*it].first)
//                 toMatch = pairs[*it].second;
//             else
//                 toMatch = pairs[*it].first;
//             it++;
//         }
        

//         if (toMatch == pairs[curr].first || toMatch == pairs[curr].second)
//             return true;
        
//     }

//     return false;
// }

// void check(vector<int> past)
// {
//     auto it = past.begin();

//     int toMatch = pairs[*it].first;
//     while (it != past.end())
//     {
//         if (toMatch == pairs[*it].first)
//             toMatch = pairs[*it].second;
//         else
//             toMatch = pairs[*it].first;
//         it++;
//     }

//     if (toMatch == last.first)
//         found == true;
// }

// void search(int curr)
// {
//     for (auto i : memory)
//     {
//         if (!i.second && !found && canSearch(i.first, curr))
//         {
//             vector<int> copy(i.first);
//             copy.push_back(curr);

//             if (copy.size() + 1 == start)
//             {
//                 check(copy);
//                 memory.insert(make_pair(copy, true));
//             }
//             else
//                 memory.insert(make_pair(copy, false));
//         }
//     }
// }

// int main()
// {
//     while (true)
//     {
//         cin >> start;
//         if (start == 0)
//             break;

//         found = false;
        

//         int m;
//         cin >> m;
//         cin >> first.first >> first.second;
//         cin >> last.first >> last.second;

//         vector<int> tmp = {0};
//         memory.insert(make_pair(tmp, false));

//         pairs[0] = first;
//         for (int i = 1; i <= m; i++)
//         {
//             int a, b;
//             cin >> a >> b;
//             pairs[i] = make_pair(a, b);
//         }

//         sort(pairs, pairs + m);

//         for (int i = 0; i < m; i++)
//         {
//             search(i);
//         }
        
//         for (int i = 0; i < m; i++)
//         {
//             search(i);
//         }

//         if (found)
//         {
//             cout << "YES\n";
//         }
//         else
//             cout << "NO\n";
//         // for (int i = 0; i < 14; i++)
//         // {
//         //     cout << pairs[i].first << pairs[i].second << "\n";
//         // }
        
        
        
//     }
    
//     return 0;
// }