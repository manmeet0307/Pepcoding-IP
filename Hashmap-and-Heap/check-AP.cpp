#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

 // ------------------------------------------------------
 bool checkAP(vector<int> &arr)
 {
        int n = arr.size();
        int m1 = *max_element(arr.begin() , arr.end());
        int m2 = *min_element(arr.begin() , arr.end());
        int d = (m1-m2)/(n-1);
        unordered_map<int,int> m;
        for(int i = 0; i<n ;i++)
        {
            m[arr[i]]++;
        }
        int x = m2;
         int y = m2+(n-1)*d;
        while(x<=y)
        {
            if(m.count(x))
            {
              x = x+d;
            }
            else{
                return false;
            }
        }
        return true;
 }
 int main()
 {
     int n = 0;
     cin >> n;
     vector<int> num(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> num[i];
     }
     if (checkAP(num))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }

     return 0;
 }
