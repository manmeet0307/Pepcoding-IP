#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

 int arrayNesting(vector<int> &nums) {
     //Write your code here
     vector<bool> visited(nums.size(),0);

        int ma = 0;
        for(int i = 0 ; i <  nums.size() ; i++)
        {
            if(visited[i])
                {
                  continue;}
            int c = i;
            int counter = 0;
            while(!visited[c])
            {
                visited[c] = true;
                counter++;
                c = nums[c];

            }
            ma = max(ma,counter);
        }
     return ma;
 }

 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr(n);
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
     cout<<arrayNesting(arr);
 }
