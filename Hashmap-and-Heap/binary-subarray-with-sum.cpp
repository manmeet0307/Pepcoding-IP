#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> A, int S) {
 int rs = S;
 unordered_map<int , int> m;
 m[0] = 1;
 int ps = 0;
 int c = 0;
 for(int i = 0;i < A.size() ; i++)
 {
      ps = ps + A[i];
      if(m.count(ps-rs))
      {
          c += m[ps-rs];
      }
      m[ps]++;
 }
 return c;
}

int main(int args,char** argv) {
          // Taking input for the array.
          int N; cin>>N;
          vector<int> array(N,0);

          for (int i = 0; i < N; i++) {
              cin>>array[i];
          }

          // Taking input for sum.
          int sum;cin>>sum;

          cout<<(numSubarraysWithSum(array, sum));
}
