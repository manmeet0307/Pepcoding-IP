#include<bits/stdc++.h>
using namespace std;
void rotate(int n)
{
    queue<int> q;
    unordered_map<int,int> m;
    for(int i =1;i<=n;i++)
    {
        q.push(i);
    }
    int c = 1;
    while(!q.empty())
    {
        int x = 0;
        int r = c%q.size();
        while(x < r)
        {
            q.push(q.front());
            q.pop();
            x++;
        }

        m[q.front()] = c;
        q.pop();
        c++;
    }
    unordered_map<int,int> :: iterator it;
    int r = 1;
    /*for(it = m.begin();it!=m.end();it++)
    {
        if(it->first == r)
        cout<<it->second<<" ";
        r++;
    }*/
    for(int i =0;i<n;i++)
    {
        cout<<m[i+1]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    rotate(n);

}
