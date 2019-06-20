#include<bits/stdc++.h>
using namespace std;
void depth(string s)
{
    stack<char> st;
    for(int i =0;i< s.length() ;i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
            cout<<st.size()<<" ";
        }
        else
        {
            cout<<st.size()<<" ";
            st.pop();
        }
    }
}
int main()
{
    string s;
    cin>>s;
    depth(s);
}
