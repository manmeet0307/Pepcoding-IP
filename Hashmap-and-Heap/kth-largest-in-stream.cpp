#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 vector<int> subarraysDivByK(vector<int> arr, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;
    int n = arr.size();
    vector<int> v(n);
    int i;
    for( i = 0; i < k ;i++)
    {
        pq.push(arr[i]);
        if(pq.size() < k)
        {
            v[i] = -1;
        }
        else{
            v[i] = pq.top();
        }

    }
     for(; i < n ; i++)
     {
         if(!pq.empty() && pq.top() < arr[i])
         {
             pq.pop();
             pq.push(arr[i]);
         }

         if(!pq.empty())
         {
             v[i] = pq.top();
         }
         else
         {
             v[i] = -1;
         }
     }
    return v;
 }


 int main(int argc,char** argv){

     int n,k;
     cin>>n>>k;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }

     vector<int> a = subarraysDivByK(v,k);
     for(int i = 0 ; i < a.size() ;i++)
     {
         cout<<a[i]<<" ";
     }
 }
