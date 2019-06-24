#include<iostream>
 #include<string>
 #include<vector>
 using namespace std;
 int solve(vector<vector<int> > & mat1,vector<vector<int> >& mat2,int k) {
     int rl = 0 ,cl = 0;
     int rr = mat2.size()-1 , cc = mat2[0].size()-1 ;
     int n = mat1.size();
     int counter = 0 ;
     while(1)
     {
         if(mat1[rl][cl] + mat2[rr][cc] > k)
         {
             cc--;
             if(cc<0)
             {
                 rr-- , cc = n-1;
             }
             //cout<<"more  "<<mat1[rl][cl]<<" " <<mat2[rr][cc]<<endl;
         }
         else if(mat1[rl][cl] + mat2[rr][cc] < k)
         {

             cl++;
             if(cl>=n)
             {
                 rl++;
                 cl = 0;
             }
           //  cout<<rl<<" " <<cl<<endl;
          //    cout<<"less  "<<mat1[rl][cl]<<" " <<mat2[rr][cc]<<endl;
         }
         else
         {
            counter++;
        //     cout<<mat1[rl][cl]<<" " <<mat2[rr][cc]<<endl;
             cc--;
             if(cc<0)
             {
                 rr-- , cc = n-1;
             }
             cl++;
             if(cl>n)
             {
                 rl++;
                 cl = 0;
             }
         }

         if(rl >=n || rr <0 || cc<0 || cl>=n)
         {
             break;
         }

    }
     return counter;
 }


 int main(int argc,char** argv){

     int n;
     cin>>n;
     vector< vector<int> > mat1(n,vector<int> (n));
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>mat1[i][j];
         }
     }
     vector< vector<int> > mat2(n,vector<int> (n));
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>mat2[i][j];
         }
     }
     int k;
     cin>>k;
     cout<<solve(mat1,mat2,k)<<endl;
 }
