#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 #include<string>
 using namespace std;
 void display(vector<int> &arr) {
      for (int i = 0; i < arr.size(); i++) {
          cout<<arr[i]<<" ";
      }
      cout<<endl;
  }

 void print (vector<char> &v) {
    vector<int> vt(v.size());
     for(int i = 0 ; i  <  vt.size() ;i++)
     {
        if(v[i]=='0') vt[i]= -1;
        else vt[i] = v[i]-48;
     }
   // display(vt);
     int ps = 0,ans = 0;
     unordered_map<int, int> m;
  m[0]=-1;
     for(int i = 0 ; i < vt.size();i++)
     {
         ps +=vt[i];
         if(!m.count(ps))
         {
             m[ps] = i;
         }
         else
         {
             ans = max(ans , (i - m[ps]));
         }
     }
     cout<<ans;
 }

 int main(int argc,char** argv){
     string s;
     cin>>s;
     vector<char> v(s.length());
     for(int i=0;i<s.length();i++){
         v[i]=s[i];
     }
     print(v);
 }
