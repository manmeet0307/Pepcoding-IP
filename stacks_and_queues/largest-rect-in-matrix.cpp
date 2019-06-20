#include<bits/stdc++.h>
using namespace std;
int lah(int *arr , int n)
{
    int lb[n],rb[n];
    stack<int> s;
    s.push(0);
    lb[0]=-1;
    for(int i =1 ;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>= arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
         lb[i] = -1;
        }
        else
        {
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
    for(int i = n-2;i>=0;i--)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
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
    int marea= -1;
    for(int i =0;i<n;i++)
    {
        marea = max(marea , (rb[i] - lb[i] - 1)*arr[i]);
    }
    return marea;
}
int rect(int arr[][100],int r,int c)
{
    int bars[c] ={};
    int marea = -1;
    for(int i =0;i <r;i++)
    {
        for(int j =0;j<c;j++)
        {
            if(arr[i][j]==1)
            {
                bars[j]++;
            }
            else
            {
                bars[j] = 0;
            }
        }
        marea = max(marea , lah(bars,c));
    }

return marea;
}
int main()
{
    int r,c;
    cin>>r>>c;
    int arr[100][100];
    for(int i = 0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<rect(arr,r,c);
}
