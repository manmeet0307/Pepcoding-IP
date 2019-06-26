#include<bits/stdc++.h>
#include<iostream>
 #include<vector>
 using namespace std;

int mt(vector<int> &arr) {
   unordered_map<int,int> m;
   for(int i =0 ; i< arr.size() ; i++)
   {
       m[arr[i]]++;
   }
   int a = 0;
   for(int i =0 ; i< arr.size() ; i++)
   {
      if(m[arr[i]] % 2==0)
      {
          a += m[arr[i]];
      }
      else {
       m[arr[i]]--;
       a += (m[arr[i]]);
      }

       m.erase(arr[i]);
   }
   return a;
}

 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;

     // Input for array elements.
     for (int i = 0; i < n; i++) {
         int val;
         cin>>val;
         arr.push_back(val);
     }
 	 cout<<mt(arr);
 }
