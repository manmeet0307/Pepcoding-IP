#include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>
 using namespace std;
 bool findTriplets(vector<int>&arr , int n)
 {
     sort(arr.begin() , arr.end());
     for(int i = 0 ; i <arr.size() ;i++)
     {
         int l = i +1 , r = arr.size() -1;
         while(l<r)
         {
             if((arr[i] + arr[l] + arr[r]) < 0)
             {
                 l++;
             }
             else if((arr[i] + arr[l] + arr[r]) > 0)
             {
                 r--;
             }
             else{
                return true;
             }
         }
     }
     return false;
 }

 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     bool res = findTriplets(v,n);
     string ans=res==1?"true":"false";
     cout<<ans;

 }
