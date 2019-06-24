#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
 using namespace std;

 void solve(int n,vector<int>& arr,int k){
     priority_queue<int , vector<int> , greater<int>> pq;
     for(int i = 0 ; i < k;i++)
     {
         pq.push(arr[i]);
     }
     for(int i = k; i < arr.size();i++)
     {
         if(arr[i] > pq.top() )
         {
             pq.pop();
             pq.push(arr[i]);
         }
     }
     vector<int> a;
     while(!pq.empty())
     {
         a.push_back(pq.top());
         pq.pop();
     }
     sort(a.begin() , a.end() , greater<int>());
     for(int i = 0 ; i  < a.size();i++)
     {
         cout<<a[i]<<" ";
     }
 }

 int main(int argc,char** argv){
     int n;
     cin>>n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
         cin>>v[i];

     int k;
     cin>>k;
     solve(n,v,k);
 }
