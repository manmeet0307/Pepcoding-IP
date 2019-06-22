#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 class mycomp{
 public:
    operator()(pair<int,int> o , pair<int , int> t)
    {
        if(o.second < t.second)
            return true;
        else if(o.second == t.second)
            return o.first > t.first;
        return false;
    }
 };
 vector<int> topKFrequent(int n, vector<int> nums, int k) {
    unordered_map<int, int > m;
    for(int i = 0 ; i  < nums.size() ; i++)
    {
        m[nums[i]]++;
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , mycomp> pq;
    unordered_map<int, int> :: iterator it;
    for(it = m.begin() ; it!= m.end() ; it++)
    {
        pq.push(make_pair(it->first , it->second));
    }

     vector<int> res;
    // res.push_back(1);
     //res.push_back(2);
     for(int i = 0 ; i  < k  ; i++)
     {
         res.push_back((pq.top()).first);
         pq.pop();
     }
     return res;

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
     int k;
     cin>>k;
     vector<int> res = topKFrequent(n, arr, k);
     sort(res.begin(), res.end());
     cout<<"[";
     for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }
