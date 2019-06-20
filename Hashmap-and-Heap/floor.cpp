#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

 vector<int> greatestSmaller(vector<int> arr) {

     set<int , greater<int>> s;
     vector<int> v(arr.size());
     unordered_set<int> s2;
     for(int i = 0; i< arr.size() ; i++)
     {
         if(s.lower_bound(arr[i]) == s.end())
         {
             v[i] = -1;
         }
         else
         {
             if(s2.count(arr[i]))
             {
                 s.erase(arr[i]);

                  if(s.lower_bound(arr[i]) == s.end())
                  {
                    v[i] = -1;
                    goto label;
                  }
             }

             v[i] = *(s.lower_bound(arr[i]));
         }
         label:
         s.insert(arr[i]);
         s2.insert(arr[i]);
     }
     return v;
 }

 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for(int i=0;i<n;i++){
         int val;
         cin>>val;
         arr.push_back(val);
     }
     for(int val : greatestSmaller(arr)){
         cout<<val<<" ";
     }
 }
