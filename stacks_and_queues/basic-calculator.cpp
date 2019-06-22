#include<bits/stdc++.h>
using namespace std;
bool isnum(char a )
{
    return a>='0' && a<='9';
}
int calc(string t)
{
    stack<int> num ;
    stack<char> op;
    for(int i = 0 ; i  < t.length() ; i++)
    {
     //cout<<t[i];
        if(t[i]==' ')
            continue;
        if(isnum(t[i]))
        {
            int j = i;
            int x =0 ;
            while(j < t.length() && isnum(t[j]))
            {
              x = (x*10 + (t[j]-48));
              j++;
            }
           // cout<<x<<endl;
            i = j-1;
            num.push(x);

        }
        else if(t[i]== ')')
        {
            while(op.top() != ')')
            {
                char opt = op.top();
                op.pop();
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                int a = (opt=='+' ? ( n1+n2) : (n2-n1));
                num.push(a);
            }
            op.pop();
        }
        else if(t[i]=='(')
        {
            op.push(t[i]);
        }
        else
        {
     //       cout<<t[i]<<endl;
            while(!op.empty())
            {
                char opt = op.top();
                op.pop();
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                int a = (opt=='+' ? ( n1+n2) : (n2-n1));
     //   cout<<a<<endl;
                num.push(a);
            }
            op.push(t[i]);
        }
    }
            while(!op.empty())
            {
                char opt = op.top();
                op.pop();
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                int a = (opt=='+' ? ( n1+n2) : (n2-n1));
   //     cout<<a<<endl;
                num.push(a);
            }
    return num.top();
}
int main()
{
string s;
getline(cin,s);
cout<<calc(s);
}
