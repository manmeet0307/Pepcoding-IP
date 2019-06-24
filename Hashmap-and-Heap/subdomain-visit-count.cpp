 #include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 vector<string> splitspace(string s)
 {
     string t;
     vector<string> v;
     for(int i =0 ; i <s.length() ;i++)
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
 vector<string> splitdot(string s)
 {
     string t;
     vector<string> v;
     v.push_back(s);
     int c = 0 ;

     while(c<s.length())
     {

         while((c < s.length()) && (s[c] !='.'))
         {
             c++;
         }

         if(c!=s.length())
         { v.push_back(s.substr(c+1, s.length()-c));
            c++;}
         else
         {
             break;
         }

     }

     return v;
 }
 vector<string> subdomainVisits(vector<string> cpdomains) {
     unordered_map<string,int> m;
     for(int i = 0 ; i < cpdomains.size() ; i++)
     {
         vector<string> fp = splitspace(cpdomains[i]);
         vector<string> sp = splitdot(fp[1]);
         int f = stoi(fp[0]);
         for(int i = 0 ; i < sp.size() ; i++)
         {
             m[sp[i]] += f;
         }
     }
     vector<string> ans;
     unordered_map<string,int> :: iterator it;
     for(it = m.begin() ; it != m.end() ; it++)
     {
         string t = to_string(it->second) + " " +it->first;
         ans.push_back(t);
     }
     return ans;
 }

 int main(int argc, char** argv){

     int n;
     string sn;
     getline(cin, sn);
     n = stoi(sn);
     vector<string> cpd;
     string s;
     int i = 0;
     for(int i=0; i<n; i++) {
         string s;
         getline(cin, s);
         std::cout<<"";
         cpd.push_back(s);
     }
     vector<string> ans = subdomainVisits(cpd);
     sort(ans.begin(), ans.end());
     for(string s : ans){
         cout<<s<<" ";
     }

 }
