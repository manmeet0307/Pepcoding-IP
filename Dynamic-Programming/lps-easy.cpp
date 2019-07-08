#include<bits/stdc++.h>
using namespace std;
int Lcs( string x, string y, int m, int n )
{
    int lcs[m+1][n+1];
    memset(lcs,0,sizeof(lcs));
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(x[i] == y[j])
            {
                lcs[i][j] = lcs[i+1][j+1]+1;
            }
            else
            {
                lcs[i][j] = max(lcs[i+1][j] , lcs[i][j+1]);
            }
        }
    }
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<lcs[i][j]<<" ";
        }
        cout<<endl;
    }
    return lcs[0][0];
}

/* Driver program to test above function */
int main()
{
    string x ;
    cin>>x;
    string y = x;
    reverse(x.begin(),x.end());
int  m = x.length();
  int  n = y.length();
    cout<< Lcs( x, y , m, n );

return 0;
}
