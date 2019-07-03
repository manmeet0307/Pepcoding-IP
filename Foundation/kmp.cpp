#include<bits/stdc++.h>
using namespace std;
vector<int> computelps(string pat , string src )
{
    vector<int> lps(src.length() , 0);
    lps[0] = 0;
    int i =0 , j = 0, len = 0;
    for(int i = 1 ; i< src.length(); )
    {
        if(pat[j] == src[i])
        {
            len++;
            lps[i] = len;
            i++;j++;
        }
        else
        {
            if(len > 0)
            {
                len = lps[len-1];
            }
            else
            {
                i++;
            }
        }
    }
    return lps;
}
void kmp(string src , string pat)
{
    vector<int> lps = computelps(pat , src);
    int i = 0, j = 0;
    for(int i = 0 ; i < src.length() ; )
    {
         if(pat[j] == src[i])
         {
             i++ , j++;
             if(j== pat.length())
             {
                 cout<< "pattern found at"<< i-j<<endl;
                  j = lps[j-1];
             }
         }
         else
         {
             if(j>0)
             {
                 j = lps[j-1];
             }
             else
             {
               i++;
             }
         }
    }
}
int main()
{
    string s,p;
    cin>>s>>p;
    kmp(s,p);
}
