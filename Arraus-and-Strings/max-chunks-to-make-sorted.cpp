#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 int maxChunksToSorted(vector<int> &arr) {
    vector<pair<int,int> > maxmin(arr.size());
    maxmin[arr.size()-1].first = arr[arr.size()-1];
    for(int i = arr.size()-2 ; i>=0; i--)
    {
        maxmin[i].first = min(maxmin[i+1].first , arr[i]);
    }
    maxmin[0].second = INT_MIN;
    for(int i = 1 ; i < arr.size() ;i++)
    {
        maxmin[i].second = max(maxmin[i-1].second , arr[i-1] );
    }
        int c= 0;
    for(int i = 0 ; i < arr.size();i++)
    {
        if(maxmin[i].first > maxmin[i].second)
        {
            c++;
        }
    }
 return c;
 }

 int main(int argc, char** argv){
     int n; cin>>n;
     vector<int> a(n);
     for(int i=0; i<n; i++){
         cin>>a[i];
     }
 	 cout<<maxChunksToSorted(a);
 }
