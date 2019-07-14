#include<bits/stdc++.h>
using namespace std;
int maxprice(int prices[] , int totlen)
{
    int * dp = new int  [totlen+1];
    dp[0] = 0;
    for(int i=1;i<totlen+1;i++)
    {
        dp[i] = prices[i-1];
        for(int x = 0; x<i;x++)
        {
            int other = i - x;
            dp[i] = max(dp[i] , dp[x] + dp[other]);
        }

    }
    return dp[totlen];
}
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<< maxprice(arr, size);
    getchar();
    return 0;
}
