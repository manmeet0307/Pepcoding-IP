#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k)
{
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for(int j = 0 ; j < k+1; j++)
    {
        dp[1][j] = j;
    }
    for(int i=1;i<n+1;i++)
    {
        dp[i][1] = 1;
    }

    for(int i = 2; i < n+1 ; i++)
    {

       for(int j=2;j<k+1;j++)
       {
           int mans = INT_MIN;
           int m = INT_MAX;
           for(int f = 1 ; f <= j ; f++)
           {
               mans = max(dp[i-1][f-1] , dp[i][j-f]);
               m = min( m, mans);
           }
           dp[i][j] = m+1;
       }

    }

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            cout<<dp[i][j]<<" " ;
        }
        cout<<endl;
    }
    return dp[n][k];
}

/* Driver program to test to pront printDups*/
int main()
{
	int n = 2, k = 36;
	cout<< eggDrop(n, k);
	return 0;
}
