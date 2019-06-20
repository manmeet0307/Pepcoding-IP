#include<bits/stdc++.h>
using namespace std;
int robes(int*arr, int n)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    int r =0;
    while(pq.size()>=2)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x+y);
        r += (x+y);
    }
    return r;
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<robes(a,n);
}
