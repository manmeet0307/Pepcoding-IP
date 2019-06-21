#include<iostream>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;

 int solve(string& s) {
     unordered_map<int , int> m;
     for(int i = 0 ; i < s.length() ; i++)
     {
          m[(s[i]-48)]++;
     }
     int mf = -1 , num = -1;
     for(int i = 9 ; i>=0; i--)
     {
         if(m[i] > mf)
         {
             num =  i;
             mf = m[i];
         }
     }
     return num;
 }

 int main(int argc,char** argv){
     string s;
     cin>>s;
     cout<<solve(s)<<endl;
 }
