/* A naive recursive implementation that simply
follows the above optimal substructure property */
#include<bits/stdc++.h>
using namespace std;
int MatrixChainOrder(int p[] , int n )
{
   int ** dp = new int *[n-1] ;
   for(int i = 0 ;i < n-1;i++)
   {
       dp[i] = new int [n-1];
       for(int j = 0;j<n-1;j++)
       {
           dp[i][j] = 0;
       }
   }
   for(int gap = 0; gap < n-1;gap++)
   {
       for(int i = 0,j = i+gap ; j <n-1 ; i++,j++ )
       {
           if(i==j)
            continue;
            dp[i][j]= INT_MAX;
           for(int x = i ; x < j ; x++ )
           {
               int cost = dp[i][x] + dp[x+1][j] + p[i] * p[x+1] * p[j+1];
                dp[i][j] = min(dp[i][j] , cost);
           }
       }
   }
   return dp[0][n-2];

}
int main()
{
	int arr[] = {1, 2, 3, 4, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, n);
}
