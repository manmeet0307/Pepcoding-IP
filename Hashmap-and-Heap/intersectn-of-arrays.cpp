#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

 void solve(vector<int>& a, vector<int>& b,int n, int x)
 {
   int c =0;
    unordered_map<int , int> m;
    for(int i = 0 ;i < n ; i++)
    {
        m[a[i]]++;
    }
    for(int i = 0 ;i < b.size() ; i++)
    {
        if(m.count(b[i]))
        {
            m[b[i]]--;
            c++;
            if( m[b[i]] == 0 )
            {
                m.erase(b[i]);
            }
        }
    }
    cout<<c;
 }


 int main(int argc,char** argv){
     int n ;
     cin>>n;
     vector<int> num(n);
     for (int i = 0; i < n; i++) {

         cin>>num[i];
     }
     int m;
     cin>>m;
     vector <int> num2(m);
     for (int i = 0; i < m; i++) {
         cin>>num2[i];
     }
     solve(num, num2, n, m);
 }
