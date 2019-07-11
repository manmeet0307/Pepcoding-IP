#include<iostream>
 #include<vector>
 using namespace std;

 int CountWays(int n, int k) {
        int ** dp = new int * [2];
        for(int i = 0 ; i < 2 ; i++)
        {
            dp[i] = new int[n];
            for(int j=0;j<n;j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[1][0] = k;
        for(int i = 1; i < n ; i++)
        {
            dp[1][i] = (dp[0][i-1] + dp[1][i-1])*(k-1);
            dp[0][i] = dp[1][i-1];
        }
//         for(int i = 0 ; i < 2 ; i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout<<dp[i][j]<< " ";
//            }
//            cout<<endl;
//        }
        return dp[0][n-1] + dp[1][n-1];
}

 int main(int argc,char** argv){
     int n,k;
     cin>>n>>k;
     cout<<CountWays(n,k)<<endl;
 }
