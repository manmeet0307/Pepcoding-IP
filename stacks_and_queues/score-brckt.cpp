#include<bits/stdc++.h>
using namespace std;
int score(string s)
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
            if(st.top()=='(')
            {
                st.pop();
                st.push('1');
            }
            else{
                    int res =0;
                while(!st.empty() && st.top()!='(')
                {
                    res += (st.top() - 48 );
                    st.pop();
                }
                st.pop();
         //       cout<<"push"<<2*res<<endl;
                st.push((2*res) + 48);
            }

        }
    }
    int s1 = 0;
    while(!st.empty())
    {
       // cout<<st.top()-48 <<endl;
        s1 += st.top() -48;
        st.pop();
    }

    return s1;
}
int main()
{
    string s;
    cin>>s;
    cout<<score(s);
}
