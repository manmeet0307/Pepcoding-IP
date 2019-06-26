#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

 vector<string> func(vector<string> &arr) {
     vector<string> v;
     unordered_map<string,int> m;
     for(int i = 0  ; i<arr.size() ; i++)
     {
         m[arr[i]]++;
     }
     unordered_map<string,int> :: iterator it;
     int mf = -1;
     string ans ;
     for(it = m.begin() ; it!= m.end() ; it++)
     {
         if(it->second > mf)
         {
             mf = it->second;
             ans = it->first;
         }
     }
     v.push_back(ans);
     return v;
 }

 int main(int argc, char** argv){
     int n; cin>>n;
     vector<string> str;
     for (int i = 0; i < n; i++) {
         string s; cin>>s;
         str.push_back(s);
     }
     vector<string> res = func(str);
     cout<<res[0];
 }
