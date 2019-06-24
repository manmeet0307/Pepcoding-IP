#include<iostream>
#include<bits/stdc++.h>
 using namespace std;
 bool isAnagram(string s, string t) {
     unordered_map<char , int> m;
    for(int i = 0 ; i < s.size();i++)
    {
        m[s[i]] = m[s[i]] + 1;
    }
    unordered_map<char ,int> :: iterator it;

    for(int i = 0 ; i < t.size();i++)
    {

        if(m.find(t[i]) == m.end())
        {
            return false;
        }
        m[t[i]]--;
        if(m[t[i]] == 0)
        {
            m.erase(t[i]);
        }
    }
    return m.size()==0 ;

 }

 int main(int argc, char** argv){
     string s, t;
     cin>>s>>t;

     if (isAnagram(s, t)) {
         cout<<"Yes";
     } else {
         cout<<"No";
     }
 }
