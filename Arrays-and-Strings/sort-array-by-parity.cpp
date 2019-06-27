#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }

 vector<int> sortResultEvenOdd(vector<int> &arr) {
     int i = 0;

     while (i < arr.size()) {
         if (arr[i] % 2 != 0) {
             sort(arr.begin(), arr.begin() + i);
             sort(arr.begin() + i, arr.end());
             return arr;
         }
         i++;
     }

     sort(arr.begin(), arr.end());
     return arr;

 }
 vector<int> sortArrayByParity(vector<int> &a) {
    int  iptr = 0 , jptr = 0;
    while(iptr < a.size())
    {
        if(a[iptr]%2 == 0)
        {
            swap(a[iptr],a[jptr]);
            iptr++;
            jptr++;
        }
        else
        {
            iptr++;
        }
    }
    return a;
 }

 int main(int argc, char** argv){
     int length;
     cin>>length;
     vector<int> arr(length);

     // Input for elements of array.
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }

     vector<int> result = sortArrayByParity(arr);
     vector<int> sortedResult = sortResultEvenOdd(result);
     display(sortedResult);
 }
