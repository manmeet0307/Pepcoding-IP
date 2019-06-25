#include<bits/stdc++.h>
#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>

 using namespace std;

 bool issame(const vector<int> v)
 {
     bool f = 1;
     int p = v[0];
     for(int i = 1; i <v.size();i++)
     {
         if(p != v[i])
         {
             return false;
         }
     }
     return true;
 }
 bool isFrequencyEqual(string &str)
 {
    unordered_map<char,int> m;
     for(int i = 0 ; i <str.length() ;i++)
     {
         m[str[i]]++;
     }
     unordered_map<char , int> :: iterator it;
     vector<int> v;
     for(it= m.begin() ;it!= m.end() ;it++)
     {
            v.push_back(it->second);
     }
     sort(v.begin() , v.end());
     int mf = v[v.size() -1];

     if(v[0] == 1  && v[v.size()-1] == 1 ){
      v.erase(v.begin());

      if(issame(v))
      {
          return true;
      }
      else
        return false;
     }
     if(issame(v))  return false;
     v[v.size()-1]--;
     if(issame(v)) return true;

     return false;
 }


 int main()
 {
     string s;
     cin >> s;

     if (isFrequencyEqual(s))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }

     return 0;
 }
