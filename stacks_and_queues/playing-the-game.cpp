#include<bits/stdc++.h>
using namespace std;
int game(string * s1 , int n)
{
    stack<int> s;
    int score = 0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]=="+")
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(y);
            s.push(x);
            s.push(x+y);
        }
        else if(s1[i]=="D")
        {
            s.push(2*s.top());
        }
        else if(s1[i]=="C")
        {
            s.pop();
        }
        else{
            s.push(stoi(s1[i]));
        }
    }
    while(!s.empty())
    {
        score+=s.top();
      //  cout<<s.top()<<endl;
        s.pop();
    }
    return score;
}
int main()
{
    string arr[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<game(arr,n);
}
