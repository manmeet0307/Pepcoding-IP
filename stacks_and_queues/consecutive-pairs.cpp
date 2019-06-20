#include<bits/stdc++.h>
using namespace std;
bool pairWiseConsecutive(stack<int> s , int n)
{
    if(n%2!=0)
        s.pop();
    while(!s.empty())
    {
        int n1 = s.top();
        s.pop();
        int n2 = s.top();
        s.pop();
        if(abs(n1 - n2) != 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
     int num;
     cin>>num;
     s.push(num);
    }
    if(pairWiseConsecutive(s,n))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}
