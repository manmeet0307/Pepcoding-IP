// C++ program to solve Gold Mine problem
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Returns maximum amount of gold that can be collected
// when journey started from first column and moves
// allowed are right, right-up and right-down
void getMaxGold(int gold[][MAX], int m, int n)
{
    int ** dp = new int*[m];
    for(int i = 0 ;i<m;i++)
    {
        dp[i] = new int[n];
    }
    for(int i = 0 ; i < m ;i++)
    {
        dp[i][n-1] = gold[i][n-1];
    }
    for(int j=n-2;j>=0;j--)
    {
        for(int i = 0;i<m;i++)
        {
            if(i==0)
            {
                dp[i][j] = max(dp[i][j+1] , dp[i+1][j+1])+gold[i][j];
            }
            else if( i== m-1)
            {
                dp[i][j] = max(dp[i][j+1] , dp[i-1][j+1])+gold[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i][j+1] , max(dp[i+1][j+1], dp[i-1][j+1]))+gold[i][j];
            }
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
}

// Driver Code
int main()
{
	int gold[MAX][MAX]= {
	    {1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m = 4, n = 4;
    getMaxGold(gold, m, n);
	return 0;
}
