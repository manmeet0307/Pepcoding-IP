#include<iostream>
 #include<vector>
 using namespace std;
 string shiftingLetters(string &s, vector<int> &shifts) {
     shifts[shifts.size() -1] = shifts[shifts.size() -1]  % 26;
    for(int i = shifts.size()-2 ; i>=0 ; i--)
    {
        shifts[i] = (shifts[i] + shifts[i+1]) % 26;
    }

    for(int i = 0 ; i< s.length();i++)
    {
        s[i] = ((s[i]-'a') + shifts[i])%26 + 'a';
    }
    return s;
 }

 int main(int argc, char** argv){
     string s;
     cin>>s;
     int N;
     cin>>N;

     vector<int> shifts(N);

     for (int i = 0; i < N; i++) {
         cin>>shifts[i];
     }

     cout<<shiftingLetters(s, shifts);
 }
