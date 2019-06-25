#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;

 void solve(vector<int>& arr,int n,int k){
    unordered_map<int,int> m;
    for(int i = 0;i<arr.size() ;i++)
    {
        m[arr[i]]++;
    }
    int c =0 ;
    for(int i = 0;i<arr.size() ;i++)
    {
        if(m[arr[i]] == 1 && c == k-1)
        {
            cout<<arr[i];
            return ;
        }
        else if(m[arr[i]] == 1)
        {
            c++;
            m.erase(arr[i]);
        }
    }
        cout<<"-1";
 }

 int main(int argc,char** argv){
     int n;
     cin>>n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
         cin>>v[i];

     int k;
     cin>>k;
     solve(v,n,k);
 }
