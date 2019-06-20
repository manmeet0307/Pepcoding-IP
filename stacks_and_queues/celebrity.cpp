#include<bits/stdc++.h>
using namespace std;
int celeb(int a[][100],int n)
{
    stack<int> s;
    for(int i =0;i<n;i++)
    {
        s.push(i);
    }
    while(s.size()>1)
    {
        int x = s.top();
        s.pop();
        int y =s.top();
        s.pop();
        if(a[x][y])
        {
            s.push(y);
        }
        else
        {
            s.push(x);
        }
    }
    int ans = s.top();
    for(int i =0;i<n;i++)
    {
        if(i==ans)
            continue;
        if(a[ans][i])
            return -1;
    }
     for(int i =0;i<n;i++)
    {
        if(i==ans)
            continue;
        if(a[i][ans]==0)
            return -1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int a[100][100];
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<celeb(a,n);
}
