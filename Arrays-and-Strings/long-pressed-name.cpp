#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool isLongPressedName(string &name, string &typed) {
     int c=0 , sp = 0;
     while(c < name.length())
     {
         if(name[c] == typed[sp])
         {
             c++;
             sp++;
         }
         else if(sp>=0 && typed[sp] == typed[sp-1] )
         {
             sp++;
         }
         else{
            return false;
         }
     }
     while(  sp< typed.length())
     {
         if(typed[sp] != typed[sp-1])
         {
             return false;
         }
         sp++;
     }
     return true;
 }

 int main(int argc, char** argv){
     string name, typed;
     cin>>name>>typed;
 	 if(isLongPressedName(name, typed)){
         cout<<"true";
     }else{
         cout<<"false";
 }

 	 }
