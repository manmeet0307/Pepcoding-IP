#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

 class  operation{
     public:
     char op;
     int key;

     operation(char op,int key){
         this->key=key;
         this->op=op;
     }

 };

 //Don't make any changes here

 void display(vector<operation>& list) {

     for (int i = 0; i < list.size(); i++) {
         cout<<list[i].op<<" "<<list[i].key<<endl;
     }
     cout<<endl;
 }

 //this is a functional problem

 void print(vector<operation> & v){
    unordered_map<int , int> m;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i].op == 'A')
        {
            m[v[i].key]++;
        }
        else if(v[i].op == 'R')
        {
            m[v[i].key]--;
            if(m[v[i].key] == 0)
            {
                m.erase(v[i].key);
            }
        }
        cout<< m.size()<<endl;
    }

 }


 int main(int argc,char** argv){
     // Input for length of array.
     int N ;
     cin>>N;
     vector<operation> v;

     // Input for array elements.
     for (int i = 0; i < N; i++) {
         char a;
         int k;
         cin>>a>>k;
         operation ob(a,k);
         v.push_back(ob);
     }

     print(v);
 }
