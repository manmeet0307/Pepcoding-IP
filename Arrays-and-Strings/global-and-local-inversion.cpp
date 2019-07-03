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

 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array. It should return true if the number
 // of global inversions are equal to the number of local inversions, else
 // should return false.
 bool isIdealPermutation(vector<int> &A) {
     for(int i = 0 ; i < A.size() ; i++)
     {
         if(abs(i - A[i]) > 1)
            return false;
     }
     return true;
 }

 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> arr(N);

     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }

     if (isIdealPermutation(arr)) {
         cout<<"Yes"<<endl;
     } else {
         cout<<"No"<<endl;
     }

 }
