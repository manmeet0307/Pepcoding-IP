#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 void print_k_smallest_elements_in_their_original_order(int n,int k, vector<int> arr){
        priority_queue<int> pq;
        for(int i = 0 ; i < k ; i++)
        {
            pq.push(arr[i]);
        }
        for(int i = k ; i < n ; i++)
        {
                if(arr[i] < pq.top())
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
        }
        for(int i = 0 ; i< n ;i++)
        {
            if(arr[i] < pq.top())
            {
                cout<<arr[i] << " ";
            }
            else if(arr[i] == pq.top())
            {
                cout<< arr[i] << " ";
                pq.pop();
            }
        }
 }

 int main(int argc, char** argv) {

     int n, k;
     cin>>n>>k;

     vector<int> arr;

     for (int i = 0; i < n; i++) {
         int a;
         cin>>a;
         arr.push_back(a);
     }
     print_k_smallest_elements_in_their_original_order(n, k, arr);
 }
