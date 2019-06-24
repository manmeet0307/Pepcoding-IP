#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 int lengthOfLongestSubstring (string &arr) {
      int n = arr.length();
      unordered_set<char> set1;
      int start = -1, e = 0;
      int ans = 0;
      while(start < n)
      {
        while(e < n && !set1.count(arr[e]) )
        {
            set1.insert(arr[e]);
            e++;
        }
        int x = (e-start-1);
        ans = max(ans , x);

        if(start < e )
        {
            start++;
            set1.erase(arr[start]);
        }
    }
    return ans;
 }

 int main(int argc,char** argv){
     string s;
     cin>>s;
     cout<<lengthOfLongestSubstring(s)<<endl;
 }
