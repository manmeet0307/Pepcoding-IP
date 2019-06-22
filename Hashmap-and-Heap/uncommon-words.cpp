#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<string> separate(string s)
{
    vector<string> v;
    int c = 0;
    string t;
    while(c < s.length())
    {
        if(s[c] == ' ' )
        {
            v.push_back(t);
            t.clear();
            c++;
            continue;
        }
        t += s[c++];
    }
    v.push_back(t);
    return v;
}
 vector<string> uncommonFromSentences(string A, string B) {
    unordered_map<string , int> m;
    vector<string> w1 = separate(A);
    vector<string> w2 = separate(B);
    for(int i = 0 ;  i  < w1.size() ; i++)
    {
        m[w1[i]]++;
    }
    for(int i = 0 ;  i  < w2.size() ; i++)
    {
        m[w2[i]]++;
    }
    vector<string> ans;
    unordered_map<string , int> :: iterator it;
    for(it = m.begin() ; it!=m.end() ; it++)
    {
        if(it->second == 1)
        {
            ans.push_back(it->first);
        }
    }
    return ans;
 }
 int main(int argc, char** argv){
     string A, B;
     getline(cin, A);
     getline(cin, B);

     vector<string> ans= uncommonFromSentences(A, B);
     sort(ans.begin(), ans.end());
     for(int i=0; i<ans.size(); i++){
         cout<<ans[i];
     }
 }
