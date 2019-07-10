#include<bits/stdc++.h>
using namespace std;
int encodeno(string s)
{
    int * dp = new int[s.length()];
    s[0] == '0' ? dp[0] = 0 : dp[0] = 1;
    for(int i=1 ; i<s.length() ; i++)
    {
       int dig = s[i] - 48;
       if(dig >= 1 && dig <= 9)
       {
           dp[i] = dp[i-1];
       }
       int prevdig = (s[i-1]-48 )*10 + dig;
       if( prevdig>=10 && prevdig <= 26)
       {
          if(i-2 <0)
          {
              dp[i] += 1;
          }
          else
          {
              dp[i] += dp[i-2] ;
          }
       }
    }

    for(int i=0;i<s.length();i++)
    {
        cout<<dp[i] << " ";
    }
    return dp[s.length()-1];
}
int main()
{
    string n;
    cin>>n;
    cout<<encodeno(n);
}
