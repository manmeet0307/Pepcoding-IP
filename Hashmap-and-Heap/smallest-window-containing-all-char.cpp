#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string smallestWindow(string s, string t) {
      unordered_map<char,int> map1;
      unordered_map<char , int> m;
      for(int i = 0 ;i < t.length() ;i++ )
      {
          map1[t[i]]++;
      }
      int start =0 , e = 0;
      int mc = 0;
      int bs = 0, be = s.length()-1;
      //cout<<e << " "<<s.length();
      while( (e<s.length()))
      {
        while(mc < t.length())
        {

            if(e==s.length()) {cout<<" yo " ;break;}
            if(map1.count(s[e]) && m[s[e]] < map1[s[e]])
            {
                cout<<" mc" << mc<<endl;
                mc++;
                m[s[e]]++;
            }
            else if(map1.count(s[e]))
            {
                m[s[e]]++;
            }
            e++;
        }
       // cout<< mc << " " << e <<" " << start<<endl;
        if(e == s.length() && mc!=t.length())break;
        if((be - bs) > (e- start))
        {
            bs = start ;
            be = e-1;
        }
        while(mc == t.length())
        {
            if(map1.count(s[start]) && m[s[start]] <= map1[s[start]])
            {
                mc--;
                m[s[start]]--;
                if(m[s[start]]==0)
                {
                    m.erase(s[start]);
                }
            }
            else if(map1.count(s[start]))
            {
                m[s[start]]--;
                if(m[s[start]]==0)
                {
                    m.erase(s[start]);
                }
            }
            start++;
        }
     //   cout<<endl<<endl<<bs<<bs<<endl;
        if((be - bs) > ( e - start))
        {
            bs = start - 1 ;
            be = e - 1;
        }
      }
cout<<"bs = " <<bs << " be = "<<be<<endl;
      string ans;
      for(int i = bs; i<=be;i++)
      {
          ans += s[i];
      }
      return ans;
}
int main(int argc, char** argv){
      string s1,s2;
      cin>>s1>>s2;
      cout<<smallestWindow(s1, s2);
}
