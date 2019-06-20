#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

 void zerosumarr(vector<long> arr){
     int n = arr.size();
     int sum =  0;
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
     cout<<c<<endl;
 }

 int main(int argc, char** argv){
     int size;
     cin>>size;
     vector<long> a;
     for (int z = 0; z < size; z++) {
         long val;
         cin>>val;
         a.push_back(val);
     }
     zerosumarr(a);
 }
