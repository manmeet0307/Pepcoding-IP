#include<iostream>
 #include<vector>
 using namespace std;

 int maxProfit(vector<int> &prices,int fee) {
    int ** dp = new int*[2];
    int n = prices.size();
    for(int i=0;i<2;i++)
    {
        dp[i] = new int[n];
    }

    dp[0][0] = prices[0] * -1;
    dp[1][0] = 0;
    for(int i = 1 ; i < n ; i++)
    {
        dp[0][i] = max(dp[0][i-1] , dp[1][i-1] - prices[i]);
        dp[1][i] = max(dp[1][i-1] , dp[0][i-1] + prices[i] - fee);
    }

    return max(dp[0][n-1] , dp[1][n-1]);
 }

 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> prices(n);
     for (int i = 0; i < n; i++){
         cin>>prices[i];
     }
     int fee;
     cin>>fee;
     cout<<maxProfit(prices,fee);
 }
