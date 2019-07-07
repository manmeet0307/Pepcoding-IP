#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> v)
{
    for(int i =0;i< v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void print(int **dp,int i,int j,vector<int> v ,int m,int n,int a[][3])
{
    if(i>m || j>n)
    {
        return ;
    }

    if(i==m-1 && j==n-1)
    {
       v.push_back(a[i][j]);
        printvector(v);
        return ;
    }
    if(i==m-1)
    {
        v.push_back(a[i][j]);
        print(dp,i,j+1,v,m,n,a);
    }
    else if(j==n-1)
    {
         v.push_back(a[i][j]);
        print(dp,i+1,j,v,m,n,a);
    }
    else{
            v.push_back(a[i][j]);
        if(dp[i][j+1] < dp[i+1][j+1] && dp[i][j+1] < dp[i+1][j])
        {
            print(dp,i,j+1,v,m,n,a);
        }
        else if(dp[i+1][j] < dp[i+1][j+1] && dp[i+1][j] < dp[i][j+1])
        {
            print(dp,i+1,j,v,m,n,a);
        }
        else
        {
            print(dp,i+1,j+1,v,m,n,a);
        }
    }
}
void mincost(int a[][3] , int m ,int n)
{
    int **dp = new int*[m];
    for(int i=0;i<m;i++)
    {
        dp[i] = new int[n];
    }
    dp[m-1][n-1] = a[m-1][n-1];
    for(int i =n-2;i>=0;i--)
    {
        dp[m-1][i] = dp[m-1][i+1] + a[m-1][i];
    }
    for(int j = m-2;j>=0;j--)
    {
        dp[j][n-1] = dp[j+1][n-1] + a[j][n-1];
    }
    for(int i = m-2; i>=0;i--)
    {
        for(int j = n-2;j>=0;j--)
        {
            dp[i][j] = min(dp[i+1][j+1] , min(dp[i+1][j] , dp[i][j+1])) + a[i][j];
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> v;
    print(dp,0,0,v,m,n,a);
}
int main()
{
    int R = 3, C = 3;
    //int cost[3][3];
   int cost[][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };

    mincost(cost,3,3);
}
