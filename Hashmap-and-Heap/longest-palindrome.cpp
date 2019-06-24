#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 #include<string>
 using namespace std;
 //note maxodd dhundane ki zarurat nhi h, koi bhi ek pure odd ko add kardo
 int longestPalindrome(string &str) {
    unordered_map<char,int> m;
    for(int i = 0 ; i < str.length() ; i++ )
    {
        m[str[i]]++;
    }
    int res = 0;
    int maxodd = -1 , val = 0;
    unordered_map<char,int> :: iterator it;
    for(it = m.begin() ; it!= m.end() ; it++)
    {
        if(it->second % 2 !=0)
        {
            if(it->second > maxodd)
            {
                maxodd = it->second;
                val = it->first;
            }

        }
    }
    if(maxodd !=-1)
    {
        res += maxodd;
        m.erase(val);
    }
    for(int i = 0 ; i < str.length() ; i++ )
    {
        if(m.count(str[i]) && m[str[i]] % 2 == 0 )
        {
            res += m[str[i]];
            m.erase(str[i]);
        }
        else if(m.count(str[i]) && m[str[i]] % 2 != 0)
        {
            res += (m[str[i]] - 1);
            m.erase(str[i]);
        }
    }

 	return res;
 }

 int main(int argc,char** argv){
     string s;
     cin>>s;
     cout<<longestPalindrome(s)<<endl;
 }
