#include<iostream>
 #include<string>
 #include<bits/stdc++.h>
using namespace std;
bool isvowel(char a)
{
    return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
}

 void findIfFake(string s){
     unordered_set<char> m;
     for(int i =0; i<s.length() ; i++)
     {
         if(isvowel(s[i]))
         {
             continue;
         }
         m.insert(s[i]);
     }
     if(m.size() % 2 ==0 )
     {

         cout<<"SHE!";
     }
     else
     {
        cout<<"HE!";
     }

 }
 int main(int argc, char**argv){
     string s;
     getline(cin,s);
     findIfFake(s);
 }
