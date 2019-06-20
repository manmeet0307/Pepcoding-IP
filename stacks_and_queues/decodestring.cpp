#include<bits/stdc++.h>
using namespace std;
string decode(string s)
{
    stack<string> st;
    for(int i = s.length()-1 ;i>=0 ;i--)
    {
        if(s[i]==']')
        {
               //string t =s[i];
               string t(1,s[i]);
               st.push(t);
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            int n = s[i]-48;
            string num (1,s[i]);
            int j = i-1;
            while(j>=0 && s[j]>='0' && s[j]<='9')
            {
                num = s[j] + num;
                j--;
            }
            i = j+1;
            n = stoi(num);
            string m =st.top();
             st.pop();
           /*  while(!st.empty() && st.top()!="[" && st.top()!="]")
             {
                 m += st.top();
                 st.pop();
             }*/
            string a;
            for(int j = 0;j<n;j++)
            {
                a += m;
            }
            st.push(a);
        }
        else if(s[i]=='[')
        {
            string a;
            string m = st.top();
            while(m!="]")
            {
                a += st.top();
                st.pop();
                m = st.top();
            }
            st.pop();
            st.push(a);
        }
        else {
            string t(1,s[i]);
               st.push(t);
        }

    }
    string a ;
    while(!st.empty())
    {
        a += st.top();
        st.pop();
    }
return a;
}
int main()
{
    string s;
    cin>>s;
    cout<< decode(s);
}
