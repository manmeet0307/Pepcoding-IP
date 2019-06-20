#include<bits/stdc++.h>
using namespace std;
int longp(string t,int n)
{
    stack<int> st;
    st.push(-1);
    int mgap = 0;
    for(int i = 0; i<n ; i++)
    {
        if(t[i]==')')
        {
                if(st.top()==-1 || t[st.top()] == ')')
                {
                    st.push(i);
                }
                else
                {
                    st.pop();
                    mgap = max(mgap , i - st.top());
                }
        }
        else
        {
         st.push(i);
        }
    }
    return mgap;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout<<longp(s,n);
}
