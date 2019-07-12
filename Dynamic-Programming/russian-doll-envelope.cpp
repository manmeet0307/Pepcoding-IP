#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 int maxEnvelopes(vector<vector<int> >& envelopes) {
     //Write your code here
     vector<pair<int,int> > v(envelopes.size());
     for(int i=0;i< envelopes.size() ;i++)
     {
         v[i] = make_pair(envelopes[i][0] , envelopes[i][1]);
     }
     sort(v.begin() , v.end());
    int n = envelopes.size();
     int lis[n] ;
     int mlis = 1;
     for(int i=0;i<n;i++)
     {
         lis[i] = 1;
     }
     for(int i=1;i<n;i++)
     {
         for(int x = i-1 ;x >=0 ; x--)
         {
             if(v[x].second < v[i].second )
             {
                 lis[i] = max(lis[i] , lis[x] + 1);
             }
         }
          mlis = max(mlis , lis[i]);
     }
    for(int i=0;i<n;i++)
    {
        cout<<"pair array " <<v[i].first<<" " << v[i].second<<endl;
        cout<<"lis: "<<lis[i] <<endl;
    }
     return mlis;
 }

 int main(){
     int r;
     cin>>r;
     vector<vector<int> > envelopes(r,vector<int>(2));
     for(int i=0;i<r;i++){
         for(int j=0;j<2;j++){
             cin>>envelopes[i][j];
         }
     }
     cout<<maxEnvelopes(envelopes)<<endl;
 }
