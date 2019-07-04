#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 vector<string> generatePossibleNextMoves(string &s) {
     vector<string> v;
     for(int i = 0 ; i < s.length()-1 ; i++)
     {
         if(s[i] == '+' && s[i+1] == '+')
         {
             string temp = s;
             temp[i]= '-';
             temp[i+1] = '-';
             v.push_back(temp);
         }
     }
     return v;
 }

 int main(int argc, char** argv){
     string s;
     cin>>s;
 	 vector<string> res = generatePossibleNextMoves(s);
     cout<<"[";
 	 for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }
