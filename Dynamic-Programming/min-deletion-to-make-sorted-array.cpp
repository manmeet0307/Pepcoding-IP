#include<iostream>
#include<bits/stdc++.h>
 #include<vector>
 #include<algorithm>
 using namespace std;

 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array and its length
 // It should print the required output

 void mindeletions(vector<int>& a, int n)
 {
     int lis[n],ml = 0;
     for(int i=0;i<n;i++)
    {
        lis[i] = 1;
        for(int x= i-1;x>=0;x--)
        {
            if(a[x] < a[i])
            {
                lis[i] = max(lis[i] , lis[x] + 1);
            }
        }
        ml = max(ml , lis[i]);
    }
     cout<<(n - ml);
 }
 int main(int argc,char**argv){

     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }

     mindeletions(v,n);
 }
