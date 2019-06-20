#include<bits/stdc++.h>
using namespace std;
bool isint(char t)
{
    if(t>='0' && t<='9')
    {
        return true;
    }
    return false;
}
int calclen(string s)
{
    int c=0;
    for(int i =0;i<s.length();i++)
    {
        if(!isint(s[i]))
        {
            c++;
        }
        else
        {
            c*= (s[i]-48);
        }
    }
    return c;
}
char decode(string s, int k)
{

    int size = calclen(s);
    int n =s.length();
    for(int i = n-1;i>=0;i--)
    {
            if(!isint(s[i]))
            {

                k = k % size;
                if((k+1)%size == 0)
                {
                    return s[i];
                }
                else
                {

                   size--;

                }
            }
            else
            {
                    size = size / (s[i]-48);
            }
    }
    return 'o';
}
int main()
{
    string s;
    int k;
    cin>>s>>k;
    cout<< decode(s,k);

}
