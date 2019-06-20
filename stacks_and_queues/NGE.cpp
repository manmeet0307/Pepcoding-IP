#include<bits/stdc++.h>
using namespace std;
void print_nge(int *arr , int n)
{
    int res[n];
    stack<int> s;
    s.push(arr[n-1]);
    res[n-1] = -1;
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() && arr[i]>s.top())
        {
            s.pop();
        }
        if(s.empty())
        {
            res[i] = -1;
        }
        else{
                res[i] = s.top();
        }
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++)
    {

        cout<<res[i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[10000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print_nge(arr , n);
}
