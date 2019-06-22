#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 int getHashValue(string line) {
     string initial = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     unordered_map<char , int> m;
     for(int i = 0 ; i < initial.length() ; i++)
     {
         m[initial[i]] = i;
     }
     int c = 0 , s = 0,r=0;
     for(int i = 0 ; i  < line.length() ; i++)
     {
         if(line[i]== ' ')
         {
             c++;
             r = 0;
             continue;
         }
        s += ((r)+ m[line[i]] );
        r++;
       // cout<<s<< " " << c<<endl;
     }
     return s * (c+1);
 }

 int main(int argc, char** argv){
     string line;
     getline(cin, line);
     cout<<getHashValue(line);

 }
