// C++ program to find maximum achievable value
// with a knapsack of weight W and multiple
// instances allowed.
#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n, int val[], int wt[])
{
    int * dp = new int[W+1];
    for(int i =0;i<W+1;i++)
    {
        dp[i]=0;
    }
    for(int i = 0; i<n ; i++)
    {
       for(int j=0;j<W+1;j++)
       {
           if(wt[i] >= j && j%wt[i] == 0)
           {
               dp[j] = max(dp[j] , (j/wt[i])*val[i]);
           }
           if(j-wt[i] >=0)
           {
               dp[j]  =max(dp[j] , dp[j-wt[i]] + val[i]);
           }
       }
    }
    for(int i=0;i<W+1;i++)
    {
        cout<<dp[i]<<" ";
    }
return dp[W];
}

// Driver program
int main()
{
	int W = 100;
	int val[] = {10, 30, 20};
	int wt[] = {5, 10, 15};
	int n = sizeof(val)/sizeof(val[0]);

	cout << unboundedKnapsack(W, n, val, wt);

	return 0;
}
