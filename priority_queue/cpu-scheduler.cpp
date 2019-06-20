#include<bits/stdc++.h>
using namespace std;
bool operator<(const pair<char,int>& p1, const pair<char,int>& p2)
{

    return p1.second < p2.second;
}
class CompareHeight {
    public:
    int operator()(const pair<char,int>& p1, const pair<char,int>& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.second < p2.second;
    }
};
int scheduler(char * arr, int N, int n)
{
    unordered_map<char,int> m;
    priority_queue<pair< char , int >,vector<pair<char,int>> , CompareHeight> pq;
    for(int i=0;i<N;i++)
    {
        m[arr[i]]++;
    }
 /*   for(int i=0 ; i<N ; i++)
    {
        pq.push(make_pair(arr[i],m[arr[i]]));

    }*/
    unordered_map<char,int> :: iterator it;
    for(it = m.begin() ;it !=m.end() ;it++)
    {
        pq.push(make_pair(it->first,it->second));
    }
    int c =0;
    while(!pq.empty())
    {
        vector<pair<char,int>> v;
        for(int i=0 ; i<=n ; i++)
        {
            if(!pq.empty()){

                pair<char,int> p = pq.top();
           //     cout<<p.first<<" " << p.second<<" " <<pq.size()<<" "<<c<<endl;
            if(i==0 && pq.size() < n+1 && p.second == 1)
            {
                c += pq.size();
                return c;
            }
                pq.pop();
            if( p.second > 1 )
            {
                v.push_back(make_pair(p.first, p.second - 1));
            }
            }
            c++;

        }
        if(v.size()==0)
            return c;
        for(int i =0;i<v.size() ;i++)
        {
            pq.push(v[i]);
        }
    }

    return c;
}
int main()
{
    int n, N;
    cin>>n>>N;
    char c[100];
    for(int i=0;i<N;i++)
    {
        cin>>c[i];
    }
    cout<<scheduler(c,N,n);
}
