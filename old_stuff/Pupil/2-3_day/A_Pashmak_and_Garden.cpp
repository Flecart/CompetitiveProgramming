#include <bits/stdc++.h>

using namespace std;

int main()
{
    short x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
    {
        int len = abs(y2 - y1);
        int xValue;
        if (len + x1 < 1000)
        {
            xValue = len + x1;
        }
        else
            xValue = len - x1;
        cout << xValue << " " << y1 << " ";
        cout << xValue << " " << y2 << " ";
    }
    else if (y1 == y2)
    {
        int len = abs(x2 - x1);
        int yValue;
        if (len + y1 < 1000)
        {
            yValue = len + y1;
        }
        else
            yValue = len - y1;
        cout << x1 << " " << yValue << " " ;
        cout << x2 << " " << yValue << " " ;
    }
    else if (x1 == y1 && x2 == y2)
    {
        cout << x1 << " " << y2 << " ";
        cout << x2 << " " << y1 << " ";
    }
    else
    {   
        if ((x1 == y1 && x2 == y2) || (x1 == -y1 && x2 == -y2))
        {
            cout << x1 << " " << y2 << " ";
            cout << x2 << " " << y1 << " ";
        }
        else
        {
            int yTranslation = 0 - y1;
            int otherTranslated = y2 + yTranslation;

            int xTranslation = 0 - x1;
            int whafuc = x2 + xTranslation;

            if ((whafuc == otherTranslated) || (whafuc == -otherTranslated))
            {
                cout << x1 << " " << y2 << " ";
                cout << x2 << " " << y1 << " ";
            }
            else
                cout << - 1;
        }
    }

    return 0;
}