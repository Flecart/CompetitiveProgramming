#include <bits/stdc++.h>

using namespace std;

#define MAX (int)1e6
#define INF (int) 1e9 + 1

int leftCount[MAX] = {0}, rightCount[MAX] = {0};

struct Compressor
{
    map<int, int> m;
    set<int> s;

    void add(int x)
    {
        s.insert(x);
        
    }

    void fix()
    {
        for (auto i : s)
        {
            m[i] = m.size();
        }
    }

    int get(int x)
    {
        return m[x];
    }
};

void fillArray(int B[], int n, int A[], int base)
{
    for(int i = 0; i < n; ++i)
        B[i] = A[i + base];
    B[n] = INF;
}

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1, n2 = r - mid;
    int LeftCopy[n1 + 1], RightCopy[n2 + 1];

    fillArray(LeftCopy, n1, arr, l);
    fillArray(RightCopy, n2, arr, mid + 1);

    int t = 0;
    for(int w = l, i = 0, j = 0; w <= r; ++w)
        if(LeftCopy[i] < RightCopy[j])
        {
            leftCount[LeftCopy[i]] += t;
            arr[w] = LeftCopy[i++];
        }
        else
        {
            rightCount[RightCopy[j]] += n1 - i;
            arr[w] = RightCopy[j++];
            ++t;
        }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    return;
}

int main()
{
    int start;
    cin >> start;

    int arr[start];

    Compressor c;
    for (int i = 0; i < start; i++)
    {
        cin >> arr[i];
        c.add(arr[i]);
    }

    c.fix();
    for (int i = 0; i < start; i++)
    {
        arr[i] = c.get(arr[i]);
    }
    
    mergeSort(arr, 0, start - 1);
    long long ans = 0;

    for (int i = 0; i < start; ++i)
    {
        ans += (long long) leftCount[i] * rightCount[i];
    }

    cout << ans;
    
       

    return 0;
}