#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 using namespace std;
 void solve(vector<int>& arr,int k) {
    unordered_map<int , int> m;
    for(int i = 0; i < arr.size() ; i++)
    {
        m[arr[i]]++;
    }
    for(int i = 0; i < arr.size() ; i++)
    {
        if(m[arr[i]]!=k)
        {
            cout<<arr[i];
            return ;
        }
    }

 }

 int main(int argc,char** argv){

     int n,k;
     cin>>n;
     cin>>k;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     solve(v,k);

 }
