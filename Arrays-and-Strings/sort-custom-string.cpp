#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 string customSortString(string& S,string& T) {

        unordered_map<char , int> m;
        for(int i = 0 ; i < T.size() ;i++)
        {
            m[T[i]]++;
        }
        string r;
        for(int i = 0 ; i < S.length() ; i++)
        {
            if(m.count(S[i]))
            {
              int f = m[S[i]];
              for(int x = 0 ; x < f; x++)
              {
                  r += S[i];
              }
              m.erase(S[i]);
            }
        }
        for(char a =  'a' ; a <= 'z' ; a++)
        {
            if(m.count(a))
            {
                r += a;
            }
        }
        return r;
 }
 int main (int argc,char**argv){
     string S,T;
     cin>>S>>T;
     string res=customSortString(S,T);
     cout<<res;


 }
