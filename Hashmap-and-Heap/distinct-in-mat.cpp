#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 int count(vector<vector<int> > &a) {
     unordered_set<int> s1 , s2;
     for(int i = 0 ; i < a[0].size() ; i++)
     {
         s1.insert(a[0][i]);
     }
     for(int j = 1 ; j < a.size() ; j++)
     {
         for(int k = 0 ; k < a[j].size() ; k++)
         {
             if(s1.count(a[j][k]))
             {
                 s2.insert(a[j][k]);
             }
         }
         s1 = s2;
         s2.clear();
     }
     return s1.size();
 }

 //Don't make any changes here

 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<vector<int> > v(n,vector<int>(n));
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>v[i][j];
         }
     }
     cout<<count(v)<<endl;
 }
