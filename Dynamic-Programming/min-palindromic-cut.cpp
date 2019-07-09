// Counts Palindromic Subsequence in a given String
#include<iostream>
#include<cstring>
using namespace std;

int countPC(string str)
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

    for(int gap = 0; gap < n; gap++ )
    {
        for(int i=0,j = i+gap;j<n;j++,i++)
        {
            if(i == j )
            {
                if(str[i] == str[j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
            else
            {
                int ans = n +1;
               for(int k = i ; k < j ; k++)
               {
                   ans = min(ans , dp[i][k] + dp[k+1][j] + 1);
               }
               dp[i][j] = ans;
            }
          //cout<<dp[i][j]<<i<<" " <<j<<endl;
        }
    }
    return dp[0][n-1];
    //return 0;
}

// Driver program
int main()
{
	string str = "abcb";
	cout << "Total palindromic cuts are : "
		<< countPC(str) << endl;
	return 0;
}
