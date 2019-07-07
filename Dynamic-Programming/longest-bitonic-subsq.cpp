#include<bits/stdc++.h>
using namespace std;
string printlis(int * dp, int n, int arr[] , int i )
{
        if(i<0)
        {
            return "";
        }
    if(dp[i] == 1)
    {
        return to_string(arr[i])+" ";
    }
    string ans="";
    for(int j = i-1;j>=0;j--)
    {
        if(dp[j] == dp[i] - 1 && arr[j] < arr[i])
        {
            ans = printlis(dp,n,arr,j);
        }
        if(ans.length() > 0)
        {
            ans += to_string(arr[i]) + " ";
            return ans;
        }
    }
    return ans;
}
void lis( int arr[], int n, int* dp)
{
    //int*dp = new int[n];
	for(int i=0;i<n;i++)
	{
	  dp[i] = 1;
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

    string a = printlis(dp,n,arr,3);
    cout<<"lis : "<<a<<endl;
 }
 string printlds(int *dp, int n,int arr[] ,int i)
 {
     if(i<0) return "";
     if(dp[i]==1)
     {
         return to_string(arr[i]);
     }
     string p ;
     p = to_string(arr[i]) + " ";
     string ans = "";
     for(int j = i+1;j<n;j++)
     {
         if(dp[j] == dp[i]-1 && arr[j] < arr[i])
         {
             ans = printlds(dp,n,arr,j);
         }

         if(ans.length() > 0)
         {
             return p+ans+" ";
         }
     }
     return ans;
 }
 void lds( int arr[], int n,int * dp )
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
    cout<<endl;
    cout<<"Lds"<<endl;
    string a = printlds(dp,n,arr,0);
    cout<<a<<endl;
}

void printlbs(int *lisar, int *ldsar,int n,int arr[],int i)
{
    string a = printlis(lisar , n,arr , i);
    string b = printlds(ldsar,n,arr,i);
    int pos = b.find(" ");
    b = b.substr(pos+1);
    cout<<a<<" " <<b;
}
int lbs( int arr[], int n )
{
    //vector<int> lis(int n),lds(int n);
    int *lisar = new int[n];
    int *ldsar = new int[n];
    lis(arr,n,lisar);
    lds(arr,n,ldsar);
    int minel = -1;
    int index = -1;
    for(int i=0;i<n;i++)
    {
        if(lisar[i]+ldsar[i] > minel)
        {
            minel =  lisar[i]+ldsar[i];
            index = i;
        }
    }
    cout<<"lbs: "<<endl;
     printlbs(lisar,ldsar,n,arr,index);
        return minel-1;

}
int main()
{
int arr[] = {80, 60, 30, 40, 20, 10};
int n = sizeof(arr)/sizeof(arr[0]);
cout<<lbs(arr,n);
return 0;
}
