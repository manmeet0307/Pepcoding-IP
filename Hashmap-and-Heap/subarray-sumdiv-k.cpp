#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 int subarraysDivByK(vector<int> arr, int k) {
    unordered_map<int , int> m;
    m[0] = 1 ;
    int ps = 0;
    int c = 0;
    int x;
    int n = arr.size();
    for(int i = 0 ;i < n ; i++)
    {
        ps += arr[i];
        if(ps<0)
        {
           if(ps % k == 0)
           {
               x = 0;
           }
           else
            x= (ps %k)+k;
           //.count(x-sum)
        }
        else
        {
           x = ps % k;
        }
        if(m.count(x))
        {
            c += m[x];
        }
        m[x]++;
    }
     return c;
 }
int main(int argc, char** argv){
     int n, k;
     cin>>n>>k;
     vector<int> arr;
     for (int z = 0; z < n; z++) {
         int val;
         cin>>val;
         arr.push_back(val);
     }
     cout<<subarraysDivByK(arr, k);
 }
