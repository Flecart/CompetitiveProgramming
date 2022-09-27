    #include <bits/stdc++.h>
     
    using namespace std;
    #define ll long long
     
    #define LIMIT 102
    

    // THis code doesnt work and i don kno why
    
    int n, m;
     
    inline int findRight(bitset<LIMIT> bits)
    {
        for(int i = 0; i < m + 2; i++)
        {
            if (bits[i])   
                return i;
        }
        return -1;
    }
     
    inline int findLeft(bitset<LIMIT> bits)
    {
        for (int i = m + 1; i >= 0; i--)
        {
            if (bits[i])
                return i;
        }
        return -1;
    }
     
    int main()
    {
        cin >> n >> m;
     
        vector<bitset<LIMIT>> building;
        vector<pair<int, int>> extremes;
        bitset<LIMIT> floor;
        while (n--)
        {
            cin >> floor;
            int left, right;
     
            left = findLeft(floor);
            right = findRight(floor);
            // cout << left << " " << right << endl;
            building.push_back(floor);  
            extremes.push_back(make_pair(left, right));  
        }
        
        reverse(building.begin(), building.end());
        reverse(extremes.begin(), extremes.end());
     
        int currRoom = m + 1;
        int ans = 0;
        auto it = extremes.begin();
        // for (auto i : extremes)
        // {
        //     cout << i.first << ' ' << i.second << endl;
        // }
        for (auto i : building)
        {
            // cout << it->first << ' ' << it->second << endl;
     
            if (currRoom == m + 1 && it->second != -1)
            {
                currRoom = it->second;
                ans += m + 1 - it->second;
            }
            else if (currRoom == 0 && it->first != - 1)
            {
                currRoom = it->first;
                ans += it-> first;
            }
     
            
            it++;
     
            if (it != extremes.end())
            {
                int manyEmpty = 0;
                while (it->first == -1)
                {
                    it++;
                    manyEmpty++;
                }
     
                if (it == extremes.end())
                {
                    cout << ans;
                    return 0;
                }
                
                int left, right;
                left = m + 1 - currRoom + 1 + m + 1 - it->first;
                right = currRoom + 1 + it->second;
     
                if (left > right)
                {
                    ans += currRoom + 1 + manyEmpty;
                    currRoom = 0;
                }
                else
                {
                    ans += m + 1 - currRoom + 1 + manyEmpty;
                    currRoom = m + 1;
                }
            }
            else
                break;
        }
     
        cout << ans;
        
     
     
     
        return 0;
    }