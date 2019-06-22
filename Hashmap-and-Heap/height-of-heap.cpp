#include<iostream>
 #include<string>
 #include<vector>
 using namespace std;
 int getceillog(int n)
 {
     int x = 0 ;
     while((1<<x) < n)
     {
         x++;
     }
     return x;
 }
 int solve(int N) {
 return getceillog(N+1)-1;

  }

 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }

     cout<<solve(n)<<endl;
 }
