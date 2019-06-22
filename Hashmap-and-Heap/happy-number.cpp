#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 bool isHappy(int n) {
    int num = n;
    unordered_set<int> s;
    while(1)
    {
        int sum = 0;
        while(num>0)
        {
            int dig = num % 10;
            sum += pow(dig,2);
            num /= 10;
        }
        if(sum == 1 )
        {
            return true;
        }
        if(s.count(sum))
        {
            return false;
        }
        s.insert(sum);
        num = sum;
    }

 }

 int main(int argc,char** argv) {
     int N;
     cin>>N;

     if (isHappy(N)) {
         cout<<"Happy"<<endl;
     } else {
         cout<<"Not Happy"<<endl;
     }
 }
