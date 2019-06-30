#include<iostream>
 #include<vector>
 using namespace std;

 string addpoint(string s , int ind)
{
    if(ind == s.length()) return s;
    string r;
    int i;
    for( i = 0 ; i < ind ; i++)
    {
        r += s[i];
    }
    r += '.';
    for(  ; i < s.length() ; i++)
    {
        r += s[i];
    }
    return r;
}
string trimleft(string s)
{
    int c = 0;
    while(c<s.length() && s[c] == '0')
    {
        c++;
    }
    s = s.substr(c , s.length() - c);
    return s;
}
string trimright(string s)
{
    int c = s.length()-1;
    while(c>=0 && s[c] == '0')
    {
        c--;
    }
    string r;
    for(int i = 0 ; i <= c ; i++)
    {
        r += s[i];
    }
    return r;
}

 vector<string> getcomb(string s)
 {
     vector<string> a;
     for(int i = 0 ; i < s.length();i++)
     {
         string m = addpoint(s,i+1);
         if(m != "" )
         {
            m =  trimleft(m);
            m = trimright(m);
            a.push_back(m);
         }
     }
     return a;
 }
 vector<string> ambiguousCoordinates(string &S) {


     vector<string> ans;
     for(int i = 1 ; i < S.length()-1 ; i++)
     {
         string p1 = S.substr(1,i);
         string p2 = S.substr(i+1, S.length() - i -2);
         if(p1 == "" || p2=="")
            continue;
         vector<string> c1 = getcomb(p1);
         vector<string> c2 = getcomb(p2);
         for(int i = 0 ; i < c1.size() ;i++)
         {
             for(int j =0;j<c2.size() ;j++)
             {
                 ans.push_back("(" + c1[i] + " , " + c2[j]+ ")");
             }
         }
     }
     return ans;
 }

 int main(int argc, char** argv){
     string s;
     cin>>s;
 	 vector<string> res = ambiguousCoordinates(s);
     cout<<"[";
 	 for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
     cout<<endl;
 }
