#include<iostream>
 #include<vector>
 using namespace std;

 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input two Sparse  2d Arrays, A and B
 // Return their product
 vector<vector<int> > multiply(vector<vector<int> > A, vector<vector<int> > B) {
     vector<vector<int>> res (A.size());
     for(int i = 0 ; i < A.size() ; i++)
     {
         res[i] = vector<int> (B[0].size());
     }
     int n = A.size() , m = B[0].size();
     for(int i = 0 ; i < n; i++ )
     {
         for(int j = 0 ; j < m ; j++)
         {
            int x = 0;
             for(int k = 0 ; k < A[0].size() ; k++)
             {
                 x += (A[i][k] * B[k][j]);
             }
         res[i][j] = x;
         }

     }
     return res;
 }
 // -----------------------------------------------------

 int main(int argc, char** argv){
     int arow, acol;
     cin>>arow>>acol;
     vector<vector<int> > a(arow, vector<int> (acol));
     for(int i=0;i<arow;i++){
         for(int j=0;j<acol;j++){
             cin>>a[i][j];
         }
     }
     int brow, bcol;
     cin>>brow>>bcol;
     vector<vector<int> > b(brow, vector<int> (bcol));
     for(int i=0;i<brow;i++){
         for(int j=0;j<bcol;j++){
             cin>>b[i][j];
         }
     }
     vector<vector<int> > res(arow, vector<int> (bcol));
     res=multiply(a,b);
     for(int i=0;i<res.size();i++){
         for(int j=0;j<res[i].size();j++){
             cout<<res[i][j]<<" ";
         }
         cout<<endl;
     }
 }
