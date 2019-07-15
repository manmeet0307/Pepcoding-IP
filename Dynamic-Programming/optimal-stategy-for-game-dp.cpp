#include <bits/stdc++.h>
using namespace std;
int optimalStrategyOfGame(int* arr, int n)
{
    int ** dp = new int *[n];
  for(int i=0; i<n;i++)
  {
      dp[i] = new int[n];
      for(int j = 0 ; j < n ; j++)
      {
          dp[i][j] = 0;
      }
  }
  for(int gap = 0 ; gap<n; gap++)
  {
      for(int i =0 , j = i+gap;j<n;j++,i++)
      {
         if(i==j)
         {
             dp[i][j] = arr[i];
         }
         else if( j == i+1)
         {
             dp[i][j] = max(arr[i] , arr[j]);
         }
         else
         {
             int op1 = arr[i] + min( i+1 < n? dp[i+1][j-1] : 0,  i+2 < n? dp[i+2][j] : 0);
             int op2 = arr[j] + min(i+1<n ? dp[i+1][j-1] : 0, j-2 >=0 ? dp[i][j-2] : 0);
             dp[i][j] = max(op1,op2) ;
         }
      }
  }
  return dp[0][n-1];
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }
       cout<<optimalStrategyOfGame(a,n)<<endl;

   }
}
