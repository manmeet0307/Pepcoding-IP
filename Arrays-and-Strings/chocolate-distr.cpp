#include <cmath>
#include <cstdio>
#include <vector>
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int distr(int a[] , int n , int m)
{
    sort(a , a+n);
    int ans = INT_MAX;
    for(int i = 0; i < n-m+1 ; i++)
    {
        int f = a[i];
        int l = a[i+m-1];
        ans = min(ans , l-f);
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>> n;
    int a[n];
    int m ;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<distr(a,n,m);
    return 0;
}
