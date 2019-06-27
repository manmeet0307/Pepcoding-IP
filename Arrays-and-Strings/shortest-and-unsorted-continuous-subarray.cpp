#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 //min - first , max - second
 int findUnsortedSubarray(vector<int> &a) {
     vector<pair<int,int>> v(a.size());
     v[a.size() - 1].first = a[a.size()-1];
     v[0].second = a[0];
     for(int i = a.size()-2;i>=0;i--)
     {
         v[i].first = min(a[i] , v[i+1].first);
     }
     for(int i = 1 ;i < a.size() ; i++)
     {
         v[i].second = max(a[i],v[i-1].second);
     }
     int l = 0 , r = 0;
     for(int i= 0 ; i < v.size() ; i++)
     {
         if(v[i].first != v[i].second)
         {
             l = i;
             break;
         }
     }
      for(int i = a.size()-1;i>=0;i--)
      {
         if(v[i].first != v[i].second)
         {
             r = i;
             break;
         }
      }
      if(r==0 && l==0) return 0;
      return r-l+1;
 }

 int main(int argc, char** argv){
     int length;
     cin>>length;
     vector<int> arr(length);

     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }

     cout<<findUnsortedSubarray(arr);

 }
