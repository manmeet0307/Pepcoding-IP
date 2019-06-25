#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int countOfSubstringWithKOnes(string s, int k)
 {
        unordered_map<int,int> m ;
    m[0] = 1;
        int c = 0 , ps = 0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            ps += (s[i] - 48);

            if(m.count(ps-k))
            {
                c += m[ps-k];

            }
            m[ps]++;
        }
        return c;
 }

 int main(int argc, char** argv){
     string s;
     cin>>s;
     int K;
     cin>>K;

     cout<<countOfSubstringWithKOnes(s, K);
 }
