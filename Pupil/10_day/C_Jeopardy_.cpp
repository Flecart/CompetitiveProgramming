#include <iostream>
#include <algorithm>
typedef long long ll;

int main()
{
    int n, m;
    std::cin >> n >> m;

    int numbers[n], special[m], normal[n - m];
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> special[i];
    }

    std::sort(special, special + m);

    int specialIndex = 0;
    int normalIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (specialIndex < m && i + 1 == special[specialIndex])
        {
            special[specialIndex] = numbers[i];
            specialIndex += 1;
        }
        else
        {
            normal[normalIndex] = numbers[i];
            normalIndex += 1;
        }
    }
    
    

    std::sort(normal, normal + n - m);
    std::reverse(normal, normal + n - m);

    std::sort(special, special + m);
    std::reverse(special, special + m);


    ll ans = 0;
    for(int i = 0; i < n - m; ++i)
    {
        ans += normal[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        if (ans > special[i])
            ans *= 2;
        else
            ans += special[i];
    }
    
    std::cout << ans;
    
    return 0;
}