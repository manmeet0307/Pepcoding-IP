#include<bits/stdc++.h>
#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 // timestamp = 10s
 class Logger {
     public:
     unordered_map<string,int> m;
     Logger() {

     }

     bool shouldPrintMessage(int timestamp, string message) {

        if(!m.count(message))
        {
            m[message] = timestamp;
            return true;
        }
        else
        {
                if( (timestamp - m[message]) >= 10 )
                {
                    m[message] = timestamp;
                    return true;
                }
                else
                {
                    return false;
                }
        }
     }
 };


 int main(int argc,char** argv) {
     Logger lg;
     int n;
     cin>>n;
     vector<int> v(n);
     for (int i = 0; i < n; i++){
         cin>>v[i];
     }
     vector<string> S(n);
     for (int i = 0; i < n; i++){
         cin>>S[i];
     }
     for (int i = 0; i < n; i++){
         cout<<lg.shouldPrintMessage(v[i], S[i]) <<" ";
     }
 }
