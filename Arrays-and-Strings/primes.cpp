#include<bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int fun(int n , int q , int m , vector<pair<int,int>> op)
{
    vector<int> arr(n,0);
    for(int i = 0 ; i < op.size() ; i++)
    {
        arr[op[i].first]++;
        if(op[i].second +1 < n)
        {
            arr[op[i].second + 1]--;
        }
        cout<<op[i].first<<op[i].second<<endl;
    }
    for(int i =1;i<n;i++)
    {
        arr[i] = arr[i] + arr[i-1];

    }

cout<<endl;
for(int i =0 ; i < n;i++)
{
    cout<<arr[i]<<" ";
}

    int ans = 0;
    for(int i = 0 ; i < op.size();i++)
    {
        vector<int> copy = arr;
        pair<int,int> curr = op[i];

        for(int i= curr.first;i<=curr.second ;i++)
        {
            copy[i]--;
        }

        int ca = 0;
        for(int i = 0; i < n ;i++)
        {
            if(copy[i] == m)
            {
                ca++;
            }
        }
        ans = max(ans , ca);
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n , q , m;
    cin>>n>>q>>m;
    vector<pair<int,int>> operation;
    for(int i = 0 ; i < q ; i++)
    {
        int s,e;
        cin>>s>>e;
        operation.push_back(make_pair(s,e));
    }
    cout<<fun(n,q,m,operation);
    return 0;
}
