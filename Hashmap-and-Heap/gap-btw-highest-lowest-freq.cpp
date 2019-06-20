#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 void findDifference(vector<int> &nums) {
     //write your code here
     unordered_map<int , int> m;
     for(int i = 0 ; i < nums.size() ; i++)
     {
         m[nums[i]]++;
     }
     unordered_map<int , int> :: iterator it;
     int minf = INT_MAX , maxf = INT_MIN;
     for( it = m.begin() ; it!= m.end() ; it++)
     {
         minf = min(minf , it->second);
         maxf = max(maxf , it->second);
     }
     cout<< maxf - minf;
 }

 int main(int argc,char** argv){

     // Input for length of array.
     int N ;
     cin>>N;

     vector<int> v;

     // Input for array elements.
     for (int i = 0; i < N; i++) {
         int a;
         cin>>a;
         v.push_back(a);
     }

     findDifference(v);
 }
