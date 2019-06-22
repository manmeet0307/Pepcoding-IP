#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
string rethashcode(string strs)
{
          string t;
           for(int i = 0 ; i < strs.length()-1 ; i++)
           {
               int n1 = strs[i];
               int n2 = strs[i+1];
               int x = n2 - n1;
               if(x<0) x = x + 26;
                 t += to_string(x) + "*";
           }
           return t;
}
 vector<vector<string> > groupStrings(vector <string>& strs){
     unordered_map<string , vector<string>> m;
     for(int i = 0 ; i < strs.size() ;i++)
     {
         int n = strs[i].length();
         if(n==1)
         {
            if(m.count("1"))
            {
                m["1"].push_back(strs[i]);
            }
            else
            {
                vector<string> v(1,strs[i] + "");
                m["1"] = v;
            }
         }
         else
         {
             string t = rethashcode(strs[i]);
            if(m.count(t))
            {
                m[t].push_back(strs[i]);
            }
            else
            {
                vector<string> v(1,strs[i] + "");
                m[t] = v;
            }
         }

     }
     unordered_map<string , vector<string>> :: iterator it;
     vector<vector<string>> ans;
     for(it = m.begin() ; it!=m.end() ; it++)
     {
         sort((it->second).begin() , (it->second).end() );
         ans.push_back(it->second);
     }
return ans;
 }

 void display(vector<vector<string> > &v){
     for(int i=0;i<v.size();i++){
         for(int j=0;j<v[i].size();j++){
             cout<<v[i][j]<<" ";
         }
         cout<<endl;
     }
 }
 //function to sort the lists
 bool sortcol( const vector<string>& l1,
                const vector<string>& l2 ) {

     if (l1.size() != l2.size()) {
         return l2.size()<l1.size();
     } else {
         if(l1.size()==0){
             return false;
         }else{
             return l1[0]<l2[0];
         }
     }

 }
 int main(int argc,char ** argv){

     int n;
     cin>>n;
     vector<string> strs;
     for(int i=0;i<n;i++){
         string a;
         cin>>a;
         strs.push_back(a);
     }

     vector<vector<string> > res;
     res=groupStrings(strs);
     for(vector<string> v:res){
         sort(v.begin(),v.end());
     }
     sort(res.begin(),res.end(),sortcol);
     display(res);
 }
