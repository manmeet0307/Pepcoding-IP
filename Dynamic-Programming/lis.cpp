#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> v)
{
    for(int i =0;i< v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void print_lis(int * dp,int n, int arr[],int i,vector<int> v)
{
    if(i<0)
    {
        return ;
    }
    if(i==0)
    {
        v.push_back(arr[i]);
        printvector(v);
        return ;
    }
    for(int j = i-1;j>=0;j--)
    {
        if(dp[j] == dp[i]-1 && arr[j] < arr[i])
        {
            v.push_back(arr[i]);
            print_lis(dp,n,arr,j,v);
            v.pop_back();
        }
    }
}
int lis( int arr[], int n)
{
	int * dp = new int[n];
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
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
    vector<int> v;
    print_lis(dp,n,arr,7,v);
}


int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
		lis( arr, n );
	return 0;
}
