#include<bits/stdc++.h>
using namespace std;
int * ngeother(int * a, int * b, int n1, int n2)
{
    unordered_map<int, int> m;
    int * ans = new int[n1];
    stack<int> st;
    for(int i =0;i< n1 ;i++)
    {
        m[a[i]] = i;
    }
    st.push(b[0]);
    for(int i =1; i<n2 ;i++)
    {

                while(!st.empty() && (st.top() <= b[i]))
                {
                   if(m.count(st.top()))
                   {
                       ans[m[st.top()]] = b[i];
                   }
      //     cout<<st.top()<<" popped by " <<b[i] <<endl;
                    st.pop();
                }

                st.push(b[i]);

    }
    while(!st.empty())
    {
        if(m.count(st.top()))
        {
            ans[m[st.top()]] = -1;
        }
        st.pop();
    }
//    for(int i =0;i<n1;i++)
//    {
//        cout<<ans[i]<<" ";
//    }
//cout<<endl;
    return ans;
}
int main()
{
    int n1, n2;
    cin>>n1>>n2;
    int a[n1],b[n2];
    for(int i =0 ;i <n1; i++)
    {
        cin>>a[i];
    }
    for(int i =0 ;i <n2; i++)
    {
        cin>>b[i];
    }

    int * ans = ngeother(a,b,n1,n2);
    for(int i =0;i<n1;i++)
    {
        cout<<ans[i]<<" ";
    }
}
