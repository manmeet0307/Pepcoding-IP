#include<iostream>
 #include<vector>
 using namespace std;
 int getindex(vector<int> nums , int i)
 {
     int n = nums.size();
     if( (i + nums[i]) >=0 )
     {
         return (i % n + nums[i] % n) % n;
     }
     else
     {
         return (n + (i%n + nums[i]%n )) % n;
     }
 }
 bool circularArrayLoop(vector<int>& nums) {
     vector<bool> visited(nums.size(),0);
     int n = nums.size();
     for(int i = 0 ; i < n ; i++)
     {
         int fast = i , slow = i;
         int count = 0;
        while(nums[fast]*nums[slow] >= 0 && nums[getindex(nums,fast)] * nums[slow] >=0 && visited[fast]== false )
        {
            if(fast == slow && count != 0)
            {
                if(getindex(nums,slow)==fast)
                {
                    break;
                }
                return true;
            }
            fast = getindex(nums , getindex(nums,fast));
            slow = getindex(nums,slow);
            count++;
        }

        fast = i;
        slow = i;
        while(nums[fast]*nums[slow] >= 0 && visited[fast] == false)
        {
          visited[fast] = true;
          fast = getindex(nums,fast);
        }

     }
     return false;
 }

 int main (int argc,char**argv){
     int n;
     cin>>n;
     vector<int> nums(n);
     for (int i = 0; i < nums.size(); i++) {
         cin>>nums[i];
     }
     string res=circularArrayLoop(nums)?"true":"false";
     cout<<res;
 }
