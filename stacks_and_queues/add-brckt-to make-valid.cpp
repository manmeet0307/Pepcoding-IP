#include<bits/stdc++.h>
using namespace std;
int add(string s)
{
    stack<char> st;
    for(int i =0;i< s.length() ;i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
                if(st.empty() || st.top() == ')')
                {
                    st.push(s[i]);
                }
                else
                {
                    st.pop();
                }
        }
    }

    return st.size();
}
int main()
{
    string s;
    cin>>s;
    cout<<add(s);
}
