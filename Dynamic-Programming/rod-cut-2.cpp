#include<bits/stdc++.h>
using namespace std;
int rodcut(int x,int y,int z, int tot)
{
    int * dp = new int [tot+1];
    dp[0] = 0;
    for(int i=1;i<tot+1;i++)
    {
        if(i == x || i == y || i==z)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 0;
        }
        for(int x = 1; x< i;x++)
        {
            int other = i-x;
           if(dp[other] == 0 || dp[x] == 0)
            continue;
            dp[i] = max(dp[i] , dp[x] + dp[other]);
        }
    }
    return dp[tot];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int t;
        cin>>t;
        int x,y,z;
        cin>>x>>y>>z;
        cout<<rodcut(x,y,z,t)<<endl;
    }
}
