#include<bits/stdc++.h>
using namespace std;
bool isnum(char a)
{
    return a>='0' && a<='9';
}

int result(int n1,int n2 , char opr)
{
    int a =0;
    switch(opr)
    {
        case '+': a= n1+n2;
        break;
        case '-': a= n1-n2;
        break;
        case '*': a= n1*n2;
        break;
        case '/': a= n1/n2;
        break;
        case '^': a= pow(n1,n1);
        break;
    }
    return a;
}
int evaluate(string s)
{
    stack<int> num;

    for(int i=s.length()-1;i>=0;i--)
    {
        if(isnum(s[i]))
        {
            num.push(s[i]-48);
        }

        else
        {
                char opr = s[i];
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                num.push(result(n1,n2,opr));
        }
    }

    return num.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<evaluate(s);
}
