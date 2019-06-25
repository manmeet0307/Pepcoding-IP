#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> sp(string m)
{
    vector<string> v;
   string t;
    for(int i = 0 ; i <  m.length() ;i++)
    {
        if(m[i] == ' ')
        {
            v.push_back(t);
            t.clear();
            continue;
        }
        t += m[i];
    }
    v.push_back(t);
    return v;
}
 bool wordPattern(string &pattern, string &b) {
    unordered_map<char,string> m ;
    vector<string> str = sp(b);
    for(int i =0 ; i < pattern.size() ; i++)
    {

        if( m.count(pattern[i]) == 0)
        {
            m[pattern[i]] = str[i] ;
        }
        else
        {
            if(m[pattern[i]] != str[i] )
            {
                return false;
            }
        }
    }
    unordered_map<string,char> m2;
    for(int i =0 ; i < str.size() ; i++)
    {

        if( m2.count(str[i]) == 0)
        {
            m2[str[i]] = pattern[i] ;
        }
        else
        {
            if(m2[str[i]] != pattern[i] )
            {
                return false;
            }
        }
    }
    return true;
}


 int main(int argc, char** argv){
     string pattern, str;
     getline(cin,pattern);
     getline(cin,str);

     if(wordPattern(pattern,str)){
         cout<<"true";
     }else{
         cout<<"false";
     }
 }
