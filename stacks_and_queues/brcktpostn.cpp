#include<bits/stdc++.h>
using namespace std;
void printb(string s)
{
    vector<int>v;

        stack<int> st;
int c = 0;
for(int i =0;i<s.length() ;i++)
{


    if(s[i]=='(')
    {
        c++;
        st.push(c);

        v.push_back(c);
    }
    else if(s[i]==')')
    {
         v.push_back(st.top());
        st.pop();


    }
}

    for(int i =0; i<v.size() ;i++)
    {
        cout<<v[i]<<" ";
    }
}

int main()
{
    string s;
    cin>>s;
    printb(s);
}
