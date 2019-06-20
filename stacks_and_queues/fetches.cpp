#include<bits/stdc++.h>
using namespace std;
class RecentFetch{
    queue<int> q;
public:
    int ping(int x)
    {
        int leftbound = x-3000;
        while(!q.empty() && q.front()<leftbound)
        {
            q.pop();
        }
        q.push(x);
        return q.size();
    }
};
int main()
{
    int n;
    RecentFetch r;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int num;
        cin>>num;
        cout<<r.ping(num)<<" ";
    }
}
