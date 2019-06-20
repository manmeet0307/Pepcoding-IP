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
bool isnum(char a)
{
    return a>='0' && a<='9';
}

int result(int n1,int n2 , char opr)
{
    int a;
    switch(opr)
    {
        case '+': a= n1+n2;
        break;
        case '-': a= n2-n1;
        break;
        case '*': a= n1*n2;
        break;
        case '/': a= n2/n1;
        break;
        case '^': a= pow(n2,n1);
        break;
    }
    return a;
}
int evaluate(string s)
{
    stack<int> num;
    stack<char> op;

    for(int i=0;i<s.length();i++)
    {
        if(isnum(s[i]))
        {
            num.push(s[i]-48);
        }
        else if (s[i]=='(')
        {
            op.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!op.empty() && op.top() != '(' )
            {
                int opr = op.top();
                op.pop();
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                num.push(result(n1,n2,opr));
            }
            op.pop();
        }
        else
        {
            while(!op.empty() && (op.top()!='(') && (priority(op.top()) >= priority(s[i])) )
            {
                int opr = op.top();
                op.pop();
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                num.push(result(n1,n2,opr));
            }
            op.push(s[i]);
        }
    }

    while(!op.empty() && !num.empty() )
            {
                int opr = op.top();
                op.pop();
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                num.push(result(n1,n2,opr));
            }
            return num.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<evaluate(s);
}
