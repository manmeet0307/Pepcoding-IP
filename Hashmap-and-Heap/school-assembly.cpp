#include<bits/stdc++.h>
using namespace std;
int assembly(vector<int> v ,int n)
{
   unordered_map<int,int > indexmap;
    for(int i =0 ; i < n;i++)
    {
       indexmap[v[i]] = i;
    }
    vector<int> temp(n,0);
    for(int i =0 ; i < n;i++)
    {
        int reqdi = indexmap[v[i]-1];
        temp[i] = temp[reqdi+1];
    }
    return n - temp[n-1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i= 0; i<n ;i++ )
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    cout<<assembly(v,n);
}
