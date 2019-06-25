#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
void acquire(unordered_map<char,int> &m , int &e , string &str)
{
    m[str[e]]++;
    e++;
}
void release(unordered_map<char,int> &m , int &s , string &str)
{

    s++;
    m[str[s]]--;
    if(m[str[s]] == 0)
    {
        m.erase(str[s]);
    }

}
void print(string &str, int k) {
    int s = -1, e = 0 , ml = -1;
    unordered_map<char , int> m;
    while( s+1 < str.length() && e<str.length())
    {
            while(m.size() <= k)
            {
                    acquire(m,e,str);
            }

            //settle
            ml = max(ml , e-s -2);

            while(m.size() > k)
            {
                release(m,s,str);
            }
    }
    cout<<ml;
 }

 int main(int argc,char** argv){
     string s;
     cin>>s;
     int k;
     cin>>k;
     print(s,k);
 }
