#include<iostream>
 #include<string>
 #include<unordered_map>
 using namespace std;

 char findTheDifference(string& s, string& t) {

    unordered_map<char , int> m;
    for(int i = 0 ; i < s.length() ;i++)
    {
        m[s[i]]++;
    }
     for(int i = 0 ; i < t.length() ;i++)
     {
         if(!m.count(t[i]))
            return t[i];
         m[t[i]]--;
         if(m[t[i]] == 0)
            m.erase(t[i]);
     }
 }
 //Don't make any changes here

 int main(int argc,char** argv){

     string s,t;
     cin>>s;
     cin>>t;
     cout<<findTheDifference(s,t)<<endl;
 }
