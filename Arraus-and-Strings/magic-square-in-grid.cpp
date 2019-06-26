#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
  bool checkmagicsq(vector<vector<int> > &grid , int i , int j)
  {
      int rs = 0 , cs = 0 ,ds1 = 0,ds2 = 0 , c=0;
      int x = i , y = j;

      for(int i = x ; i <x+ 3;i++)
      {
          rs = 0;
          for(int j = y ; j < y+3;j++)
          {
              rs += grid[i][j];
          }
          if(i==x)
          {
              c = rs;
          }
          else if(c != rs)
            return false;
      }
      for(int j =y ; j < y+3; j++)
      {
            cs = 0;
          for(int i = x ; i < x+3;i++)
          {
              cs += grid[i][j];
          }
          if(cs!=c)
          {
              return false;
          }
      }
     for(int i =x ; i < x+3; i++)
     {
         for(int j = y; j<y+3; j++)
         {
             if((i-x)==(j-y))
             {
                 ds1 += grid[i][j] ;
             }
             if((i+j-x-y) == 3-1)
             {
                 ds2+= grid[i][j];
             }
         }

     }
    if((ds1!=c) || (ds2!=c))
    {
            return false;
    }
     return true;
  }
int numMagicSquaresInside(vector<vector<int> > &grid) {
      int m = grid.size() , n = grid[0].size() , c=0;
      for(int i =0;i<= m-3;i++)
      {
          for(int j = 0;  j <= n-3 ; j++)
          {

              if(i+1<m && j+1< n && grid[i+1][j+1] == 5 && checkmagicsq(grid , i, j))
              {
                  c++;
              }
          }
      }
      return c;
}

  int main(int argc, char** argv){
      int r, c;
      cin>>r>>c;
      vector<vector<int> > Input(r, vector<int> (c));
      for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
              cin>>Input[i][j];
          }
      }
      cout<<numMagicSquaresInside(Input);
  }
