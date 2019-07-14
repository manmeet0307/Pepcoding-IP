#include<bits/stdc++.h>
using namespace std;
string backans(int ** dp,int i,int j,int m,int n,string ans ,string s1,string psf)
{
    if(i>=m | j>=n|| i<0||j<0)
        return "";
    if(i==m-1 || j == n-1)
    {
        return ans;
    }
    if(i+1 < m && j+1 <n && (dp[i+1][j+1] == dp[i][j]-1) && dp[i][j+1]==dp[i+1][j+1] && dp[i+1][j]==dp[i+1][j+1])
    {
        ans += s1[i];
        return backans(dp,i+1,j+1,m,n,ans,s1,psf);
    }
    else
    {
       if(i+1 < m && j+1<n && dp[i+1][j] >= dp[i][j+1])
       {

            return backans(dp,i+1,j,m,n,ans,s1,psf);
       }

       else if(i+1 < m && j+1<n && dp[i+1][j] < dp[i][j+1])
       {
            return backans(dp,i,j+1,m,n,ans,s1,psf);
       }

    }
}
pair<string , int> lcs(string s1 , string s2)
{

    string ans;
    int ** dp = new int * [s1.length() + 1];
    for(int i =0; i <s1.length() + 1;i++)
    {
        dp[i] = new int[s2.length() + 1];
    }
    int m = s1.length() + 1;
    int n = s2.length() + 1;
    for(int i = 0;i< n;i++)
    {
        dp[m-1][i] = 0;

    }
    for(int i=0;i<m;i++)
    {
        dp[i][n-1] = 0;
    }
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            if(s1[i] == s2[j])
            {
                dp[i][j] = dp[i+1][j+1] + 1;
                continue;
            }
            else
            {
                dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            }
        }

    }/*
   for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    //reverse(ans.begin() , ans.end());
    //cout<<" ****BACKTRACK***"<<endl;
    string psf="",t="";
    if(dp[0][0] !=0)
     t=backans(dp,0,0,m,n,"",s1,psf);
   return make_pair(t , dp[0][0]);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,c;
       int x,y,z;
       cin>>x>>y>>z;
        cin>>a>>b>>c;

        pair<string ,int> p = lcs(a,b);
      //  cout<<"psf = "<<p.first;
        int s = lcs(c,p.first).second;
        cout<<s<<endl;
    }
}
