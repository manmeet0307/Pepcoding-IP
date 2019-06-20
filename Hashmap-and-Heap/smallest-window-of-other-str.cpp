#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int smallestWindow(string s, string t) {
      unordered_set<char> set1;
      for(int i = 0 ;i < t.length() ;i++ )
      {
          set1.insert(t[i]);
      }
      int start =-1 , e = -1;
      unordered_map<char , int> m;
      while(m.size() < set1.size() )
      {
         e++;
         if(set1.find(s[e])!=set1.end())
         {
          m[s[e]]++;
         }
      }
      int bs = start, be = e;

      while(e < s.length())
      {
        while(m.size() == set1.size())
        {
             start++;
             if(m.count(s[start]))
             {
                  m[s[start]]--;
                  if(m[s[start]] == 0)
                  {
                      m.erase(s[start]);
                  }
             }
        }
          if((be - bs) > (e - start))
              {
                  be = e ;
                  bs = start  ;
              }
        while(m.size() < set1.size() )
        {
             e++;
             if(e == s.length())
             {
                 break;
             }
             if(set1.find(s[e])!=set1.end())
             {
              m[s[e]]++;
             }


        }
             if(e == s.length() && m.size()  < set1.size())
             {
                 break;
             }
            if((be - bs) > (e - start))
              {
                  be = e ;
                  bs = start + 1  ;
              }
    }
      return be - bs + 1;
}
int main(int argc, char** argv){
      string s1;
      cin>>s1;
      cout<<smallestWindow(s1, s1);
}
