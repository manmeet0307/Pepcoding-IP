#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;

 void solve(vector<string> &str) {
     unordered_map<string , int> m;
     for(int i = 0 ; i <str.size() ;i++)
     {
         if(m.count(str[i]))
         {
             string t = str[i] + to_string(m[str[i]]);
             cout<<t<<endl;
         }
         else{
            cout<<"Verified"<<endl;
         }
         m[str[i]]++;
     }

 }

 int main(int argc,char** argv){

     int N ;
     cin>>N;
     vector<string> arr(N);
     for (int i = 0; i < N; i++) {
         cin>>arr[i];
     }

     solve(arr);
 }
