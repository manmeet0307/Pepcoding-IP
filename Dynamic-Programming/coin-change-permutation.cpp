#include<bits/stdc++.h>
using namespace std;
void coincombination(int* arr, int n , int tar )
{
    int * dp = new int[tar+1];
    memset(dp,0,sizeof(dp)*(tar+1));
    dp[0] = 1;
    int c = 0;
    while(c<n)
    {
        for(int i = 1 ; i<=tar;i++)
        {
            if(i-arr[c] >=0)
            {
                dp[i] += dp[i-arr[c]];
            }
        }
        c++;
    }
    for(int i = 0; i < tar+1; i++)
    {
        cout<<dp[i]<<" ";
    }
}
void coinchange(int* arr, int n , int tar)
{
    int * dp = new int[tar+1];
    memset(dp,0,sizeof(dp)*(tar+1));
    dp[0] = 1;
    for(int i = 1 ; i<=tar;i++)
    {
        //dp[i] = 0;
        int targetsum = i;
        int c = 0;
        while(c<n && arr[c] <= targetsum)
        {
           // if(targetsum-arr[c]<0)
             //   break;
            dp[i] += dp[targetsum - arr[c]];
            c++;
        }
    }
    for(int i = 0 ; i < tar+1;i++)
    {
        cout<<dp[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for( int i = 0 ; i <  n; i++)
    {
        cin>>arr[i];
    }
        int tar;
        cin>>tar;
    coincombination(arr,n,tar);
}
