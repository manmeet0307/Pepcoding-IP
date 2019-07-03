#include<iostream>
 #include<vector>
 using namespace std;


 int Jump(vector<int> &nums) {
   vector<int> dp(nums.size());
   int n = nums.size();
   dp[n-1] = 0;
   nums[n-2] == 0 ? dp[n-2] = INT_MAX : dp[n-2] = 1;
   for(int i = n-3 ; i>=0 ; i--)
   {
       int maxjump = nums[i];
       int tojump = INT_MAX;
       for(int x = i+1 ; x  <= i+maxjump && x < n ; x++ )
       {
           if(dp[x] == INT_MAX) continue;
           tojump = min(tojump , dp[x] + 1);
       }
       dp[i] = tojump;
   }
    return  dp[0];
 }


 int main(int argc,char**argv){

     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }

     int res=Jump(v);
     cout<<res<<endl;
 }
