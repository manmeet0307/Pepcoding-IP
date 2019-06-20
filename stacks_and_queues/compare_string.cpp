#include<bits/stdc++.h>
using namespace std;
string stringcompare(string s )
{
    stack<char> s1;
    int i = 0;
    while( i<s.length())
    {
        if(!s1.empty() && s[i]=='#')
        {
            s1.pop();
        }
        else{
            s1.push(s[i]);
        }
        i++;
    }
    string a1;
    while(!s1.empty())
    {
        a1 += s1.top();
        s1.pop();
    }

    return a1;

}
int main()
{
    string m, n;
    cin>>m >>n;
    string a = stringcompare(m);
    string b = stringcompare(n);
    if(a==b)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
