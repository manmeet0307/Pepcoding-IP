#include<bits/stdc++.h>
using namespace std;
void printnegative(int * a, int n ,int k)
{
    int i = 0, j = 0;
    int ans[n-k+1];
    while(i<=n-k)
    {
        if(a[j]>=0)
        {
            j++;
            continue;
        }
        if( j<i+k)
        {
            ans[i] = a[j];
            i++;
            if(i>j)
            {
                j++;
            }
        }
        else
        {
            ans[i] = 0;
            i++;
        }
    }
    for(int i=0;i<n-k+1;i++)
    {
        cout<<ans[i]<<" ";
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
