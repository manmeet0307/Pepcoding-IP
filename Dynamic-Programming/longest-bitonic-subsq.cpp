#include<bits/stdc++.h>
using namespace std;
int lis( int arr[], int n,int * dp)
{
	for(int i=0;i<n;i++)
	{
	  dp[i] = 0;
	}
	dp[0] = 1;
	for(int i = 1;i < n ;i++)
    {
        for(int j = i-1;j>=0;j--)
        {
            if(arr[j] < arr[i])
            {
                dp[i] = max(dp[i] , dp[j] +1);
            }
        }
    }
    cout<<"lis"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
 }
 int lds( int arr[], int n ,int * dp)
{
	for(int i=0;i<n;i++)
	{
	  dp[i] = 0;
	}
	dp[n-1] = 1;
	for(int i = n-2;i >=0 ;i--)
    {
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < arr[i])
            {
                dp[i] = max(dp[i] , dp[j] +1);
            }
            dp[i]==0 ? dp[i]=1: dp[i] = dp[i];
        }
    }
    cout<<"lds"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
}
int lbs( int arr[], int n )
{
    //vector<int> lis(int n),lds(int n);
    int *lisar = new int[n];
    int *ldsar = new int[n];
    lis(arr,n,lisar);
    lds(arr,n,ldsar);
    int minel = -1;
    for(int i=0;i<n;i++)
    {
        minel = max(lisar[i] + ldsar[i] , minel);
    }
        return minel-1;

}
int main()
{
int arr[] = {80, 60, 30, 40, 20, 10};
int n = sizeof(arr)/sizeof(arr[0]);
printf("Length of LBS is %d\n", lbs( arr, n ) );
return 0;
}
