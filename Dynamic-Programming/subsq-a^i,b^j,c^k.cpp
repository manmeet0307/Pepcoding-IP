#include <bits/stdc++.h>
using namespace std;

int countSubsequences(string s)
{
    int acount = 0, bcount = 0 , ccount = 0;
    for(int i=0;i<s.length() ;i++)
    {
        if(s[i] == 'a')
        {
            acount= acount*2 +1;
        }
        if(s[i] == 'b')
        {
            bcount = 2*bcount + acount;
        }
        if(s[i] == 'c')
        {
            ccount= 2*ccount + bcount;
        }
    }
    return ccount;
}
int main()
{
	string s = "abbc";
	cout << countSubsequences(s) << endl;
	return 0;
}
