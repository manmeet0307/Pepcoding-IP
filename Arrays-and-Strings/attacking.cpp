#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

 int findPoisonedDuration(vector<int> & timeSeries, int duration) {

     int s = timeSeries[0], e = timeSeries[0] + duration;
     int c = 0;
     for(int i = 1 ; i < timeSeries.size() ; i++)
     {

         if( timeSeries[i] < e)
         {
             e = timeSeries[i] + duration;
         }
         else
         {
            c += (e-s);
            s = timeSeries[i];
            e = timeSeries[i] + duration;
         }
     }
     c += (e-s);
     return c;
 }

 int main(int argc,char** argv){
     int n;
     cin>>n;
     int k ;
     cin>>k;
     vector<int> timeseries(n);
     for (int i = 0; i < n; i++) {
         cin>>timeseries[i];
     }
     cout<<findPoisonedDuration(timeseries, k)<<endl;
 }
