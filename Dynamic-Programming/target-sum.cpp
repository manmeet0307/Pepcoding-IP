#include<bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void printsol(bool **dp ,int n , int tar , vector<int> v ,int i , int j,int * arr)
{
    if(i<0 || j<0)
        return ;
    if(i==0 && j ==0)
    {
        print(v);
        return ;
    }
    if(dp[i-1][j])
    {
        printsol(dp,n,tar,v,i-1,j,arr);
    }
    if(dp[i-1][j-arr[i-1]])
    {
        v.push_back(arr[i-1]);
        printsol(dp,n,tar,v,i-1,j-arr[i-1],arr);
    }
}
void countarr(bool **dp ,int n , int tar , vector<int> v ,int i , int j,int * arr,int &counter)
{
    if(i<0 || j<0)
        return ;
    if(i==0 && j ==0)
    {
        counter++;
        return ;
    }
    if(dp[i-1][j])
    {
        countarr(dp,n,tar,v,i-1,j,arr,counter);
    }
    if(dp[i-1][j-arr[i-1]])
    {
        v.push_back(arr[i-1]);
        countarr(dp,n,tar,v,i-1,j-arr[i-1],arr,counter);
    }
}
void targetsum(int * arr , int n,int tar)
{
    bool ** dp = new bool*[n+1];
    for(int i = 0 ; i < n +1;i++)
    {
        dp[i] = new bool[tar+1];
    }
    for(int i = 0; i <n+1;i++)
    {
        for(int j = 0 ; j < tar+1;j++)
        {
            dp[i][j] = false;
        }
    }
    //0 sum can be formed everytime
    for(int i = 0; i  < n+1;i++)
    {
        dp[i][0] = true;
    }

    for(int i = 1; i < n+1 ; i++)
    {

        for(int j = 1; j < tar+1; j++)
        {

                //using it
            if((j - arr[i-1])>=0)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]];
            }
            //without using it
            if(dp[i-1][j])
            {
                dp[i][j] = true;
            }
        }
    }
    for(int i = 0; i <n+1;i++)
    {
        for(int j = 0 ; j < tar+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> v;
     printsol(dp,n,tar,v,n,tar,arr);

     cout<<endl;
     int c= 0;
      countarr(dp,n,tar,v,n,tar,arr,c);

      cout<<"count: "<<c;
}
int main()
{
    int n, tar;
    cin>>n;
    int arr[n];
    cin>>tar;
    for(int i =0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    targetsum(arr,n,tar);

}
