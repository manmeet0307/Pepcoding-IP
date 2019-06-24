#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 void print (vector<int> &vt,int k,int n) {
    int ps = 0,ans = 0;
     unordered_map<int, int> m;
        m[0]=-1;
     for(int i = 0 ; i < vt.size();i++)
     {
         ps +=vt[i];
         if(!m.count(ps%k))
         {
             m[ps % k] = i;
         }
         if(m.count(ps % k))
         {
             ans = max(ans , (i- m[ps%k]));
         }
     }
     cout<<ans;
 }

 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     int k;
     cin>>k;
     print(v,k,n);
 }
