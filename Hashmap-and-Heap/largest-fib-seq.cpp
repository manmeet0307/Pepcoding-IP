#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 void solve(vector<int> &v) {
    unordered_map<int,bool> m;
     for(int s = 0 ; s< v.size() ; s++)
     {
         m[v[s]] = true;
     }
     int s = 2, f = 1 , c=0;;
      while(f <= *max_element(v.begin(),v.end()))
      {
          int t = f+s;
          if(m.count(f)  )
          {
              cout<<f<<" ";
            //  m[f] = 0;
          }
          f = s, s = t;
      }
 }

 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     solve(v);
 }
