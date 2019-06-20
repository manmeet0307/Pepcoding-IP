#include<bits/stdc++.h>
using namespace std;
int priority(char a)
{
    if(a == '^')
    {
        return 3;
    }
    else if(a == '/' || a=='*')
    {
        return 2;
    }
    else if(a=='+' || a=='-')
    {
        return 1;
    }
}
bool ischar(char a)
{
    return (a>='a' && a<='z') || (a>='A' && a<='Z');
}

string post_to_inf(string s)
{
    stack<string> num;

    for(int i=0;i<s.length();i++)
    {
        if(ischar(s[i]))
        {
           string t(1,s[i]);
            num.push(t);
        }
        else
        {

                string opr(1,s[i]);
                string n1 = num.top();
                num.pop();
                string n2 = num.top();
                num.pop();
                num.push(("(" + n2 + opr + n1 + ")"));
        }
    }

            return num.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<post_to_inf(s);
}
