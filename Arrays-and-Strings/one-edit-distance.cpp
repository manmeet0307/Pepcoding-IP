#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;

 bool isOneEditDistance(string & s, string& t) {
    int m = s.length() , n = t.length();
    int ** dp = new int*[m+1];
    for(int i = 0 ; i < m+1;i++)
    {
        dp[i] = new int[n+1];
        for(int j = 0; j  < n+1 ; j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 0 ; i < n+1;i++)
    {
        dp[0][i] = i;
    }
    for(int j = 1; j < m+1;j++)
    {
        dp[j][0] = j;
    }
    for(int i = 1; i< m+1 ;i++)
    {
        for(int j = 1 ; j< n+1 ; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {

                int op1 = 1 + dp[i-1][j];  //delete from s
                int op2 = 1 + dp[i][j-1]; // insert in s
                int op3 = 1 + dp[i-1][j-1]; //replace
                dp[i][j] = min(op1,min(op2,op3));
            }
        }
    }
 return dp[m][n] == 1 ? true : false;
 }

 int main (int argc,char** argv){
     string s,t;
     cin>>s;
     cin>>t;

     if (isOneEditDistance(s, t)) {
         cout<<"Yes"<<endl;
     } else {
         cout<<"No"<<endl;
     }

 }
