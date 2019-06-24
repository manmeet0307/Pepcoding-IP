#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 //make vector pair of indexes
 // l-r kheldo

 vector<int> twoSum(vector<int> nums, int target) {
    vector<int> v;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        for(int j = 0 ; j < nums.size();j++)
        {
            if(nums[i] + nums[j] == target && i!=j)
            {
                v.push_back(i);
                v.push_back(j);
                return v;
            }
        }
    }
    return v;
 }

 int main(int argc, char** argv){
     vector<int> nums;
     int n;
     cin>>n;
     for (int i = 0; i < n; i++) {
         int val;
         cin>>val;
         nums.push_back(val);
     }
     int target;
     cin>>target;
     vector<int> res = twoSum(nums, target);
     cout<<"[";
     for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }
