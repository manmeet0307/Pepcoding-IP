#include<bits/stdc++.h>
using namespace std;
void lps(string x , int m)
{
    int ** dp = new int*[m];
    for(int i=0;i<m;i++)
    {
        dp[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int gap = 0; gap < m ; gap++)
    {
        for(int i = 0,j = i + gap ; j < m ; i++, j++)
        {
            if(i == j)
            {
                dp[i][j] = 1;
                continue;
            }
            else if(x[i] ==x[j])
            {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1] , dp[i+1][j]);
            }
        }
    }

    for(int i =0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j] <<" ";
        }
        cout<<endl;
    }
}
int main()
{
  lps("abccbc" , 6);
}
