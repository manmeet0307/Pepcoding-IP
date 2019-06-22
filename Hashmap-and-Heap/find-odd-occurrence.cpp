#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;

  // This is a functional problem. You have to complete this function.
 // It takes as input the an array of integers. It should return
 // the number occurring odd number of times.

 int solve(vector<int>& arr) {
     // write your code here.
     int xor1 = 0;
     for(int i = 0 ; i < arr.size();i++)
     {
         xor1 ^= arr[i];
     }
     return xor1;
 }

 //Don't make any changes here

 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     int res = solve(v);
     cout<<res<<endl;

 }
