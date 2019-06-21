#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

 vector<string> commonChars(vector<string>& A){
 	 unordered_map<char , int> base , curr;
 	 for(int i = 0 ;i <A[0].size() ; i++ )
     {
         base[A[0][i]]++;
     }
     for(int j = 1 ; j < A.size() ; j++)
     {
         for(int k = 0; k < A[j].size() ; k++)
         {
             if(base.count(A[j][k]) && curr[A[j][k]] < base[A[j][k]] )
             {
                 curr[A[j][k]]++;
             }
         }
         base = curr;
         curr.clear();
     }
     unordered_map<char , int> :: iterator it;
     vector<string> v;
     string t;
     for(it = base.begin() ; it!= base.end() ; it++)
     {
         for(int j = 0 ; j < it->second ;j++)
            v.push_back(string(1,it->first));
     }

     return v;
 }

 void display(vector<string> &ans){
     cout<<"[";
         for(int j=0;j<ans.size();j++){
             cout<<ans[j];
             if(j!=ans.size()-1){
                 cout<<", ";
             }
         }
     cout<<"]"<<endl;
 }
 int main(int argc,char ** argv){

     int n;
     cin>>n;
     vector<string> A;
     for(int i=0;i<n;i++){
         string a;
         cin>>a;
         A.push_back(a);
     }
     vector<string> res;
     res=commonChars(A);
     sort(res.begin(),res.end());
     display(res);

 }
