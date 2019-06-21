#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;

 int sumLength(vector<int> arr) {
    int n = arr.size();
    unordered_set<int> set1;
    int start = -1, e = 0;
    int ans = 0;
    while(start < n)
    {
        while(e < n && !set1.count(arr[e]) )
        {
            set1.insert(arr[e]);
            e++;
        }
        int x = set1.size();
        ans += (x*(x+1)/2);

        if(start < e )
        {
            start++;
            set1.erase(arr[start]);
//            if(start > e)
//            {
//                e = start;
//            }
        }
    }
    return ans;
 }

 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for (int i = 0; i < n; i++) {
         int val;
         cin>>val;
         arr.push_back(val);
     }
     cout<<sumLength(arr);
 }
