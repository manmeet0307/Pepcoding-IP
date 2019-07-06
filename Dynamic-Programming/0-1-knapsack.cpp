#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> v)
{
    cout<<"subset";
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void print(int ** dp,int i , int j , vector<int> v,int *w,int*p)
{

    if(i==0 || j==0)
    {

        printvector(v);
        return ;
    }
//    cout<<dp[i][j]<<endl;
    if(j-w[i-1] >=0 )
    {
        if(dp[i-1][j] > (dp[i-1][j-w[i-1]] + p[i-1]))
        {
            print(dp,i-1,j,v,w,p);
        }
        else if(dp[i-1][j] < (dp[i-1][j-w[i-1]] + p[i-1]))
        {

            v.push_back(w[i-1]);
            print(dp,i-1,j-w[i-1],v,w,p);
        }
        else
        {
             print(dp,i-1,j,v,w,p);
              v.push_back(w[i-1]);
            print(dp,i-1,j-w[i-1],v,w,p);
        }
    }
    else
    {
        print(dp,i-1,j,v,w,p);
    }
}
void knapsack(int *p,int*w , int tar , int n)
{
    int ** dp = new int * [n+1];
    for(int i = 0 ; i < n+1; i++)
    {
        dp[i] = new int[tar+1];
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j = 0 ; j< tar+1;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i<n+1;i++)
    {
        for(int j = 1; j <tar+1;j++)
        {
            if(j-w[i-1] >=0)
            {
                dp[i][j] = dp[i-1][j-w[i-1]] + p[i-1];
            }

            dp[i][j] = max(dp[i][j] , dp[i-1][j]);
        }
    }

    for(int i = 0; i<n+1;i++)
    {
        for(int j = 0; j <tar+1;j++)
        {
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> v;
    cout<<endl<<endl;
    print(dp,n, tar ,v, w,p);
}
int main()
{
    int tar;
    cin>>tar;
    int n;
    cin>>n;
    int w[n] , p[ n ];
    for(int i = 0 ; i  < n; i++)
    {
        cin>>w[i];
    }
    for(int i = 0 ; i < n; i++)
    {
        cin>>p[i];
    }
    knapsack(p,w,tar,n);
}
