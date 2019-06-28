#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 int countBinarySubstrings(string& n) {
     int pc = 0 ,cc = 1,ans = 0;
     for(int i = 1 ; i < n.length() ; i++)
     {
//         if(n[i] == n[i-1] &)
//         {
//             cc++;
//         }
          if(n[i] == n[i-1])
         {
             cc++;
         }
         else
         {
             pc = cc;
             cc = 1;
             //i++;
         }
         if(cc<=pc) ans++;
     }
     return ans;
 }

 int main (int argc,char**argv){
     string n;
     cin>>n;
     cout<<countBinarySubstrings(n);

 }
