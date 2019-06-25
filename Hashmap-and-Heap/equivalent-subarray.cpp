#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
  using namespace std;

 int val(vector<int> &arr) {
    unordered_set<int> s;
    for(int i = 0; i  < arr.size() ; i++)
    {
        s.insert(arr[i]);
    }
    int st = -1,e = 0 , c = 0,ans = 0;
    unordered_map<int,int> t;

    int k = s.size() , n = arr.size();
    for(int i = 0 ; i < n ; i++)
    {
        while(e<n && t.size() < k)
        {
            t[arr[e]]++;
            e++;
        }
        if(t.size() == k)
        {
            ans += (n-e +1);
        }
        t[arr[i]]--;
        if(t[arr[i]] == 0)
            t.erase(arr[i]);
    }
 return ans;
 }

 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for(int  i=0;i<n;i++){
         int val;
          cin>>val;
         arr.push_back(val);
     }
     cout<<val(arr);
 }
