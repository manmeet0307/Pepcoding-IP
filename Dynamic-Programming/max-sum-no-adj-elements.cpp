#include<bits/stdc++.h>
using namespace std;
int maxloot(int *  arr ,  int n)
{
    int ** dp = new int* [2];
    for(int i=0;i<2;i++)
    {
        dp[i] = new int[n];
    }
    dp[0][0] = arr[0];
    dp[1][0] = 0;
    for(int i = 1;i<n;i++)
    {
        dp[0][i] = dp[1][i-1] + arr[i];
        dp[1][i] = dp[0][i-1];
    }
    return max(dp[0][n-1] , dp[1][n-1]);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<maxloot(a,n)<<endl;
    }
}
