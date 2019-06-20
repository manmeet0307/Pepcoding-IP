#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 int subArraySum(vector<int> arr, int n, int sum) {
    unordered_map<int , int> m;
    m[0] = 1 ;
    int ps = 0;
    int c = 0;
    for(int i = 0 ;i < n ; i++)
    {
        ps += arr[i];
        if(m.count(ps-sum))
        {
            c+=m[ps-sum];
        }
        m[ps]++;
    }
     return c;
 }
 int main(int argc, char** argv){
     int n, sum;
     cin>>n>>sum;
     vector<int> arr;
     for (int z = 0; z < n; z++) {
         int val;
         cin>>val;
         arr.push_back(val);
     }
     cout<<subArraySum(arr, n, sum);
 }
