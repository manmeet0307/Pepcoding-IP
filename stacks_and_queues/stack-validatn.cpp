#include<bits/stdc++.h>
using namespace std;
bool validate(int * pushed, int * popped, int n)
{
    stack<int> st;
    int p1 =0, p2 = 0;
    while(p1<n)
    {
        if(!st.empty() && st.top() == popped[p2])
        {
            p2++;
            st.pop();
        }
        else
        {
            st.push(pushed[p1]);
            p1++;
        }
    }
    while(!st.empty() && p2<n)
    {
        if(st.top() ==popped[p2])
            st.pop();
        p2++;
    }
    if(st.empty())
        return true;

    return false;
}
int main()
{
    int n;
    cin>>n;
    int pu[n],po[n];
    for(int i = 0 ; i<n ;i++)
    {
        cin>>pu[i];
    }
    for(int i = 0 ; i<n ;i++)
    {
        cin>>po[i];
    }
    if(validate(pu,po,n))
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
