#include<iostream>
 #include<string>
 #include<vector>
 using namespace std;
 int islandPerimeter(vector<vector<int> >& v)
 {
     int ans = 0;
     int m = v.size() , n = v[0].size();
     for(int i = 0 ; i < v.size() ; i++)
     {
         for(int j = 0 ; j < v[0].size() ; j++)
         {
             if(v[i][j] == 1 )
             {
                 ans += 4;

             if((i+1 < m) && v[i+1][j])
             {
                 ans-=2;
             }
             if((j+1<n) && v[i][j+1])
             {
                 ans-=2;
             }
             }
         }
     }
     return ans;
 }
 int main(int argc, char** argv){
     int row,col;
     cin>>row>>col;
     vector<vector<int> > v (row, vector<int>(col));
     for(int i=0;i<row;i++){
         for(int j=0;j<col;j++)
             cin>>v[i][j];
     }

     cout<<islandPerimeter(v);
 }
