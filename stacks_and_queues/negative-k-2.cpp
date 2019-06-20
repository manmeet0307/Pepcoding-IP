#include<bits/stdc++.h>
using namespace std;
void printnegative(int * a, int n ,int k)
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            q.push(i);
        }
    }
    for(int i=0;i<n-k+1;i++)
    {
        if(q.empty())
        {
            cout<<"0 ";
        }
        else if(q.front()== i )
        {
            cout<<a[i]<<" ";
            q.pop();
        }
        else if(q.front()<i+k)
        {
            cout<<a[q.front()]<<" ";
        }
        else{
            cout<<"0 ";
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    printnegative(a,n,k);
}
