#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

 int maxProfit(vector<int> &prices,int n) {
   int ** dp = new int * [2];
   dp[0] = new int[n];
   dp[1] = new int [n];
   int minsofar = prices[0];
   dp[0][0] = 0;
   for(int i = 1 ; i < n; i++)
   {
       minsofar = min(minsofar , prices[i]);
       dp[0][i] = max(dp[0][i-1] , prices[i] - minsofar );
   }
   int maxsofar = prices[n-1] ; dp[1][n-1] = 0 ;
   for(int i = n-2 ;i >=0 ;i--)
   {
       maxsofar = max(maxsofar , prices[i]);
       dp[1][i] = max(dp[1][i+1] , maxsofar - prices[i] );
   }

   int sum = 0;
   for(int i=0;i<n;i++)
   {
       sum  = max(sum , dp[0][i] + dp[1][i]);
   }
   return sum;
}

 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> prices(n);
     for (int i = 0; i < n; i++){
         cin>>prices[i];
     }
     cout<<maxProfit(prices,n);
 }
