#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string& s,string& p){
    int start = 0 , e =0 ;
    vector<int> v;
    unordered_map <int,int> p_fmap;
    for(int i =0;i < p.length(); i++ )
    {
        p_fmap[p[i]]++;
    }
    int mc =0 ;
    unordered_map<int,int> tmap;
    while(e < p.length())
    {
        if(p_fmap.count(s[e]) && (tmap[s[e]] < p_fmap[s[e]]))
        {
            tmap[s[e]]++;
            mc++;
        }
        else
        {
            tmap[s[e]]++;
        }
        e++;
    }
    if(mc == p.length() )
    {
        v.push_back(start);
    }
 //  cout<<"mc befor loop"<<mc<<endl;
    while(e < s.length())
    {

        /*if(e >= s.length() )
        {
            break;
        }*/
        if(p_fmap.count(s[e]) && tmap[s[e]]< p_fmap[s[e]])
        {
            mc++;
        }
        tmap[s[e]]++;
        e++;
    //    cout<< start << " "<< s[start] << " "<<p_fmap.count(s[start])<<endl;
        if((p_fmap.count(s[start]) == 1) && tmap[s[start]]<= p_fmap[s[start]])
        {
            mc--;
        }
        tmap[s[start]]-- ;
        start++;
      //  cout<<mc<<endl;
        if(mc == p.length())
        {
            v.push_back(start);
        }
    }
    return v;
  }

 int main(int argc,char** argv){
     string s;
     string p;
     getline(cin,s);
     getline(cin,p);
     vector<int> v;
     v=findAnagrams(s,p);
     cout<<"[";
     int i=0;
     for(i=0;i<v.size();i++){
         cout<<v[i];
         if(i!=v.size()-1){
             cout<<", ";
         }
     }
     cout<<"]"<<endl;

 }
