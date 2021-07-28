#include <bits/stdc++.h>

using namespace std;


int dayStartTime = 5 * 60;
int dayEndTime = 24 * 60 - dayStartTime;

struct time
{
    int hour;
    int minutes;
} startTime;


int main()
{
    int a_deptarture, a_taken, b_departure, b_taken;
    cin >> a_deptarture >> a_taken >> b_departure >> b_taken;

    scanf("%d:%d", &startTime.hour, &startTime.minutes);

    int start = startTime.hour * 60 + startTime.minutes - dayStartTime;
    int finish = min(start + a_taken, dayEndTime);
    
    // remember its a flor, not division... this is what makes it work
    int firstBus = (start - b_taken) / b_departure * b_departure;
    while(firstBus + b_taken <= start)
        firstBus += b_departure;
    if(firstBus < 0)
        firstBus = 0;

    // cout << start << ' ' << finish << ' ' << firstBus << "\n";
    int ans = ceil((finish - firstBus) / (float) b_departure);
    if (ans < 0)
        ans -= ans;
    cout << ans;
    return 0;
}