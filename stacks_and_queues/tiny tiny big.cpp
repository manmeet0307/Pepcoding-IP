#include<bits/stdc++.h>
using namespace std;
bool check(int * arr , int n)
{
    for(int i=0;i+2 < n;i++)
    {
        int m = arr[i];
        int n = arr[i+1];
        int o = arr[i+2];
        if(m<n && o> m && o<n)
        {
            return  true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int arr[10000];
    for(int i = 0;i<n ;i++)
    {
        cin>>arr[i];
    }
    if(check(arr , n))
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }

}
