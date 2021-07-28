#include <bits/stdc++.h>

using namespace std;

int main()
{   
    while(true)
    {
        int start;
        cin >> start;

        if (start == 0)
        {
            break;
        }

        bitset<32> foo(start);
        // cout << foo << endl;
        bitset<32> a;
        bitset<32> b;

        bool isA = true;
        for (int i = 0; i < 32; i++)
        {   
            if (isA && foo[i])
            {
                a[i] = foo[i];
                isA = isA ^ 1;
            }
            else if (!isA && foo[i])
            {
                b[i] = foo[i];
                isA ^= 1;
            }
        }
        // cout << foo << '\n' << a << '\n' << b << '\n';
        cout << a.to_ulong() << ' ' << b.to_ulong() << '\n';
    }
    

    return 0;
}