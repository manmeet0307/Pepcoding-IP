#include<iostream>
 #include<string>
 #include<bits/stdc++.h>
 #include<vector>
 using namespace std;

 int countPrimes(int n) {
   bool sieve[n];
   memset(sieve , 1 , sizeof(sieve));
   sieve[0] = 0;
   sieve[1] = 0;
   for(int i = 2 ; i <= sqrt(n) ; i++)
   {
       for(int j = 2 ; i * j < n ; j++)
       {
           sieve[i*j] = 0;
       }
   }
    int c =0 ;
    for(int i = 0 ; i < n ; i++ )
    {
        if(sieve[i])
            c++;
    }
    return c;
 }

 int main(int argc,char** argv){


     int N ;
     cin>>N;
     cout<<countPrimes(N)<<endl;
 }
