#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ksum(string s ,int k)
{
    int sum = 0;
    int level = -1;
    for(int i = 0; i < s.length() ; i++)
    {
        if(s[i] == '(')
        {
            level++;

        }
        else if(s[i] == ')')
        {
            level--;
        }
        else
        {
            if(level == k)
            {
                string num;
                while(s[i] >='0' && s[i]<='9')
                {
                    num +=s[i];
                    i++;
                }
                i--;
                sum += stoi(num);
            }
        }
    }
    return sum;
}
int main(int argc, char** argv){
        int k;
        cin>>k;
        string s;
        cin>>s;

        cout<<ksum( s , k);
}
