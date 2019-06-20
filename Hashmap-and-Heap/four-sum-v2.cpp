#include <iostream>
 #include <algorithm>
 #include <vector>
 #include<bits/stdc++.h>
 using namespace std;

 // -----------------------------------------------------
     // This is a functional problem. Only this function has to be written.
     // This function takes as input the head of the linked list.
     // It should return the head of the modified list.


 int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
 {
      unordered_map<int , vector<pair<int,int>>> m;
      int target = 0;
     for(int i=0;i<A.size();i++)
     {
         for(int j = 0; j < B.size() ;j++)
         {
             m[A[i]+B[j]].push_back(make_pair(i,j));
         }
      }
      int c = 0 ;
     for(int i=0;i<C.size();i++)
     {
         for(int j = 0 ; j < D.size() ;j++)
         {
             int cds = C[i] + D[j];
             if(m.count(target-cds))
             {
                    c ++;
             }
        }
    }
     return c;
 }

 int main(int args, char **argv)
 {
     int n;
     cin >> n;
     vector<int> A(n, 0);
     vector<int> B(n, 0);
     vector<int> C(n, 0);
     vector<int> D(n, 0);

     for (int i = 0; i < n; i++)
     {
         cin >> A[i];
     }

     for (int i = 0; i < n; i++)
     {
         cin >> B[i];
     }
     for (int i = 0; i < n; i++)
     {
         cin >> C[i];
     }
     for (int i = 0; i < n; i++)
     {
         cin >> D[i];
     }

     cout << fourSumCount(A, B, C, D);
 }
