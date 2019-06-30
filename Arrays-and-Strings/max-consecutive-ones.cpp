#include<iostream>
 #include<vector>
 using namespace std;

 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
 	 }
     cout<<endl;
 }

 int findMaxConsecutiveOnes(vector<int> &nums) {

     int e = -1 ,ma = -1,counter = 0;
     for(int i = 0 ; i < nums.size() ; i++)
     {
         while(e+1 <= nums.size() && counter <= 1)
         {
             e++;
             if(nums[e] == 1)
             {

             }
             else
             {

                 counter++;
             }
         }
         ma = max( ma, e-i);
         if(nums[i] == 0)
         {
             counter--;
         }
     }
     return ma;
 }

 int main(int argc, char** argv){
     int N; cin>>N;
     vector<int> arr1(N);
     for (int i = 0; i < arr1.size(); i++) {
         cin>>arr1[i];
     }
     int result = findMaxConsecutiveOnes(arr1);
     cout<<result;

 }
