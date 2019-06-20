#include<bits/stdc++.h>
using namespace std;
int minpair(int *arr, int n)
{
   int ans =INT_MIN;
    for(int i=0;i<n-1;i++)
    {
        int x = arr[i];
        int y = arr[i+1];
        ans = max(ans , x+y);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n ;i++)
    {
        cin>>arr[i];
    }
    cout<<minpair(arr,n);
}
