#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

   bool SubsetProblem(vector<int> arr1, vector<int> arr2)
   {
       unordered_set<int> set1;
       for(int i = 0 ;  i  < arr1.size() ; i++)
       {
           set1.insert(arr1[i]);
       }
       for(int i =0  ; i < arr2.size() ;i++)
       {
           if(!set1.count(arr2[i]))
           {
               return false;
           }
       }
       return true;
   }

   void solve()
   {
       int n, m;
       cin >> n;

       vector<int> arr1(n, 0);

       for (int i = 0; i < n; i++)
       {
           cin >> arr1[i];
       }
      cin>>m;
       vector<int> arr2(m, 0);

       for (int i = 0; i < m; i++)
       {
           cin >> arr2[i];
       }

       cout<< (SubsetProblem(arr1,arr2)?"Yes":"No")<<endl;

   }

   int main(int args, char **argv)
   {
       solve();
       return 0;
   }
