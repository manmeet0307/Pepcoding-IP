#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

 bool isIsomorphic(string& s, string& t) {
     unordered_map<char,char> m;
     for(int i = 0 ; i < s.length() ; i++)
     {
            if(m.count(s[i]))
            {
                if(m[s[i]] != t[i])
                {
                    return false;
                }
            }
            else
            {
                m[s[i]] = t[i];
            }
     }
     return true;

 }
 int main(int argc,char** argv){
     string A,B;
     cin>>A;
     cin>>B;
     bool res=isIsomorphic(A, B);
     if(res==0){
         cout<<"false";
     }else{
         cout<<"true";
     }
 }
