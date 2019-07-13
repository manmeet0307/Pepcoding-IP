#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int largesq(int mat[][50] , int m ,int n)
{
    int ** dp = new int *[m];
    for(int i=0;i<m;i++)
    {
        dp[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            if(mat[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        dp[i][n-1]==0 ? dp[i][n-1] = 0 : dp[i][n-1] = 1;
    }
    for(int i=0;i<n;i++)
    {
        dp[m-1][i] == 0 ? dp[m-1][i] = 0 : dp[m-1][i] = 1;
    }
    for(int i = m-2;i>=0;i--)
    {
        for(int j= n-2;j>=0;j--)
        {
            if(dp[i][j] == 0)
                continue;
            dp[i][j] = min(dp[i+1][j] , min(dp[i][j+1] , dp[i+1][j+1])) + 1;
        }
    }

    int maxel = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           // cout<<dp[i][j]<<" ";
            maxel = max(maxel , dp[i][j]);
        }
        //cout<<endl;
    }
    return maxel;
}
int main() {
	int t;
	cin>>t;
	while(t--)
    {
        int m , n;
        cin>>m>>n;
        int mat[m][50];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
            }
        }
        cout<<largesq( mat , m ,n )<<endl;
    }
	return 0;
}
