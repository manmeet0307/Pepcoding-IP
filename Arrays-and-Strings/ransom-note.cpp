#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;

 bool canConstruct(string & rans, string& magzine) {
     unordered_map<char , int> m1,m2;
     for(int i = 0 ; i < magzine.length() ; i++)
     {
         m1[magzine[i]]++;
     }
     for(int i = 0 ; i < rans.length() ; i++)
     {
         m2[rans[i]]++;
     }
     unordered_map<char , int> :: iterator it;
     for(it = m2.begin() ; it != m2.end() ;it++ )
     {
         if(!m1.count(it->first))
         {
             return false;
         }
         else if(it->second > m1[it->first])
         {
             return false;
         }
     }
 return true;
 }

 int main (int argc,char** argv){
     string s,t;
     cin>>s;
     cin>>t;
     bool res=canConstruct(s,t);
     if(res==true){
         cout<<"true";
     }else{
         cout<<"false";
     }

 }
