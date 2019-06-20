#include<iostream>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 class mycomp{
 public:
     bool operator()(pair<char,int> one , pair<char , int> two)
     {
         if( one.second < two.second ) return true;
         else if(one.second == two.second )
            return one.first > two.first;
         else return false;
     }
 };
 string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(int i = 0; i<s.length() ; i++)
        {
            m[s[i]]++;
        }
        priority_queue<pair<char , int> , vector<pair<char,int>> , mycomp> pq;
        unordered_map<char , int> :: iterator it;
        for(it = m.begin() ; it != m.end() ; it++)
        {
            pq.push(make_pair(it->first , it->second));
        }
        string ans;
        while(!pq.empty())
        {
            pair<char , int> temp = pq.top();
            pq.pop();
            if(temp.second == 1)
            {

            }
            else{
                pq.push(make_pair(temp.first , temp.second - 1));
            }
            ans += temp.first;
        }
        return ans;
 }

 int main(int argc, char** argv) {
     string s;
     cin>>s;
     cout<<reorganizeString(s);
 }
