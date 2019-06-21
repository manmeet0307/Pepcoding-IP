#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;

 // This is a functional problem. You have to complete this function.
 // It takes as input an array of integers.
 // It should return 1 or -1.

 int solve(vector<int>& arr) {
     // write your code here.
     unordered_set<int> s;
     for(int i = 0 ; i < arr.size() ; i++)
     {
         for(int j = i+1  ; j < arr.size() ; j++)
         {
             int p = arr[i] * arr[j];
             if(s.count(p))
             {
                // cout<<arr[i]<< " "<<arr[j]<<endl;
                 return 1;
             }
             s.insert(p);
         }
     }
     return -1;
 }

 //Don't make any changes here

 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     int res = solve(v);

     if (res == 1) {
         cout<<"Found"<<endl;;
     } else if (res == -1) {
         cout<<"Not Found"<<endl;
     }


 }
