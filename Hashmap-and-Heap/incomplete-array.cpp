#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int incomplete(vector<int> v) {
    unordered_set<int> s;
    int minel = INT_MAX , maxel = INT_MIN;
    for(int i =0 ;i < v.size() ; i++)
    {
        maxel = max(v[i] , maxel);
        minel = min(v[i] , minel);
        s.insert(v[i]);
    }
    return (maxel-minel +1) - s.size();

}


 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int > v;
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         v.push_back(a);
     }
     cout<<incomplete(v)<<endl;
}
