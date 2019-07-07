#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> v)
{
    for(int i =0;i< v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void print(int *dp, int n , int i, int * jumps,vector<int> v)
{
    if(i>=n || dp[i] == 0)
    {
        return ;
    }
    if(i == n-1)
    {
       v.push_back(i);
        printvector(v);
        return ;
    }

    for(int x = i+1 ; x < i + 1 + jumps[i] ; x++)
    {
        if(dp[x] !=0)
        {
            v.push_back(i);
            print(dp,n,x,jumps,v);
            v.pop_back();
        }
    }
}
int pathcount(int* jumps,int n)
{
    int * dp = new int[n];
     for(int i = 0 ; i < n ; i++)
     {
         dp[i] = 0;
     }
     dp[n-1] = 1;
     for(int i = n-2 ; i>=0;i--)
     {
         if(jumps[i] == 0)
         {
             continue;
         }
         int c = 0;
         for(int j = i+1; j< i+1+jumps[i] ; j++)
         {
             c += dp[j];
         }
         dp[i] = c;
     }

      for(int i = 0 ; i < n ; i++)
     {
         cout<<dp[i]<<" " ;
     }
     cout<<endl;
    vector<int> v;
    print(dp,n,0,jumps,v);
     //return dp[0];
}
int main()
{
    int jumps[] = {3,5,0,1,2,0,3,1,0,1,0};
    pathcount(jumps,11);
}
