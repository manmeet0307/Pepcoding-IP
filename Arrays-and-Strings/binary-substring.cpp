#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 string bin(int n)
 {
    string ans;
    while(n>0)
    {
        ans += (n%2) + '0';
        n/=2;
    }
    reverse(ans.begin() , ans.end());
    return ans;
 }
 bool queryString(string &S, int N) {
 	 for(int i = N/2;i<=N;i++)
     {
         string b = bin(i);
         size_t t = S.find(b);
         if(t == string :: npos)
         {
             return false;
         }
     }
     return true;
 }

 //Don't make any changes here.
 int main(int argc, char** argv){
     int n;
     cin>>n;
     string str;
     cin>>str;
     if(queryString(str, n)){
         cout<<"true";
     }else{
         cout<<"false";
     }
 }
