#include<bits/stdc++.h>
using namespace std;
stack<int> sortstack(stack<int> st)
{
    stack<int> h;
    while(!st.empty())
    {
        int num = st.top();
        st.pop();
        while(!h.empty() && h.top() > num)
        {
            st.push(h.top());
            h.pop();
        }
            h.push(num);
    }
    return h;
}
int main()
{
    int n;
    cin>>n;
    stack<int> st;
    for(int i =0 ;i < n ;i++)
    {
        int num;
        cin>>num;
        st.push(num);
    }
    stack<int> r = sortstack(st);
    while(!r.empty())
    {
        cout<<r.top()<<" ";
        r.pop();
    }
}
