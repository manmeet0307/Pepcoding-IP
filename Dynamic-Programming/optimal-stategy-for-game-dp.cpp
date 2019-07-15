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
             int op1 = arr[i] + min( i+1 < n? dp[i+1][j-1] : 0,  i+2 < n? dp[i+2][j-1] : 0);
             int op2 = arr[j] + min(i+1<n ? dp[i+1][j-1] : 0, j-2 >=0 ? dp[i][j-2] : 0);
             dp[i][j] = max(op1,op2) ;
         }
      }
  }
  return dp[0][n-1];
}
int main()
{
    int arr1[] = { 8, 15, 3, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1,n));

    int arr2[] = { 2, 2, 2, 2 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optimalStrategyOfGame(arr2,n));

    int arr3[] = { 20, 30, 2, 2, 2, 10 };
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optimalStrategyOfGame(arr3,n));

    return 0;
}
