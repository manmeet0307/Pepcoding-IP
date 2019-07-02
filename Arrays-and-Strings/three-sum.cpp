#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 vector<vector<int> > threeSum(vector<int>& nums) {
   sort(nums.begin() , nums.end() );
   vector<vector<int> > ans;
    for(int i = 0 ; i < nums.size() ; i++)
    {

        int l = i+1 , r = nums.size() - 1;
        while(l<=r)
        {
            if(nums[l] + nums[r] + nums[i] < 0)
            {
                l++;
                while(l<nums.size() && nums[l] == nums[l-1])
                    l++;
            }
            else if(nums[l] + nums[r] + nums[i] > 0)
            {
                r--;
                 while(r>=0 && nums[r] == nums[r+1])
                    r--;
            }
            else
            {
                if(l==r) break;
                vector<int> temp{nums[i] , nums[l] , nums[r] };
                ans.push_back(temp);
                l++;
                while(l<nums.size() && nums[l] == nums[l-1])
                    l++;
                 r--;
                while(r>=0 && nums[r] == nums[r+1])
                    r--;
            }
        }

 while(i<nums.size() && nums[i] == nums[i+1])
            i++;
    }
      return ans;
 }


 void display(vector<vector<int> >& v){
     cout<<"[";
     for(int j=0;j<v.size();j++){
         cout<<"[";
         for(int i=0;i<v[j].size();i++){
             cout<<v[j][i];
             if(i!=v[j].size()-1){
                 cout<<", ";
             }
         }
         if(j!=v.size()-1)
             cout<<"], ";
         else
         {
             cout<<"]";
         }

     }
     cout<<"]";
 }
 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> nums(n);
     for(int i=0;i<n;i++){
         cin>>nums[i];
     }
//     vector<vector<int> >res=threeSum(nums);
//     display(res);
    sort(nums.begin() , nums.end());
    for(int i = 0 ; i < n ; i ++)
    {
        cout<<nums[i]<<" ";
    }


 }
