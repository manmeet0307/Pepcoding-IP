#include <iostream>
  #include <string>
  #include <vector>
  #include <unordered_set>
  #include <climits>
#include<bits/stdc++.h>
  using namespace std;

  //----------------------------------------
  bool isContiguous(vector<int> &arr)
  {
     unordered_map<int , bool> m;
     int max1 = INT_MIN , min1 = INT_MAX;
     for(int i = 0;i < arr.size() ; i++)
     {
         m[arr[i]] = true;
         max1 = max(arr[i] , max1);
         min1 = min(arr[i] , min1);
     }
     return ((max1-min1+1)-m.size())==0;
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

      if (isContiguous(num))
      {
          cout << "true" << endl;
      }
      else
      {
          cout << "false" << endl;
      }

      return 0;
  }
