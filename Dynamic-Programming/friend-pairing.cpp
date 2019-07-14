#include<bits/stdc++.h>
using namespace std ;
int m = 1000000007;
int pairfrnd(int n)
{
    int * dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i < n+1; i++)
    {
        int x = dp[i-1] ;
        long r = (1l * (1l * (i-1)) * dp[i-2]) % m;
        int y = (1l * r) %m;
        dp[i] = (x + 0l + y  ) %m;
        cout<<" x = " << x<<" y = " << y <<" dp = " <<dp[i]<<endl;
    }

    return dp[n];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<pairfrnd(n)<<endl;
    }
}
