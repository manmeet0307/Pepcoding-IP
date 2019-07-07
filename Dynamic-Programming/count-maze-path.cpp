//isme size galat hai , [m][n] ki matrix banegi

#include<bits/stdc++.h>
using namespace std;
void mazepath(int m , int n)
{
    int ** dp = new int *[m+1];
    for(int i =0;i<m+1;i++)
    {
        dp[i] = new int[n+1];
        for(int j =0;j<n+1;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 0 ; i  < m+1;i++)
    {
        dp[i][n] = 1;
    }
    for(int i = 0 ; i < n+1;i++)
    {
        dp[m][i] = 1;
    }

    for(int i = m-1;i>=0;i--)
    {
        for(int j = n-1 ; j>=0 ; j--)
        {
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }
    }

    for(int i =0 ; i < m+1;i++)
    {
        for(int j = 0; j < n+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n ,m;
    cin>>m>>n;
    mazepath(m-1,n-1);
}
