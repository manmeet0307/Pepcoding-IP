#include<bits/stdc++.h>
using namespace std;
int max_rect(int *arr , int n)
{
    int res[n],lb[n],rb[n];
    stack<int> s;
    s.push(0);
    int marea = -1;
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && arr[i]<=arr[s.top()])
        {
            int x = s.top();
            rb[s.top()] = i;
            s.pop();
            if(s.empty())
            {
                lb[x] = -1;
            }
            else{
                lb[x] = s.top();
            }
            marea = max(marea , (rb[x] - lb[x] - 1) * arr[x]);
        }
        /*if(s.empty())
        {
            lb[i] = -1;
        }
        else{
            lb[i] = s.top();
        }*/
        s.push(i);
    }
    while(!s.empty())
    {
        int x = s.top();
        rb[x] = n;
        s.pop();
        if(s.empty())
            {
                lb[x] = -1;
            }
            else{
                lb[x] = s.top();
            }
            marea = max(marea , (rb[x] - lb[x] - 1) * arr[x]);
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
