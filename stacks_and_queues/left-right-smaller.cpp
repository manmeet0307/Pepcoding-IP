#include<bits/stdc++.h>
using namespace std;
int smaller(int * arr , int n)
{
    stack<int> s;
    s.push(n-1);
    int nsel[1000],nser[1000];
    nser[n-1] = 0;
    for(int i = n-2; i >=0 ; i--)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
         s.empty() ==1 ? nser[i] = 0 : nser[i] =  arr[s.top()];
        s.push(i);

    }
    while(!s.empty())
    {
        nser[s.top()] = 0;
        s.pop();
    }
    nsel[0] = 0;
    s.push(0);
    for(int i =1;i<n;i++)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
        {
                  s.pop();
        }
        s.empty() == 1 ? nsel[i] = 0 : nsel[i] = arr[s.top()];
        s.push(i);
    }
    int d = -1;
    for(int i = 0;i<n;i++)
    {
        d = max(d, abs(nsel[i]-nser[i]));
    }
    return d;
}
int main()
{
    int pos[1000];

    int n;
    cin>>n;
    for(int  i=0;i<n;i++)
    {
        cin>>pos[i];
    }
cout<<smaller(pos,n);
}
