#include<bits/stdc++.h>
using namespace std;
void krev(queue<int> &q,int n,int k)
{
   stack<int> s;
    for(int i=0;i<k;i++)
    {
        int x = q.front();
        q.pop();
        s.push(x);
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<(n-k);i++)
    {
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        q.push(num);
    }
    krev(q,n,k);
    for(int i=0;i<n;i++)
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}
