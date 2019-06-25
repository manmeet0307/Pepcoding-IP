#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int grain(int *arr,int n)
{
    pair<int,int> m ,sm;
    m.first = -1, sm.first = -1;
    for(int i = 0 ;i<n;i++)
    {
        if(arr[i] > m.first)
        {
           //cout<<m.first<<endl;
            m.first = arr[i];
            m.second = i;
        }
    }
    for(int i = 0 ; i < n;i++)
    {
        if(arr[i] == m.first && i != m.second)
        {
            sm.first = arr[i];
            sm.second = i;
        }
        else if(arr[i] > sm.first && i != m.second )
        {
            sm.first = arr[i];
            sm.second = i;
        }
    }
//cout<<m.first<<m.second<< " "<<sm.first<<sm.second<<endl;
    int s = min(m.second,sm.second) , e = max(m.second,sm.second);
    int h = sm.first,r = 0;
    for(int i = s+1 ; i < e ; i++ )
    {
        r += (h-arr[i]);
    }
    return r;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int a[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin>>a[i];
        }
    cout<<grain(a,n);
    return 0;
}
