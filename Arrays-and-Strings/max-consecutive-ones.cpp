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

 int findMaxConsecutiveOnes(vector<int> &nums) {


 }

 int main(int argc, char** argv){
     int N; cin>>N;
     vector<int> arr1(N);

     for (int i = 0; i < arr1.size(); i++) {
         cin>>arr1[i];
     }
     int result = findMaxConsecutiveOnes(arr1);
     cout<<result;

 }
