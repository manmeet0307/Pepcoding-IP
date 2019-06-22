#include<iostream>
 #include<vector>
 using namespace std;

  void uncommon(string str1, string str2) {
    int n1 = 0;
    int n2 = 0;
    for(int i = 0 ; i < str1.size() ; i++)
    {
        char ch = str1[i];
        n1 = n1 | (1<<(ch-'a'));
    }
    for(int i = 0 ; i < str2.size() ; i++)
    {
        char ch = str2[i];
        n2 = n2 | (1<<(ch-'a'));
    }
    int n = n1^n2;
    for(int i = 0 ; i < 26 ;i++)
    {
        if((n&(1<<i))!=0)
        {
            cout<<(char)('a' + i );
        }
    }
 }

 //Don't make any changes here
 int main(int argc, char** argv){
     string str1, str2;
     cin>>str1>>str2;
     uncommon(str1, str2);
 }
