#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool customerSolution(vector<int> &arr, int k)
{
    unordered_map<int , int> m;
    for(int i = 0;i < arr.size() ;i++)
    {
        m[arr[i]]++;
    }
    unordered_map<int , int> :: iterator it;
    int mf =0,mk =0;
    for(it = m.begin() ; it!= m.end() ;it++)
    {
        if(it->second > mf)
        {
            mf = it->second;
            mk = it->first;
        }
    }
    if(mf > 2*k)
    {
        return false;
    }
    else
    {
        return true;
    }
}

 void solve()
 {
     int n;
     cin >> n;
     vector<int> arr(n, 0);

     for (int i = 0; i < n; i++)
     {
         cin >> arr[i];
     }
     int k;
     cin >> k;

     cout<<customerSolution(arr,k);
     cout<<endl;
 }

 int main()
 {
     solve();
     return 0;
 }
