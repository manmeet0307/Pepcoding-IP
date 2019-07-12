#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices,int n,int k) {
    int ** dp = new int *[k+1];
    for(int i=0;i<k+1;i++)
    {
        dp[i] = new int[n];
        for(int j = 0; j < n;j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i = 1 ; i < k+1 ; i++)
    {
        for(int j = 1; j < n; j++)
        {
            int op1 = dp[i][j-1];
            int op2 = 0;
            for(int x = 0; x< j;x++)
            {
                op2 = max(op2 , dp[i-1][x] + (prices[j] - prices[x]));
            }
            dp[i][j] = max(op1,op2);
        }
    }

    int maxatk = 0;
    for(int i = 0 ; i < n ; i++)
    {
        maxatk = max( maxatk , dp[k][i]);
    }
    return maxatk;
 }

 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> prices(n);
     for (int i = 0; i < n; i++){
         cin>>prices[i];
     }
     int k;
     cin>>k;
     cout<<maxProfit(prices,n,k);
 }
