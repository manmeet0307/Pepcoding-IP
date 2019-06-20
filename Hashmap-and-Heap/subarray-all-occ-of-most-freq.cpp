#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 class helper{
 public :
     int freq , start , e;
     helper(int x ,int y, int z)
     {
         freq = x ;
         start = y ;
         e = z;
     }
     helper(){
     }

 };
 void subarrAllOcc(vector<int> arr) {
     unordered_map< int, helper> m;
     int bfs , bfe , bf = INT_MIN;
     for(int i = 0 ; i < arr.size() ; i++)
     {
         if(m.count(arr[i]))
         {
             helper h = m[arr[i]];
             m[arr[i]] = helper(++h.freq , h.start , i);
         }
         else
         {
           m[arr[i]] = helper(1 , i , i);
         }
         if(bf < m[arr[i]].freq)
         {
             bf =  m[arr[i]].freq;
             bfs = m[arr[i]].start;
             bfe = m[arr[i]].e;
         }
         else if((bf == m[arr[i]].freq )&& (bfe - bfs) >(m[arr[i]].e- m[arr[i]].start))
         {
             bf =  m[arr[i]].freq;
             bfs = m[arr[i]].start;
             bfe = m[arr[i]].e;
         }
     }

     for(int i = bfs ;i <= bfe ; i++)
     {
         cout<<arr[i]<<" ";
     }
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
     subarrAllOcc(arr);
 }
