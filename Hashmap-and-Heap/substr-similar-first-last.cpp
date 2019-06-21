#include<iostream>
#include<bits/stdc++.h>
 using namespace std;

 int count(string str) {
        unordered_map< char , int> m;
        int c = 0 ;
        for(int i = 0 ;i < str.length() ; i++)
        {
            if(m.count(str[i]))
            {
                c += m[str[i]];
            }
            m[str[i]]++;
        }
        return c + str.length();
 }

 //Don't write your code here
 int main(int argc, char** argv){
     string str;
     cin>>str;
     int ans = count(str);
     cout<<ans;
 }
