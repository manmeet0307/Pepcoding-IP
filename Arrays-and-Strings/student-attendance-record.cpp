#include<iostream>
#include<bits/stdc++.h>
 using namespace std;
 bool checkRecord(string &s) {

    int counta = 0, countl = 0,countcl = 0;
    for(int i = 0 ; i< s.length() ;i++)
    {
        if(s[i]=='A')
        {
            counta++;
            if( counta >1)
                return false;
        }
        else if(s[i]=='L')
        {
            while(s[i++] == 'L')
            {
                countl++;
            }
            i--;
            if(countl>2)
                return false;
            if(countl>1)
            countcl++;
            countl = 0;
            if( countcl > 2 )
            {
                return false;
            }
        }
    }
    return true;
 }

 int main(int argc, char** argv){
     string S;
     cin>>S;

     if (checkRecord(S)) {
         cout<<"Yes";
     } else {
         cout<<"No";
     }
 }
