#include<iostream>
 #include<vector>
 using namespace std;
 vector<string> removeComments(vector<string>& source) {
    vector<string> ans;
    bool dontpick = 0;
    string currans;
    for(int j = 0 ; j < source.size() ;j++)
    {
        string cur = source[j];
        string s = cur;
        for(int i = 0; i < s.length();i++)
        {
           // bool lineoff = 0;
            if(i+1 < cur.length() && s[i]=='/' && s[i+1] == '/')
            {
                break;
            }
           else if(i+1 < cur.length() && s[i]=='/' && s[i+1] == '*')
            {
                dontpick = 1;
            }
            else if(i+1 < cur.length() && s[i]=='*' && s[i+1] == '/')
            {
                dontpick = 0;
                i++;
            }
            else if(dontpick == 0 )

            {
                currans += s[i] ;
            }
//            cout<<currans<<endl;
        }
        if(dontpick==0 && currans.length()>0)
        {
            ans.push_back(currans);
            currans="";
        }

    }
    return ans;
 }

 void display(vector<string> & res){
     cout<<"[";
     for(int i=0;i<res.size();i++){
         cout<<res[i];
         if(i!=res.size()-1){
             cout<<", ";
         }
     }
     cout<<"]";
 }

 int main(int argc, char** argv){
     int n ;
     cin>>n;
     vector<string> source (n);
     cin.ignore();
     for (int i = 0; i < n; i++) {
         getline(cin,source[i]);
     }

     vector<string> res=removeComments(source);
     display(res);

 }
