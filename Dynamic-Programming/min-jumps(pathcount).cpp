#include<bits/stdc++.h>
using namespace std;
int pathcount(int* jumps,int n)
{
    int * dp = new int[n];
     for(int i = 0 ; i < n ; i++)
     {
         dp[i] = 0;
     }
     dp[n-1] = 1;
     for(int i = n-2 ; i>=0;i--)
     {
         if(jumps[i] == 0)
         {
             continue;
         }
         int c = 0;
         for(int j = i+1; j< i+1+jumps[i] ; j++)
         {
             c += dp[j];
         }
         dp[i] = c;
     }

      for(int i = 0 ; i < n ; i++)
     {
         cout<<dp[i]<<" " ;
     }

     //return dp[0];
}
int main()
{
    int jumps[] = {3,5,0,1,2,0,3,1,0,1,0};
    pathcount(jumps,11);
}
