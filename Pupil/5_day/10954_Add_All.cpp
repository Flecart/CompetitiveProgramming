#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (!n)
        {
            break;
        }

        priority_queue<int, vector<int>, greater<int>> hello;


        while (n--)
        {
            int in;
            cin >> in;
            hello.push(in);
        }

        int ans = 0;

        while(hello.size() > 1)
        {
            // cout << hello.top() << '\n';

            int sum = hello.top();
            hello.pop();
            sum += hello.top();
            hello.pop();

            ans += sum;

            hello.push(sum);
        }

        cout << ans << "\n";
    }
    

    return 0;
}