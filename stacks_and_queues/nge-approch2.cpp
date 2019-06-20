#include<bits/stdc++.h>
using namespace std;
void print_nge(int *arr , int n)
{
    int res[n]={};
    stack<int> s;
    s.push(0);
    for(int i= 1;i<n;i++)
    {
        while(!s.empty() && arr[i]>arr[s.top()])
        {
            res[s.top()] = arr[i];
            s.pop();
        }/*
        if(s.empty())
        {
            res[i] = -1;
        }
        else{
                res[i] = s.top();
        }*/
        s.push(i);
    }
    while(!s.empty())
    {
        res[s.top()] = -1;
        s.pop();
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
