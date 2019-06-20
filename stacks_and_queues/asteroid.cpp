#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
bool ispositive(int n)
{
    return n>=0;
}
bool cancollide(int x ,int y)
{
    if(ispositive(x) == ispositive(y))
    {

        return false;
    }
    if(!ispositive(y) && ispositive(x))
    {
        return false;
    }
    return true;
}
vector<int> asteroid(int * arr, int n)
{
    vector<int>m;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.empty() || !cancollide(arr[i] , s.top()))
        {
            s.push(arr[i]);
        }
        else
        {
            s.push(arr[i]);
            int x = s.top() ;
            s.pop();
            int y = s.top();
            s.pop();
            //int r;
     //       cout<<"h1"<<endl;
            while( cancollide(x,y))
            {
   // cout<<"loop"<<endl;
                if(x==y)
                {
                    continue;
                }
                abs(x) > abs(y) ? s.push(x): s.push(y);
                //s.push(r);
                if(s.size()<=1)
                {
                  // s.push(r);
                    break;
                }
                x = s.top() ;
                s.pop();
                y = s.top();

                s.pop();
            }
            if(!cancollide(x,y))
            {
                s.push(y),s.push(x);
            }
        }
       // if(!s.empty())
     //   cout<<i <<" " << s.top()<<endl;
    }
    int c=0;
    while(!s.empty())
    {
        m.push_back(s.top());
        s.pop();
    }
    reverse(m.begin() , m.end());
    return m;

}
int main()
{
    int arr[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ans = asteroid(arr,n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
