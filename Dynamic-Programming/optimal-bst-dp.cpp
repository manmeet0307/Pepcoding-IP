#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j);

int optimalSearchTree(int keys[], int freq[], int n)
{
        int dp[n][n];
        memset(dp,0, sizeof(dp));
        for(int gap = 0; gap < n; gap++)
        {
            for(int i = 0 , j = i + gap ; j<n;j++,i++)
            {
                if(i==j)
                {
                    dp[i][j] = freq[i];
                }
                else
                {
                    int ans = INT_MAX;
                    for(int r = i ; r <= j ; r++)
                    {
                        int ls,rs;
                        if(r <= i)
                        {
                            ls = 0;
                            rs = dp[r+1][j];
                        }
                        else if(r >= j)
                        {
                            ls = dp[i][r-1];
                            rs = 0;
                        }
                        else
                        {
                            ls = dp[i][r-1];
                            rs = dp[r+1][j];
                        }
                        int op = ls+rs;
                        ans = min(ans,op);
                    }
                    dp[i][j] = ans + sum(freq,i,j);
                }
            }
        }
        return dp[0][n-1];
}

int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}

int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys)/sizeof(keys[0]);
	cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
	return 0;
}
