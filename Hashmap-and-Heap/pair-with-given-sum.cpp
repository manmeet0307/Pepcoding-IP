#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;

 void print(vector<int>& nums1,vector<int> &nums2 ,int k){
 	 int n = nums1.size();
 	 unordered_map<char , int> m;
 	 for(int i = 0; i < nums2.size() ; i++ )
     {
         m[nums2[i]]++;
     }
     vector<pair<int,int>> v;
     for(int i= 0 ; i <nums1.size();i++)
     {
         if(m.count(k-nums1[i]))
         {
             m[k-nums1[i]]--;
             if( m[k-nums1[i]] == 0)
             {
                 m.erase(k-nums1[i]);
             }
            v.push_back(make_pair(nums1[i],k-nums1[i]));
         }
     }

     for(int i = 0 ; i < v.size() ; i++)
     {
         if(i==v.size()-1)
         {
             cout<<v[i].first<<" " <<v[i].second;
         }
         else{
            cout<<v[i].first<<" " <<v[i].second<<" , ";
         }
     }

 }

 int main(int argc,char ** argv){

     int n;
     cin>>n;
     int m;
     cin>>m;
     int k;
     cin>>k;
     vector<int> num1;
     vector<int> num2;
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         num1.push_back(a);
     }
     for(int i=0;i<m;i++){
         int a;
         cin>>a;
         num2.push_back(a);
     }

     print(num1, num2, k);
     cout<<endl;

 }
