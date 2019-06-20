#include<algorithm>
#include<queue>
#include <iostream>
#include <vector>
using namespace std;
class fraction{
public:
    int nrindex , drindex ;
    float val;
    fraction(int x, int y, float z)
    {
        nrindex = x;
        drindex = y;
        val = z;
    }
};
 class comf{
 public:
     bool operator()(fraction f1, fraction f2)
     {
         return f1.val > f2.val;
     }
 };
 vector<int> kthSmallestPrimeFraction(vector<int> &A, int k)
 {
     priority_queue<fraction, vector<fraction> , comf> pq;
     sort(A.begin(), A.end());
     int n = A.size();
     for(int i = 0 ; i < k ; i++)
     {
         pq.push(fraction(i,  n-1 , 1.0 * A[i]/A[n-1]));
     }
     while(--k > 0)
     {
         fraction temp = pq.top();
         pq.pop();
         if(temp.drindex-1 > temp.nrindex)
         {
            pq.push(fraction(temp.nrindex, temp.drindex -1 , 1.0*A[temp.nrindex]/A[temp.drindex -1])) ;
         }
     }
     fraction f = pq.top();
    vector<int> v;
    v.push_back(A[f.nrindex]);
    v.push_back(A[f.drindex]);
    return v;
 }

 int main()
 {
     int k, n;
     cin >> k >> n;
     vector<int> arr(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> arr[i];
     }

      arr = kthSmallestPrimeFraction(arr, k);
  cout<<arr[0]<<"/"<<arr[1];
     cout << endl;
 }
