#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

 // -----------------------------------------------------
     // This is a functional problem. Only this function has to be written.
     // This function takes as input the head of the linked list.
     // It should return the head of the modified list.

 vector<vector<int>> fourSum(vector<int> &nums, int target)
 {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        for(int i =0 ; i<nums.size()-3 ; i++)
        {
            for(int j =i+1; j<nums.size()-2 ;j++)
            {
                    int l = j+1 , r = nums.size()-1;
                    while(l<r)
                    {
                      if(nums[i] +nums[j] + nums[l] + nums[r] < target)
                      {
                          l++;
                      }
                      else if(nums[i] +nums[j] + nums[l] + nums[r] > target)
                      {
                          r--;
                      }
                      else
                      {
                        vector<int> t{nums[i] , nums[j] , nums[l] , nums[r]};
                        ans.push_back(t);
                        l++;
                        r--;
                      }
                    }
            }
        }
        return ans;
 }

 int main(int args, char **argv)
 {
     int n, target;
     cin >> target >> n;
     vector<int> nums(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> nums[i];
     }

     vector<vector<int>> list = fourSum(nums, target);
     cout << "[";
     for (int i = 0; i < list.size(); i++)
     {
         cout << "[";
         for (int j = 0; j < list[i].size(); j++)
         {
             if (j == list[i].size() - 1)
                 cout << list[i][j];
             else
                 cout << list[i][j] << ",";
         }
         if (i == list.size() - 1)
             cout << "]";
         else
             cout << "],";
     }
     cout << "]";
 }
