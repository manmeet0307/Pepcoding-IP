#include<bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long kadane(vector<long> v)
{
    long currmax = 0 , maxsofar = INT_MIN;
    for(int i = 0 ; i  < v.size() ; i++)
    {
        if(currmax>=0)
        {
            currmax += v[i];
        }
        else
        {
            currmax = v[i];
        }
        maxsofar = max(currmax , maxsofar);
    }
    return maxsofar;
}
long kconcat(vector<long> v , int n , int k)
{
    long s = 0;
    for(int i = 0 ; i  < n ;i++)
    {
        s += v[i];
    }
    vector<long> concat(2*n);
    int i;
    for( i = 0 ; i  < n ; i ++)
    {
        concat[i] = v[i];
    }
    for(  ; i  < 2*n ; i ++)
    {
        concat[i] = v[i-n];
    }
    if(s > 0)
    {
        return (k-2)*s + kadane(concat);
    }
    else
    {
        return kadane(concat);
    }
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<long> v(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>v[i];
    }
    cout<<kconcat(v,n,k);
    return 0;
}
