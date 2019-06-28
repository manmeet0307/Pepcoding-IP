#include<iostream>
 #include<bits/stdc++.h>
 #include<algorithm>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array
 // It should return a boolean value.
 bool splitArray(vector<int> & nums) {
     	 unordered_map<int,vector<int>> m;
     	 int ps = 0;
     	 int n = nums.size();
     	 vector<int> psa(n,0);
     	 psa[0] = nums[0];
     	 for(int i = 1 ; i  < n ;i++)
         {
             psa[i] = psa[i-1] + nums[i];
         }

     	 for(int i = 1 ; i <=n-6;i++ )
         {
            if(m.count(psa[i-1]))
            {
                m[psa[i-1]].push_back(i);
            }
            else{
                vector<int> t;
                t.push_back(i);
                m[psa[i-1]] = t;
            }
         }
         int index = -1,kindx;
         for(int k = n-2;k>=5;k--)
         {
             if(m.count(psa[n-1] - psa[k]))
             {
                 vector<int> t = m[psa[n-1] - psa[k]];
                 kindx = k;
                 index = t[0];
                 break;
             }
         }
         int k = kindx;
         if(index==-1) return false;
         for(int j = index+2;j<=k-2;j++)
         {
             int s1 = psa[j-1] - psa[index];
             int s2 = psa[k-1] - psa[j];
             if(s1 == s2)
             {
                 return true;
             }
         }
         return false;
 }
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> nums(n);
     for(int i=0;i<n;i++){
         cin>>nums[i];
     }
     bool res=splitArray(nums);
     if(res==true){
         cout<<"true"<<endl;
     }else{
         cout<<"false"<<endl;
     }
 }
