#include<bits/stdc++.h>
using namespace std;
int fun(string s)
{
    int jc = 0 , kc = 0 , sc = 0;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] =='j')
        {
            jc++;
        }
        else if(s[i] == 'k')
        {
            kc ++;
        }
        if(kc<jc)
        {
            sc++;
            kc++;
            jc--;
        }
    }
    sc += abs(jc - kc)/2;
    return sc;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<fun(s)<<endl;
    }
}
