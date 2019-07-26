#include<bits/stdc++.h>
using namespace std;
void print(string str , string cur)
{
    if(str.length() == 0)
    {
        cout<<cur<<endl;
        return ;
    }
    print(str.substr(1,str.length() -1 ) , cur);
    cur += str[0];
    print(str.substr(1,str.length() -1 ) , cur);

}

int main()
{

    string str = "cab";
    print(str,"");
}
