#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

 int threeSumClosest(vector<int>& nums, int target) {
     //Write your code here
     int result = INT_MIN , min = INT_MAX;
     sort(nums.begin() , nums.end());
     for(int i = 0 ; i < nums.size() ;i++)
     {
         int newtar = target - nums[i];
         int j = i+1 , k = nums.size() -1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if(diff == 0) return sum;
                if (diff < min) {
                min = diff;
                result = sum;
                }
                if (sum <= target) {
                j++;
                } else {
                k--;
                }
           }

        }
          return result;
 }
 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> nums(n);
     for(int i=0;i<n;i++){
         cin>>nums[i];
     }
     int k;
     cin>>k;
     int res=threeSumClosest(nums,k);
     cout<<res;

 }
