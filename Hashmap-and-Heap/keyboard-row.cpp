#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 bool checkrow(string s)
 {
     unordered_map<char,int> m ;
     m['q'] = 1;
     m['w'] = 1;
     m['e'] = 1;
     m['r'] = 1;
     m['t'] = 1;
     m['y'] = 1;
     m['u'] = 1;
     m['i'] = 1;
     m['o'] = 1;

     m['p'] = 1;
     m['a'] = 2;
     m['s'] = 2;
     m['d'] = 2;
     m['f'] = 2;
     m['g'] = 2;
     m['h'] = 2;
     m['j'] = 2;
     m['k'] = 2;
     m['l'] = 2;

     m['z'] = 1;
     m['x'] = 2;
     m['c'] = 2;
     m['v'] = 2;
     m['b'] = 2;
     m['n'] = 2;
     m['m'] = 2;
 transform(s.begin(), s.end(), s.begin(), ::tolower);
  int kc = m[s[0]];

  for(int i = 1; i < s.length() ;i++)
  {
      if( m[s[i]] != kc )
      {
          return false;
      }
  }
  return true;
 }
 vector<string> findWords(vector<string>& words) {
     vector<string> v;
     for(int i = 0 ; i < words.size() ;i++)
     {
         if(checkrow(words[i]))
         {
             v.push_back(words[i]);
         }
     }
    return v;

 }

 int main(int argc,char** argv){
     int n;
     cin>>n;

     vector<string> words(n);
     for(int i=0;i<n;i++)
         cin>>words[i];

     vector<string>res;
     res= findWords(words);
     for(int i=0;i<res.size();i++)
         cout<<res[i]<<" ";

 }
