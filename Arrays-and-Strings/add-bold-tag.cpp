#include<iostream>
 #include<vector>
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
void kmp(string src , string pat , vector<bool> &marked)
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
                  int start = i-j;
                  for(int x = start; x < i ;x++)
                  {
                        marked[x] = true;
                  }
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
 string addBoldTag(string &s, vector<string> &dict) {
     vector<bool> marked(s.length() , 0);
     for(int i = 0 ; i < dict.size() ; i++)
     {
         kmp(s,dict[i],marked);
     }
     string ans;
     for(int i = 0 ; i < s.length() ; )
     {
         if(marked[i] == true)
         {
             ans += "<b>";
             while(i<s.length() && marked[i] )
             {
                 ans += s[i];
                 i++;
             }
             ans+="</b>";
         }
         else
         {
            ans += s[i];
            i++;
         }
     }
     return ans;
 }

 int main(int argc, char** argv){
     string s;
     cin>>s;
     int n;
     cin>>n;
 	 vector<string> dict(n);
     for (int i = 0; i < n; i++) {
         cin>>dict[i];
     }
     cout<<addBoldTag(s, dict);
 }
