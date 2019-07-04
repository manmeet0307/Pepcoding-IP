#include<iostream>
 #include<vector>
 using namespace std;

 void rotate(vector<int> &a, int k) {
     k = k % a.size();
     vector<int> be;
     int n = a.size();
     for(int i = n-k ;i < n ; i++)
     {
         be.push_back(a[i]);
     }
     for(int i = n-k-1 ;i >=0 ;i--)
     {
         a[i+k] = a[i];
     }
     for(int i = 0 ; i <  k ; i++)
     {
         a[i] = be[i];
     }
 }

 int main(int argc, char** argv){
     int n, k;
     cin>>n>>k;
     vector<int> arr(n);
     for (int i = 0; i < n; i++) {
         cin>>arr[i];
     }
     rotate(arr, k);
     for (int v : arr)
         cout<<v<<" ";
 }
