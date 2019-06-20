#include<bits/stdc++.h>
using namespace std;
string path(string s)
{
    stack<string> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='/')
        {
            if(st.empty() || st.top() !="/" )
            {
                string t(1,s[i]);
                st.push(t);
            }
        }
        else if(s[i]=='.' && i<s.length()-1 && s[i+1] =='.')
        {
            st.pop();
            if(st.empty())
            {
                continue;
            }
            st.pop();
            i++;
        }
        else if(s[i]=='.')
        {

        }
        else
        {
            string t(1,s[i]);
            if(st.top()=="/")
            {
                st.push(t);
            }
            else
            {
             string m = st.top();
                st.pop();
                st.push(m+t);
            }
        }
    }
    if(!st.empty() && st.top()=="/")
    {
        st.pop();
    }
    string ans ;
    while(!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
   // reverse(ans.begin() ,ans.end());
   if(ans.length()==0)
   {
       ans ="/";
   }
    return ans;
}
int main()
{
    string a ;
    cin>>a;
    cout<<path(a);
}
