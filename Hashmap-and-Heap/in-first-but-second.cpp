#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 void solve(vector<long>& a, vector<long>& b,int n, int m)
 {
     unordered_map<int , int> s;
     for(int i = 0 ; i < a.size() ; i++)
     {
         s[a[i]]++;
     }
     for(int i = 0 ; i < b.size() ; i++)
     {
         s.erase(b[i]);
     }
     unordered_set<int> :: iterator it;
     vector<int> v;//    sort(v.begin() , v.end());
        for(int i = 0 ; i < a.size();i++ )
        {
            if(s.count(a[i]))
            {
                v.push_back(a[i]);
                s[a[i]]--;
                if(s[a[i]]==0)
                {
                  s.erase(a[i]);
                }
            }
        }
     for( auto i : v)
     {
         cout<<i << " ";
     }
 }


 int main(int argc,char** argv){
     int n ;
     cin>>n;
     vector<long> num(n);
     for (int i = 0; i < n; i++) {

         cin>>num[i];
     }
     int m;
     cin>>m;
     vector <long> num2(m);
     for (int i = 0; i < m; i++) {
         cin>>num2[i];
     }
     solve(num, num2, n, m);
 }
