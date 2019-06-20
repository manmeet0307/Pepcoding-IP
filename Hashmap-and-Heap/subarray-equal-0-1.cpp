#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 int countSubArrays(vector<int> arr, int n) {

    for(int  i =0 ;i < n ;i ++)
    {
        if(arr[i] == 0)
        {
            arr[i] = -1;
        }
    }
    unordered_map<int , int> m;
    m[0] = 1 ;
    int ps = 0;
    int c = 0 , sum = 0;
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
     int n;
     cin>>n;
     vector<int> a;
     for (int z = 0; z < n; z++) {
         int val;
         cin>>val;
         a.push_back(val);
     }
     cout<<countSubArrays(a, n);
 }
