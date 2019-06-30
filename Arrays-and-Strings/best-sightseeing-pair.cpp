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

 int maxScoreSightseeingPair(vector<int> &A) {
    int maxi = -1,maxj = -1,indx;

    for(int j = 0 ; j < A.size() ; j++)
    {
        maxj = max(maxj , maxi + A[j] - j);
        maxi = max(maxi , A[j] + j);
    }
    return maxj;
 }

 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> arr(N);
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
     cout<<maxScoreSightseeingPair(arr);
 }
