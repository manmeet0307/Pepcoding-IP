#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>
using namespace std;
 vector<int> pourWater(vector<int>& heights, int v, int k) {
    int n = heights.size();
    for(int i = 0 ; i < v; i++)
    {
        int tr = k-1;
        int h = heights[tr];
        while(tr >=0  )
        {
           if(heights[tr] < heights[k])
           {
               break;
           }
           else if(heights[tr] > heights[k])
           {
               goto right;
           }
           tr--;
        }
        if(tr >=0)
        {
            heights[tr]++;
            continue;
        }
        right:
        tr = k+1;
         while(tr <n )
        {
            if(heights[tr] < heights[k])
            {
                break;
            }
            else if(heights[tr] > heights[k])
            {
                goto incrk;
            }
            tr++;
        }
        if(tr < n)
        {
            heights[tr]++;
            continue;
        }
        incrk:
        heights[k]++;
    }

     return heights;
 }
 void display(vector<int> & arr) {

     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }

 int main(int argc ,char** argv){

     int N;
     cin>>N;

     vector<int> arr1(N);

     for (int i = 0; i < N; i++) {
         cin>>arr1[i];
     }

     int V;
     cin>>V;
     int K ;
     cin>>K;

     vector<int> res;
     res= pourWater(arr1, V, K);
     display(res);

 }
