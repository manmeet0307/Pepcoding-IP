#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> v(nums.size());
    for(int i = 0 ;i < nums.size() ; i++)
    {
        int p1 = 1 , p2 = 1;
        for(int x = 0; x < i ; x++)
        {
            p1 *= nums[x];
        }
        for(int x = i+1; x < nums.size() ; x++)
        {
            p2 *= nums[x];
        }
        v[i] = p1*p2;
    }
    return v;
 }

  int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> Input(n);
     for(int i=0;i<n;i++){
         cin>>Input[i];
     }
     vector<int> ans = productExceptSelf(Input);
     for (int i : ans) {
         cout<<i<<" ";
     }

 }
