#include<bits/stdc++.h>
using namespace std;
char ternary(string s)
{
    stack<char> st;
    for(int i = s.length()-1;i>=0;i--)
    {
        if(s[i]==':')
        {
            continue;
        }
        else if(s[i]=='?')
        {
            char x = st.top();
            st.pop();
            char y = st.top();
            st.pop();
            if(s[i-1] =='T')
            {
                st.push(x);
            }
            else
            {
                st.push(y);
            }
            i--;
        }
        else
        {
                st.push(s[i]);
        }

    }
    return st.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<ternary(s);
}
