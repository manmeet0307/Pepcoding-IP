// A Dynamic Programming based C++ program to count
// number of partitions of a set with n elements
// into k subsets
#include<iostream>
using namespace std;

// Returns count of different partitions of n
// elements in k subsets
int countP(int n, int k)
{
    int ** dp = new int *[k+1];
    for(int i=0;i<k+1;i++)
    {
        dp[i] = new int[n+1];
    }
    for(int i=0;i<n+1;i++)
    {
        dp[0][i] = 0;
    }
    for(int j = 0;j<k+1;j++)
    {
        dp[j][0] = 0;
    }
    for(int i=1;i<k+1;i++)
    {

        for(int j =1;j<n+1;j++)
        {
            if(i== j || i==1)
            {
                dp[i][j] = 1;
            }
            else
                dp[i][j] = dp[i-1][j-1] + (dp[i][j-1]) * i ;
        }
    }
    return dp[k][n];
}

// Driver program
int main()
{
cout << countP(5, 2);
return 0;
}
