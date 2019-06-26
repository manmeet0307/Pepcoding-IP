#include<iostream>
#include<bits/stdc++.h>
using namespace std;


 void numbers(int l, int r) {

    unordered_set<int> s;
    for(int i = l ; i<= r ;i++)
    {
        s.clear();
        bool f = 1;
        int num = i;
        while(num>0)
        {
            int dig = num % 10;
             num = num / 10;
            if(!s.count(dig))
            {
                s.insert(dig);
            }
            else{
                f = 0;
                break;
            }
        }
        if(f == 1)
        {
            cout<<i<<" ";
        }
    }
 }

 int main(int argc, char** argv){
     int l, r;
     cin>>l>>r;
     numbers(l, r);
 }
