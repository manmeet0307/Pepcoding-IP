#include<iostream>
 #include<vector>
 using namespace std;

 // function to display an array.
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 int maxProfit(vector<int> &A) {
     int minp = INT_MAX , profit = 0;
     for(int i = 0 ; i < A.size()-1 ; i++)
     {

//         if(buy==true && A[i+1] < A[i])
//         {
//            mp += A[i] - buyprice;
//            buy = false;
//         }
//
//          if(A[i+1] > A[i] && buy==false)
//         {
//             buy = true;
//             buyprice = A[i];
//
          if(A[i] > minp)
          {
              profit += (A[i]-minp);
          }
          minp = A[i];
     }
     return profit;
 }

 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr(n);
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }

     cout<<maxProfit(arr);
 }
