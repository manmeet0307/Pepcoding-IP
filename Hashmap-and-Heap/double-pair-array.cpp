#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool canReorder(int A[], int n) {
      unordered_map<int , int> m;
       for(int i =0;i<n;i++)
       {
           m[A[i]]++;
       }
       vector<int> v;
       unordered_map<int,int> :: iterator it;
       for(it = m.begin() ; it!= m.end() ; it++)
       {
            v.push_back(it->first);
       }
       sort(v.begin() , v.end());

       for(int i =0;i<v.size() ;i++)
       {
           if(v[i] < 0 && m.count(v[i]) !=0)
           {
               if(v[i] % 2 !=0)
                return false;
               int num = v[i] / 2;
               if(m.count(num) ==0)
                return false;
               m[num]--;
               m[v[i]]--;
               if(m[num] ==0)
               {
                   m.erase(num);
               }
               if(m[v[i]] == 0)
               {
                   m.erase(v[i]);
               }
           }
           else if(v[i]>0 && m.count(v[i])!=0)
           {
                int num = v[i] * 2;
               if(m.count(num) ==0)
                return false;
               m[num]--;
               m[v[i]]--;
               if(m[num] ==0)
               {
                   m.erase(num);
               }
               if(m[v[i]] == 0)
               {
                   m.erase(v[i]);
               }
           }
           else if( v[i] == 0)
           {
            if(m[v[i]] % 2 != 0)
            {
                return false;
            }
           }
       }

       return m.size() ==0 ? true : false;
}
int main(int argc, char** argv) {

       int size;
       cin>>size;
       int a[size];
       for(int i=0;i<size;i++){
           cin>>a[i];
       }
       if(canReorder(a, size) == 0){
           cout<<"false"<<endl;
       }else{
           cout<<"true"<<endl;
       }
   }
