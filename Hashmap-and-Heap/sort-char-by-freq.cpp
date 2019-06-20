#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 class mycomp
 {
 public:
    bool operator()(pair<char,int> one , pair<char,int> two)
    {
        return one.second < two.second ;
    }
 };
 string frequencySort(string s) {
     unordered_map<char , int> m;
     for(int i =0; i < s.length();i++ )
     {
         m[s[i]]++;
     }
     priority_queue<pair<char,int> ,vector<pair<char,int>> , mycomp> pq;
     unordered_map<char , int> :: iterator it;
     for(it = m.begin() ; it!=m.end() ; it++)
     {
         pq.push(make_pair(it->first , it->second));
     }
     string ans;
     while(!pq.empty())
     {
         pair<char , int> curr = pq.top();
         int f = curr.second;
         while(f--)
         {
             ans += curr.first;
         }
         pq.pop();
     }
     return ans;
 }
 int main(int argc, char** argv){
     string s;
     cin>>s;
     cout<<frequencySort(s);
 }
