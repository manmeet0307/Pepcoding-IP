#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 int maxlen(vector<int> &v,int n) {
    unordered_map<int,int> m;
   int ps = 0;
   m[0] = -1;
   int ml = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        ps += v[i];
        if(m.count(ps))
        {
            ml = max(ml , i - m[ps] );
        }
        else
        {
            m[ps] = i;
        }
    }
    return ml;
 }

 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     cout<<maxlen(v,n)<<endl;
 }
