#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 class mycomp
 {
 public:
    bool operator()(pair<int,int> one , pair<int,int> two)
    {
        if( one.second < two.second ) return true ;
        else if(one.second == two.second )
            return one.first > two.first;
        return false;
    }
 };
 void sortByFreq(vector<int> arr, int n) {
     unordered_map<int , int> m;
     for(int i = 0 ; i < n ; i++ )
     {
         m[arr[i]]++;
     }
     priority_queue<pair<int,int> ,vector<pair<int ,int>> , mycomp> pq;
     unordered_map<int , int> :: iterator it;
     for(it = m.begin() ; it!=m.end() ; it++)
     {
         pq.push(make_pair(it->first , it->second));
     }
     while(!pq.empty())
     {
         pair<int , int> curr = pq.top();
         int f = curr.second;
         while(f--)
         {
             cout<<curr.first<< " ";
         }
         pq.pop();
     }


 }
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for(int i=0;i<n;i++){
         int val;
         cin>>val;
         arr.push_back(val);
     }
     sortByFreq(arr, n);
 }
