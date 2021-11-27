#include <iostream>
using namespace std;
int main()
{
    int start;
    cin >> start; 
    while (start--) {
        int n, k;
        cin >> n >> k; 
        int meta = (k >> 1);
        n = meta ^ k;
        cout << n << endl;
    }

    return 0;
}