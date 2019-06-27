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

 vector<int> sortedSquares(vector<int> &A) {
    vector<int> v(A.size());
    int c = A.size()-1;
    int l = 0 , r=A.size()-1;
    while(l<r)
    {
        if((A[l] * A[l]) < (A[r] * A[r]))
        {
            v[c--] = A[r] * A[r];
            r--;
        }
        else
        {
            v[c--] = A[l] * A[l];
            l++;
        }
    }
  return v;
 }

 int main(int argc, char** argv){
     int length;
     cin>>length;
     vector<int> arr(length);

     // Input for elements of array.
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }

     vector<int> result = sortedSquares(arr);
     display(result);

 }
