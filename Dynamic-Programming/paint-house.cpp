#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int minCost(vector<vector<int>>& costs) {
        int houses = costs.size();
        int n = costs.size();
        int **dp = new int *[3];
        for(int i=0;i<3;i++)
        {
            dp[i] = new int[houses];
        }

        for(int i = 0 ; i < 3 ;i ++)
        {
            dp[i][0] = costs[0][i];
        }
        int c = 0;
        for(int j = 1; j < n; j++)
        {
            dp[0][j] = min(dp[1][j-1] , dp[2][j-1]) + costs[j][0];
            dp[1][j] = min(dp[0][j-1] , dp[2][j-1]) + costs[j][1];
            dp[2][j] = min(dp[0][j-1] , dp[1][j-1]) + costs[j][2];
            c = (c+1) % 3;
        }
        /*
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j  <3;j++)
        }*/
        return min(dp[0][n-1] , min(dp[1][n-1],dp[2][n-1]));
}

int main(int argc,char** argv) {
      int n ;
      cin>>n;
      vector<vector<int>> costs(n,vector<int>(3));
      for(int i=0;i<n;i++){
          for(int j=0;j<3;j++){
              cin>>costs[i][j];
          }
      }
      cout<<minCost(costs)<<endl;
}
