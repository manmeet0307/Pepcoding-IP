#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 vector<int> plusOne(vector<int>& digits) {
    vector<int> a;
    reverse(digits.begin() , digits.end());
    int c =1;
    for(int i = 0 ; i < digits.size() ;i++)
    {
        a.push_back((digits[i] + c )%10);
        c = (digits[i] + c )/10;
    }
    if(c==1)
        a.push_back(c);
    reverse(a.begin() , a.end());
    return a;
 }

 //Don't make any changes here.
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> Input(n);
     for(int i=0;i<n;i++){
         cin>>Input[i];
     }
     vector<int> ans = plusOne(Input);
     for (int i : ans) {
         cout<<i<<" ";
     }

 }
