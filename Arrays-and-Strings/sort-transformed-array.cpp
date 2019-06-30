#include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array and 3 integers
 // It should return an integeral array
 int calc(int x , int a, int b, int c )
 {
     return a*pow(x,2) + b * x + c;
 }
 vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
     int n = nums.size();
     vector<int> ans(n);
     int c1 = n-1;
     int l = 0 , r = n-1;
     while(l<=r)
     {
       //  cout<<nums[l]<<" "<< nums[r]<<endl;
       //  cout<<calc(nums[l] , a , b, c)<<" "<<calc(nums[r] , a , b, c)<<endl;
         if(calc(nums[l] , a , b, c) < calc(nums[r] , a , b, c))
         {
             ans[c1--] = calc(nums[r] , a , b, c);
             r--;
         }
         else
         {
             ans[c1--] = calc(nums[l] , a , b, c);
             l++;
         }
     }
     return ans;
 }


 int main(int argc,char** argv){
         int n;
         cin>>n;
         vector<int> nums(n);
         for(int i=0;i<n;i++){
             cin>>nums[i];
         }
         sort(nums.begin(),nums.end());
         int a,b,c;
         cin>>a>>b>>c;
         vector<int> res;
         res=sortTransformedArray(nums, a, b, c);
         for(int i=0;i<res.size();i++)
             cout<<res[i]<<" ";
 }
