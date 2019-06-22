#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 vector<int> intersect(vector<int>& a, vector<int>& b)
 {
     unordered_map<int , int> m;
    vector<int> v;
    for(int i = 0 ;i < a.size() ; i++)
    {
        m[a[i]]++;
    }
    for(int i = 0 ;i < b.size() ; i++)
    {
        if(m.count(b[i]))
        {
            m[b[i]]--;
            v.push_back(b[i]);
            if( m[b[i]] == 0 )
            {
                m.erase(b[i]);
            }
        }
    }
    return v;
 }


 int main(int argc,char** argv){
     int n ;
     cin>>n;
     vector<int> num1(n);
     for (int i = 0; i < n; i++) {

         cin>>num1[i];
     }
     int m;
     cin>>m;
     vector <int> num2(m);
     for (int i = 0; i < m; i++) {
         cin>>num2[i];
     }

     vector<int> res=intersect(num1, num2);
     for(int i=0;i<res.size();i++)
         cout<<res[i]<<" ";
 }
