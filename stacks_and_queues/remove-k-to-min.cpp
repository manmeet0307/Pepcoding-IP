#include<bits/stdc++.h>
using namespace std;
string ans(string s, int k)
{
    stack<int> st;
    for(int i =0;i<s.length();i++)
    {
        int n = s[i]-48;
        while(!st.empty() && k>0 && st.top() > n)
        {
            st.pop();
            k--;
        }
        st.push(n);
    }
    string a ="";
        while(!st.empty())
        {
            string t(1,st.top() +48);
            a = a + t +"";
            st.pop();
        }
        reverse(a.begin() , a.end());
        if(k==0)
        {
            while(s.length() >1  && a[0]=='0')
            {
                a.erase(0,1);
            }
            return a;
        }
        else{
            return a.substr(0,k-1);
        }

}
int main()
{
      int k = 0;
     cin >> k;
     string s;
     cin >> s;
    cout<<ans(s,k);
}
