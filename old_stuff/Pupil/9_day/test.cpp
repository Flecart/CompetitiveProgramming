#include <iostream>

#define ll long long
#define UPPER ((ll)1e18 + 1)

ll mult(ll first, ll second)
{
    ll div = UPPER / second;
    std::cout << UPPER / second << " " << UPPER << std::endl;
    if (first > div)
    {
        return UPPER;
    }

    return first * second;
}


int main()
{
    //51e10
    ll first = 510000000000, second = 510000000000;
    
    std::cout << mult(first, second);
}