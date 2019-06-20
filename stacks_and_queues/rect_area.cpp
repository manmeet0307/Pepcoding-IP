#include<bits/stdc++.h>
using namespace std;
int max_rect(int *arr , int n)
{
    int res[n],lb[n],rb[n];
    stack<int> s;
    s.push(0);
    lb[0] = -1;
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && arr[i]<=arr[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        {
            lb[i] = -1;
        }
        else{
            lb[i] = s.top();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        s.pop();
    }
    s.push(n-1);
    rb[n-1] = n;
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() && arr[i] <= arr[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        {
            rb[i] = n;
        }
        else{
            rb[i] = s.top();
        }
        s.push(i);
    }
    int marea = -1;
    for(int i=0;i<n;i++)
    {
        int ar = (rb[i]-lb[i]-1)*arr[i];
        //cout<< lb[i]<<" "<<rb[i]<<" "<<ar<<endl;
        marea = max(ar,marea);
    }
    return marea;
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
    cout<<max_rect(arr , n);
}
