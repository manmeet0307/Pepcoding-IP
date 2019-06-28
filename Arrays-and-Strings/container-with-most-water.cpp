#include<iostream>
 #include<vector>
#include<bits/stdc++.h>
 using namespace std;

 int maxArea(vector<int>& height) {
  int ma = -1;
  int l = 0 , r = height.size()-1;
  while(l<=r)
  {
      if(height[l] < height[r])
      {
          int gap = (r-l);
          ma = max(ma , gap*height[l]);
          l++;
      }
      else
      {
          int gap = (r-l);
          ma = max(ma , gap*height[r]);
          r--;
      }
  }
  return ma;
 }
 int main (int argc,char**argv){
     int n;
     cin>>n;
     vector<int> height(n);
     for (int i = 0; i < height.size(); i++) {
         cin>>height[i];
     }
     cout<<maxArea(height);

 }
