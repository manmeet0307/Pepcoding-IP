#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<string> splitstr(string s)
{
    int c =0;
    vector<string> v;
    string t;
    for(int i =0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            v.push_back(t);
            t.clear();
            continue;
        }
        t += s[i];
    }
    v.push_back(t);
    return v;
}
vector<string> splitkey(string s)
{
    vector<string> r(2);
    int c =0;
    string t;
    while(s[c]!='(')
    {
        t += s[c];
        c++;
    }
    c++;
    r[0] = t;
    t.clear();
    while(s[c]!=')')
    {
        t += s[c];
        c++;
    }
    r[1] = t;
    return r;
}
 vector<vector<string > > findDuplicate(vector<string>& paths){

    unordered_map<string , vector<string>> m;
    for(int i =0 ;i< paths.size() ;i++)
    {
        string curr = paths[i];
        vector<string> r = splitstr(curr);
        for(int i =1 ; i< r.size() ; i++)
        {
            vector<string> sepkey =  splitkey(r[i]);
            m[sepkey[1]].push_back(r[0] +"/" + sepkey[0]);
        }
    }

    unordered_map<string , vector<string>> :: iterator it;
    vector<vector<string>> ans;
    for(it = m.begin() ; it!=m.end() ; it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}


   int main(int argc, char** argv){
       string n;
       getline(cin,n);
       int N = stoi(n);
       vector<string> paths;
       for(int i=0;i<N;i++){
           string s;
          getline(cin, s,'\n');
           paths.push_back(s);
      // cout<<s<<" "<< i;
       }

//  vector<string> ans = splitkey("1.txt(abcd)");
//  cout<<ans[0]<<endl<<ans[1];

       vector<vector < string > > ans=findDuplicate(paths);
       for(int i=0;i<ans.size();i++){
           cout<<"[";
           for(int j=0;j<ans[i].size();j++){
               cout<<ans[i][j];
               if(j!=ans[i].size()-1){
                   cout<<", ";
               }
           }
           cout<<"]"<<endl;
       }
   }

