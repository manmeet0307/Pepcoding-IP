#include<bits/stdc++.h>
using namespace std;
int jungle(int * ans , int n)
{
    unordered_map<int,int> m ;
    for(int i =0;i < n;i++)
    {
        m[ans[i]]++;
    }

 unordered_map<int, int> :: iterator it;
 int res = 0;
 for(it = m.begin() ; it!= m.end() ; it++)
 {
//     if(it->first == 0)
//        continue;
     int grpsize = it->first + 1;
     int freq = it->second ;
     int no_of_grp = ceil(1.0*freq / grpsize);
     if(no_of_grp==0)
        no_of_grp = 1;

//     cout<< it->first<<" "<<it->second<<" " << grpsize<<" "<<no_of_grp<<endl;
     res += (grpsize * no_of_grp);
 }
 return res;
}
int main()
{
    int n;
    cin>>n;
    int ans[n];
    for(int i =0;i<n;i++)
    {
        cin>>ans[i];
    }
    cout<<jungle(ans,n);
}
