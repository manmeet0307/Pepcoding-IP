#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 bool isValidSudoku(vector<vector<char> > board) {
     int r[9] , c[9] , sm[3][3];
     memset(r,0,sizeof(r));
     memset(c,0,sizeof(c));
     memset(sm,0,sizeof(sm));
     for(int i = 0 ; i < board.size() ; i++)
     {
         for(int j = 0; j < board[0].size() ; j++)
         {
             if(board[i][j]=='.')continue;
             int val =  (board[i][j] - '0');
             if((r[i]&(1<<val)) != 0 )
             {
//                 cout<<i<< " " << j << " "<<val<<endl;
//                 cout<<"1"<<endl;
                 return false;
             }
             else
             {
                r[i] = (r[i] | (1 << val));
             }
             if((c[j]&(1<<val)) != 0 )
             {
//                 cout<<i<< " " << j << " "<<val<<endl;
//                 cout<<"2"<<endl;
                 return false;
             }
             else
             {
                c[j] = ((c[j]|(1 << val)));
             }
             if((sm[i/3][j/3] & (1<<val)) != 0 )
             {
                // cout<<"3"<<endl;
                 return false;
             }
             else
             {
                sm[i/3][j/3] = ((sm[i/3][j/3] | (1 << val)));
             }
         }
     }
     return true;
 }

 int main(int argc, char** argv){
     vector<vector<char> > board(9, vector<char> (9));

     for (int i = 0; i < 9; i++) {
         for (int j = 0; j < 9; j++) {
             cin>>board[i][j];
         }
     }
     if (isValidSudoku(board)) {
         cout<<"Valid";
     } else {
         cout<<"Invalid";
     }

 }
