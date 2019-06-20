#include<bits/stdc++.h>
using namespace std;
string decode(string s)
{
    stack<string> strst;
    stack<int> numst;
    string t = "";
    strst.push(t);
    for(int i = 0 ;i<s.length() ;i++)
    {
        if(s[i]==']')
        {
               string m = strst.top();
               int f = numst.top();
               strst.pop(),numst.pop();
               string a = strst.top();
               strst.pop();
               string q;
               for(int j =0;j< f;j++)
               {
                   q += m;
               }
               strst.push(a+q);
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            string j(1,s[i]);
            int x = i+1;
            while(x<s.length() && s[x]>='0' && s[x]<='9')
            {
                j += s[x];
                x++;
            }
            i = x-1;
            numst.push(stoi(j));

        }
        else if(s[i]=='[')
        {
            string a ="";
            strst.push(a);
        }
        else {
            string t(1,s[i]);
            string m =strst.top();
            strst.pop();
               strst.push(m+t);
        }

    }
    string a ;
    while(!strst.empty())
    {
        a += strst.top();
        strst.pop();
    }
return a;
}
int main()
{
    string s;
    cin>>s;
    cout<< decode(s);
}
