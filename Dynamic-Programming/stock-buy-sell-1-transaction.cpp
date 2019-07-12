#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;


 int maxProfit(vector<int> &prices) {
     int minel = INT_MAX , mgap = INT_MIN;
     for(int i = 0 ; i < prices.size() ; i++)
     {
         minel = min(minel,prices[i]);
         mgap = max(mgap , prices[i] - minel );
     }
     return mgap;
 }

 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> prices(n);
     for (int i = 0; i < n; i++){
         cin>>prices[i];
     }
     cout<<maxProfit(prices);
 }
