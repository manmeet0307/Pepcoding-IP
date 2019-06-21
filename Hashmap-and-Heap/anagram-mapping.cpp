#include<iostream>
#include<bits/stdc++.h>
 #include<vector>
 #include<string>
 using namespace std;
 vector<int> anagramMappings(vector<int>& str1,vector<int> &str2){

     unordered_map<int , int> imap;
     for(int i = 0 ; i <str2.size(); i++)
     {
         imap[str2[i]] = i;
     }
     vector<int> v(str1.size());
     for(int i = 0 ; i  < str1.size() ; i++)
     {
         v[i] = imap[str1[i]];
     }
     return v;
 }

 void display(vector<int> &v){
     for(int i=0;i<v.size();i++){
         cout<<v[i]<<" ";
     }
 }
 int main(int argc,char ** argv){

     int n;
     cin>>n;
     vector<int> num1;
     vector<int> num2;
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         num1.push_back(a);
     }
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         num2.push_back(a);
     }
     vector<int> res;
     res=anagramMappings(num1,num2);
     display(res);

 }
