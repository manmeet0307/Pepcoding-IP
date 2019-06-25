#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 int consecuitveSub(vector<int> &v,int n) {
     unordered_map<int,bool> m;
     for(int i =0 ;i < v.size() ; i++)
     {
         m[v[i]] = true;
     }
     int ml = 0;
     for(int i =0 ;i < v.size() ; i++)
     {
         if(m.count(v[i]-1))
         {
             m[v[i]] = false;
         }
     }
     for(int i =0 ;i < v.size() ; i++)
     {
         if(m[v[i]])
         {
             int l = 1;
             int c = v[i];
             while(m.count(++c))
                l++;
             ml = max(ml , l);
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
     cout<<consecuitveSub(v,n)<<endl;
 }
