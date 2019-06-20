#include<iostream>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
using namespace std;
string help(string s)
{
    unordered_map<char,  int> m;
    for(int i =0 ; i < s.length() ; i++)
    {
        m[s[i]]++;
    }
    int x = 0, y = 0;
    unordered_map<char,  int> :: iterator it;
    for(it = m.begin() ; it!= m.end() ; it++)
    {
        if(((it->first-'a' + 1)%2 == 0) && (it->second % 2 ==0) )
        {
            x++;
        }
        else if(((it->first-'a' + 1)%2 != 0) && (it->second % 2 !=0) )
        {
            y++;
        }
    }
    return (x+y)%2 == 0 ? "EVEN" : "ODD";
}
 int main(){
 //write you code here
 string s;
 cin>>s;
 cout<<help(s);
 }
