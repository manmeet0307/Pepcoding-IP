#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input a string representing a time.
 // It should return the next closest time.
 bool isvalid(string m)
 {
     string h = m.substr(0,2);
     string minut = m.substr(3,2);
     if(stoi(h) <= 24 && stoi(minut)<60)
     {
         return true;
     }
     return false;
 }
 string nextClosestTime(string& t) {
     vector<int> v;
     unordered_map<int,int> m;
     for(int i = 0 ;  i< t.length() ;i++)
     {
         if(t[i]==':')
         {
             continue;
         }
         v.push_back(t[i]-48);
     }
     sort(v.begin(),v.end());
     for(int i = 0; i< v.size() ;i++)
     {
         m[v[i]] = i;
     }
     string nt(t);
     int index;
     for(int i = t.length()-1 ; i>=0 ; i--)
     {
         if(t[i]==':')
            continue;
         int num = t[i] - 48;
         int ni = m[num];

         int c=0;
         int x ;
         for(int j = ((ni+1)%v.size()) ; c < v.size() ; ( j = (j+1)%v.size()),c++)
         {
            string t2(nt);
             t2[i] = v[j] + '0';
             if(isvalid(t2))
             {
                 nt = t2;
                if(j==ni+1)
                {
                    return nt;
                }
                break;
             }
         }
        // nt[i] = to_string((ni+1)%v.size);
     }

 }

 int main(int argc,char** argv){
     string time;
     cin>>time;
     cout<<nextClosestTime(time)<<endl;

 }
