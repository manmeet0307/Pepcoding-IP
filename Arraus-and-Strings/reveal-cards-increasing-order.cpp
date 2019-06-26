#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 vector<int> deckRevealedIncreasing(vector<int>& nums) {
        int n = nums.size();
        queue<int> q;
        for(int i =0 ; i < n ;i++)
        {
            q.push(i);
        }
        sort(nums.begin() , nums.end() );
        vector<int> o(n);
        int c = 0;
        while(!q.empty())
        {
            int index = q.front();
            q.pop();
            o[index] = nums[c++];
            int sendback = q.front();
            q.pop();
            q.push(sendback);
         }
         return o;
 }


 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> Input(n);
     for(int i=0;i<n;i++){
         cin>>Input[i];
     }
     vector<int> ans = deckRevealedIncreasing(Input);
     for (int i : ans) {
         cout<<i<<" ";
     }

 }
