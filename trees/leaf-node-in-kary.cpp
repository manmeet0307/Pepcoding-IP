#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 // This is a functional problem. You have to complete this function.
 // It takes as input K and M(height of the tree). It should return the number of leaf nodes.
 // return pow(k , m)
 int mod = pow(10,9) + 7;
 long kAryTree(int k, int height) {
     if(height == 0)
     {
         return 1;
     }
     long ans = kAryTree(k, height/2);
     if(height % 2 == 0)
     {
        return ((ans%mod) * (ans %mod))%mod;
     }
     else{
        return ((ans)%mod * (ans)%mod *( k)%mod)%mod;
     }

 }

 int main(int argc,char** argv) {
     int K ;
     cin>>K;
     int M ;
     cin>>M;
     cout<<kAryTree(K , M)<<endl;
 }
