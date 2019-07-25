#include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;


 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array
 // It should print the required output
 void helper(vector<int> arr , int s , int e )
 {
     if(s> e)
     {
         return ;
     }
     if(s == e)
     {
         cout<<arr[s] << " ";
     }
     int idx = -1;
     for(int i = s ; i<=e ; i++)
     {
         if(arr[i] > arr[s])
         {
             idx = i;
             break;
         }
     }
     helper(arr ,s  + 1 , idx == -1 ? e : idx - 1 );
     if(idx != -1)
     {
         helper(arr , idx , e);
     }
 }
 void print(vector<int>& arr) {

    helper(arr , 0, arr.size() -1);
 }

 int main(int argc,char** argv) {
     int n ;
     cin>>n;
     vector<int> a;
     for (int i = 0; i <n; i++) {
         int x;
         cin>>x;
         a.push_back(x);
     }
     print(a);
 }
