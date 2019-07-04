#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
void printpairs(vector<long> v , int tar)
{
    int n = v.size();
    sort(v.begin() , v.end());
    int e = 1;
    bool f = 0;
    for(int s = 0; s < n ; s++)
    {

        e = s+1;
        if(s>n)
        {break;}
        int gap = tar - (v[e] - v[s]);
        while(e < n && gap > 0 )
        {
            e++;
            gap = tar - (v[e] - v[s]);
        }
        if(gap== 0)
        {
            cout<<v[s]<<" "<<v[e]<<endl ;
            f = 1;
        }

    }
    if(f==0)
    {
        cout<<"-1";
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tar,n;
    cin>>n>>tar;
     vector<long> v(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>v[i];
    }
    printpairs(v,tar);
    return 0;
}
