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

string inf_to_post(string s)
{
    stack<string> num;
    stack<char> op;

    for(int i=0;i<s.length();i++)
    {
        if(ischar(s[i]))
        {
           string t(1,s[i]);
            num.push(t);
        }
        else if (s[i]=='(')
        {
            op.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!op.empty() && op.top() != '(' )
            {
                string opr(1,op.top());
                op.pop();
                string n1 = num.top();
                num.pop();
                string n2 = num.top();
                num.pop();
                num.push((n2 + n1 + opr));
            }
            op.pop();
        }
        else
        {
            while(!op.empty() && (op.top()!='(') && (priority(op.top()) >= priority(s[i])) )
            {
                string opr(1,op.top());
                op.pop();
                string n1 = num.top();
                num.pop();
                string n2 = num.top();
                num.pop();
                num.push((n2 + n1 + opr));
            }
            op.push(s[i]);
        }
    }

    while(!op.empty() && !num.empty() )
            {
               string opr(1,op.top());
                op.pop();
                string n1 = num.top();
                num.pop();
                string n2 = num.top();
                num.pop();
                num.push((n2 + n1 + opr));
            }
            return num.top();
}
string normalise(string s)
{
    for(int i =0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            s[i] = ')';
        }
        else if(s[i]==')')
        {
            s[i] = '(';
        }
    }
    return s;
}
int main()
{
    string s;
    cin>>s;
    reverse(s.begin() , s.end());
    s = normalise(s);
    s = inf_to_post(s);
    reverse(s.begin(),s.end());
    cout<<s;
}
