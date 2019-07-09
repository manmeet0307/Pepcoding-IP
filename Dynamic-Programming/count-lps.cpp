// Counts Palindromic Subsequence in a given String
#include<iostream>
#include<cstring>
using namespace std;

// Function return the total palindromic subsequence
int countPS(string str)
{
    int n = str.length();
    int ** dp = new int*[n];
    for(int i =0;i<n;i++)
    {
        dp[i] = new int[n];
        for(int j =0;j<n;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        dp[i][i]= 1;
    }
    for(int gap = 1; gap < n; gap++ )
    {
        for(int i=0,j = i+gap;j<n;j++,i++)
        {
            if(str[i] == str[j])
            {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
            }
            else
            {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
          //  cout<<dp[i][j]<<i<<" " <<j<<endl;
        }
    }
    return dp[0][n-1];
    //return 0;
}

// Driver program
int main()
{
	string str = "abcb";
	cout << "Total palindromic subsequence are : "
		<< countPS(str) << endl;
	return 0;
}
