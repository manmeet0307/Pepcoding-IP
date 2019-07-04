#include<iostream>
 #include<vector>
 using namespace std;

 int majorityElement(vector<int>& nums) {
     int delta = 1 , m = nums[0];
     for(int i = 1; i < nums.size() ; i++)
     {
         if(nums[i] == nums[i-1])
         {
             delta++;
         }
         else
         {
             delta--;
         }
         if(delta == 0)
         {
             m = nums[i];
             delta = 1;
         }
     }
     int n = nums.size() , f = 0;
     for(int i = 0 ; i < nums.size() ;i++)
     {
         if(nums[i] == m)
            f++;
     }
     return f == (n/2 + 1) ? m : -1;
 }


 int main(int argc,char**argv){

     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     int res=majorityElement(v);
     cout<<res<<endl;
 }
