#include<iostream>
 #include<vector>
 using namespace std;

 bool isToeplitzMatrix(vector<vector<int> >& matrix) {
    int i , j;
    int m = matrix.size() , n = matrix[0].size();
    int g = -(matrix.size()-1);
    /*cout<<g<<endl;
    cout<<matrix[0].size()<<endl;
*/
    signed int x = matrix[0].size();
    cout<<(g<x);
    for(int gap = -(matrix.size()-1) ; gap < x ; gap++)
    {

        if(gap>=0)
        {
            i = 0;
            j = i + gap;

        }
        else
        {
            j = 0;
            i = j - gap;
        }
        cout<<i<< " "<<j<<" " <<gap<<" "<< matrix[i][j]<<endl;
        while(i < m && j < n)
        {
            cout<<i<<" " <<j;
            if(i+1<m && j+1<n && matrix[i][j] != matrix[i+1][j+1])
            {

                return false;
            }
            i++;j++;
        }
    }
    return true;
 }

 int main(int argc,char** argv) {
     int r ,c;
     cin>>r>>c;
     vector<vector<int>> mat (r,vector<int>(c));
     for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
             cin>>mat[i][j];
         }
     }
     bool res=isToeplitzMatrix(mat);
     if(res==true){
         cout<<"true"<<endl;
     }else{
         cout<<"false"<<endl;
     }
 }
