#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int equilibriumindex(vector<long> v)
{
    int n = v.size();
    long rs = 0;
    for(int i = 0 ; i < n ; i++)
    {
        rs+=v[i];
    }
    long ls = v[0];
    rs -=v[0];
    for(int i = 1 ;i  < n-1 ; i ++)
    {
        rs -= v[i];
        if(ls == rs)
        {
            return i;
        }
        ls += v[i];
    }
    return -1;

}

int main() {
    int n;
    cin>>n;
    vector<long> v(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>v[i];
    }
    cout<<equilibriumindex(v);
}
