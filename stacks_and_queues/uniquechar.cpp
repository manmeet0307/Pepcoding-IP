#include<bits/stdc++.h>
using namespace std;
void unique(char * arr , int n)
{
    unordered_map<char,int> m;
    queue<char>q;
    vector<char> v;
    for(int i = 0;i<n;i++)
    {
        m[arr[i]]++;
        while(!q.empty() && m[q.front()]!=1)
        {
            q.pop();
        }
        if(m[arr[i]]==1)
        {
            q.push(arr[i]);
        }
        if(q.empty())
        {
            cout<<"-1 ";
        }
        else{
            cout<<q.front()<<" ";
        }

    }
}
int main()
{
    int n;
    cin>>n;
    char arr[1000];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    unique(arr , n);
}
